/*
 * xtc - The eXTensible Compiler
 * Copyright (C) 2009-2012 New York University
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */
package xtc.lang.cpp;

import java.lang.StringBuilder;
import java.io.IOException;

import java.util.Collection;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.List;
import java.util.LinkedList;
import java.util.ArrayList;

import xtc.tree.Node;
import xtc.tree.GNode;

import xtc.util.Pair;
import xtc.util.Runtime;

import xtc.lang.cpp.Syntax.Kind;
import xtc.lang.cpp.Syntax.LanguageTag;
import xtc.lang.cpp.Syntax.ConditionalTag;
import xtc.lang.cpp.Syntax.DirectiveTag;
import xtc.lang.cpp.Syntax.Layout;
import xtc.lang.cpp.Syntax.Language;
import xtc.lang.cpp.Syntax.Text;
import xtc.lang.cpp.Syntax.Directive;
import xtc.lang.cpp.Syntax.Conditional;

import xtc.lang.cpp.PresenceConditionManager.PresenceCondition;

/**
 * This class expands macros and processes header files
 *
 * @author Paul Gazzillo
 * @version $Revision: 1.235 $
 */
public class ForkMergeParser {
  /** The name of the AST conditional node. */
  public static String CHOICE_NODE_NAME = "Conditional";

  /** Parsing actions. */
  private static enum ParsingAction { NONE, SHIFT, REDUCE, ACCEPT, ERROR }

  /** Array of error messages. */
  final private static String[] ERRMSG = {
    "no default action",
    "invalid table entry",
    "error directive"};

  /** Error code for no default action.  */
  final private static int NODEFAULT = 0;
  
  /** Error code for invalid table entry. */
  final private static int INVALID = 1;
  
  /** Error code for seen an error directive. */
  final private static int ERRDIRECTIVE = 2;
  
  /** The state number of the the starting state. */
  final private static int STARTSTATE = 0;

  /**
   * Whether the merge subparsers on all tokens or only the subparsers
   * on the earliest token.
   */
  final private static boolean MERGE_ALL = true;

  /**
   * Whether to optimize FMLR to finish up subparsers as soon as they
   * reach EOF.
   */
  final private static boolean FAST_FINISH_EOF = false;

  /** The stream from which the parser gets syntactic units */
  private Stream stream;
  
  /** The presenceCondition manager. */
  private PresenceConditionManager presenceConditionManager;

  /** The actions object for AST-building and parsing presenceCondition. */
  private Actions actions;

  /** The xtc runtime.  Used for output and flags. */
  private Runtime runtime;

  /** The accepted subparsers. */
  List<Subparser> accepted;

  /**
   * The sequence numbers of nested conditionals.  Used by lazy
   * forking to only fork the closest conditional when it has empty
   * branches.
   */
  private LinkedList<Integer> nestedConditionals;

  /** Whether shared reductions is on or not. */
  private final boolean optimizeSharedReductions;

  /** Whether lazy forking is on or not. */
  private final boolean optimizeLazyForking;

  /** Whether early reduction is on or not. */
  private final boolean optimizeEarlyReduce;

  /** Whether Platoff ordering is on or not. */
  private final boolean optimizePlatoffOrdering;

  /** Whether follow-set caching is on. */
  private final boolean optimizeFollowSetCaching;

  /** Whether deoptimize early shift is on or not. */
  private final boolean deoptimizeEarlyShift;

  /** The follow-set cache. */
  private Map<Integer, Collection<Lookahead>> followCache;

  /** The skipConditional cache. */
  private Map<Integer, OrderedSyntax> skipConditionalCache;

  /**
   * The comparator method for the priority queue of subparsers.  For
   * optimization, there are two subparser ordering comparators: (1)
   * the fully-optimized one and (2) a configurable one.  The
   * fully-optimized comparator saves times since it does not need to
   * check which optimizations are set.
   */
  private Comparator<Subparser> subparserComparator;

  /** Show all parsing actions. */
  private final boolean showActions;

  /** Show errors. */
  private final boolean showErrors;

  /** Show errors. */
  private final boolean showAccepts;

  /** Turn language statistics collection on. */
  private final boolean languageStatistics;

  /** Turn parser statistics collection on. */
  private final boolean parserStatistics;

  /** Turn the subparser kill-switch on. */
  private final boolean killswitch;

  /** The kill-switch cutoff for number of subparsers. */
  private final int killswitchCutoff;

  /** Count the number of parser loop iterations. */
  private int iterations;

  /** Count the number of lazy forks. */
  private int lazyForks;

  /** Count the number of lazy forks with empty branches. */
  private int lazyForksEmptyBranches;

  /** Count the number of conditionals with empty branches. */
  private HashMap<Integer, Boolean> emptyConditionals;

  /** Collect the distribution of subparsers throughout parsing. */
  private HashMap<Integer, Integer> nsubparsers;

  /** Count the number of times FOLLOW is called. */
  private int nfollow;

  /** Create a new parser. */
  public ForkMergeParser(Stream stream, PresenceConditionManager presenceConditionManager,
                         Actions actions, Runtime runtime) {
    this.stream = stream;
    this.presenceConditionManager = presenceConditionManager;
    this.actions = actions;
    this.runtime = runtime;

    this.accepted = new ArrayList<Subparser>();

    this.nestedConditionals = new LinkedList<Integer>();

    optimizeSharedReductions = runtime.test("optimizeSharedReductions");
    optimizeLazyForking = runtime.test("optimizeLazyForking");
    optimizeEarlyReduce = runtime.test("optimizeEarlyReduce");

    // It has no effect.  Off by default.
    optimizePlatoffOrdering = runtime.test("platoffOrdering");

    deoptimizeEarlyShift = runtime.test("earlyShift");

    // Always leave it on.  No effect on subparser size.  Minimal
    // effect on time.
    optimizeFollowSetCaching = ! runtime.test("noFollowCaching");

    if (optimizeFollowSetCaching) {
      followCache = new HashMap<Integer, Collection<Lookahead>>();
    }

    // Early reductions and Platoff ordering affect the subparser
    // ordering policy.  See the comparator definitions for details.
    if (optimizeEarlyReduce && ! optimizePlatoffOrdering
        && ! deoptimizeEarlyShift) {
      subparserComparator = subparserComparatorOptimized;
    } else {
      subparserComparator = subparserComparatorConfigurable;
    }

    skipConditionalCache = new HashMap<Integer, OrderedSyntax>();

    languageStatistics = runtime.test("statisticsLanguage");
    parserStatistics = runtime.test("statisticsParser");

    showActions = runtime.test("showActions");
    showErrors = runtime.test("showErrors");
    showAccepts = runtime.test("showAccepts");

    if (! runtime.hasValue("killswitch")
        || null == runtime.getString("killswitch")) {
      killswitch = false;
      killswitchCutoff = 0;

    } else {
      try {
        killswitch = true;
        killswitchCutoff = Integer.parseInt(runtime.getString("killswitch"));

        if (killswitchCutoff <= 0) {
          throw new NumberFormatException("the -killswitch flag takes a "
                                          + "positive, non-zero integer");
        }
      } catch (NumberFormatException e) {
        throw new NumberFormatException("the -killswitch flag takes a "
                                        + "positive, non-zero integer");
      }
    }
  }

  /**
   * This comparator enforces the subparser set ordering policy and
   * can be configured to add or remove optimizations.
   */
  private Comparator<Subparser> subparserComparatorConfigurable
    = new Comparator<Subparser>() {
    public int compare(Subparser o1, Subparser o2) {
      int result = o1.lookahead.token.order - o2.lookahead.token.order;

      if (0 == result) {
        if (optimizeEarlyReduce) {
          // The early reduce optimization puts reductions first to
          // maximize merge opportunities.

          if (ParsingAction.SHIFT == o1.lookahead.getAction()) {
            return 1;

          } else if (ParsingAction.SHIFT == o2.lookahead.getAction()) {
            return -1;

          } else if (optimizePlatoffOrdering) {
            // Both subparsers must be REDUCEs since accept and error
            // parsers arer removed instead of rescheduled.

            // Platoff ordering says longer stacks go first to
            // maximimize merge opportunities.

            return o1.stack.getHeight() >= o2.stack.getHeight() ? -1 : 1;
          }

        } else if (optimizePlatoffOrdering) {
          if (ParsingAction.REDUCE == o1.lookahead.getAction()
              && ParsingAction.REDUCE == o2.lookahead.getAction()) {

            return o1.stack.getHeight() >= o2.stack.getHeight() ? -1 : 1;
          }
        } else if (deoptimizeEarlyShift) {
          // The early shift deoptimization puts shifts first to
          // minimize merge opportunities.

          if (ParsingAction.SHIFT == o1.lookahead.getAction()) {
            return -1;
          } else if (ParsingAction.SHIFT == o2.lookahead.getAction()) {
            return 1;
          }
        }
      }

      return result;
    }

    public boolean equals(Object o) {
      return this == o;
    }
  };

  /**
   * The fully-optimized subparser set ordering policy comparator
   * method.  Optimizations cannot be turned on or off.
   */
  private Comparator<Subparser> subparserComparatorOptimized
    = new Comparator<Subparser>() {
    public int compare(Subparser o1, Subparser o2) {
      int result = o1.lookahead.token.order - o2.lookahead.token.order;

      if (0 == result) {
        // The early reduce optimization puts reductions first to
        // maximize merge opportunities.

        if (ParsingAction.SHIFT == o1.lookahead.action) {
          return 1;

        } else if (ParsingAction.SHIFT == o2.lookahead.action) {
          return -1;
        }
      }

      return result;
    }

    public boolean equals(Object o) {
      return this == o;
    }
  };

  /**
   * Parse the syntax stream.
   *
   * @return The AST.
   */
  public Object parse() throws IOException {

    // Initialize the first subparser.

    OrderedSyntax startOfFile = new OrderedSyntax(stream);

    Subparser firstSubparser =
      new Subparser(new Lookahead(startOfFile,
                                  presenceConditionManager.new PresenceCondition(true)), 
                    new StackFrame(STARTSTATE, 0, null, null),
                    presenceConditionManager.new PresenceCondition(true),
                    actions.getInitialContext());

    firstSubparser.lookahead.token = firstSubparser.lookahead.token.getNext();


    // Initialize the set of subparsers.  Use the default initial
    // capacity.
    PriorityQueue<Subparser> subparsers
      = new PriorityQueue<Subparser>(11, subparserComparator);

    subparsers.add(firstSubparser);

    if (parserStatistics) {

      // Initialize statistics collection.

      iterations = 0;
      nsubparsers = new HashMap<Integer, Integer>();
      nfollow = 0;
      lazyForks = 0;
      lazyForksEmptyBranches = 0;
      emptyConditionals = new HashMap<Integer, Boolean>();
    }


    // Prepare a list of processed subparsers to add to the set of
    // subparsers after the parsing iteration is done
    LinkedList<Subparser> processedParsers = new LinkedList<Subparser>();

    // Instantiate the followSet list.
    Collection<Lookahead> followSet = new LinkedList<Lookahead>();

    // The main parsing loop.
    while (true) {
      // Get the earliest token.  The list of subparsers is ordered,
      // so we can get the earliest token from the first subparser in
      // the list.  Each subparser should be on an ordinary token or a
      // start conditional.

      OrderedSyntax earliestToken = subparsers.peek().lookahead.token;

      // System.err.println("earliest: " + earliestToken);

      assert earliestToken.syntax.kind() == Kind.CONDITIONAL
        && earliestToken.syntax.toConditional().tag()
        == ConditionalTag.START
        || earliestToken.syntax.kind() == Kind.LANGUAGE
        || earliestToken.syntax.kind() == Kind.EOF;


      // This flag tells us that one or more parsers in this iteration
      // performed a reduction.  It is used to implement the
      // earlyReduce optimization, since we can't do any shifts until
      // all the reduces are done.

      boolean seenReduce = false;


      // This flag tells us that there is a conditional that needed
      // its follow-set computed.  This is used to make lazy forks
      // wait until all subparsers on that conditional are ready to
      // fork.  Otherwise, the forked subparsers will get ahead of
      // other subparsers and miss merge opportunities.  Note that
      // without Oearly, this flag won't really do much, since Oearly
      // ensures that subparsers that want to shift come after other
      // subparsers.

      boolean waitToFork = false;


      // For all subparsers on the earliest token.  Pull each
      // subparser off of the priority queue, process it, and add it
      // to the processedParsers list.  This list is then added back
      // to the priority queue after processing.

      while (subparsers.size() > 0
             && (subparsers.peek().lookahead.token.order - earliestToken.order) == 0) {

        // When the earlyReduce optimization is on, give reductions
        // their own parser iteration and then merge.  Don't do any
        // shifting until after a merge attempt.

        if (optimizeEarlyReduce && seenReduce
            && subparsers.peek().lookahead.getAction() == ParsingAction.SHIFT) {
          break;
        }


        // Pull off the earliest subparser.

        Subparser subparser = subparsers.poll();

        // System.err.println("\n" + subparser + ":" + subparser.lookahead.token.syntax);


        // Carry out one parsing iteration for one subparser.

        if (subparser.lookahead.isSet()) {

          switch (subparser.lookahead.getAction()) {
          case REDUCE:

            // Perform a shared reduction.

            reduce(subparser);
            seenReduce = true;
            waitToFork = true;

            // Repartition the follow-set if necessary.  It is
            // necessary if the any parsing actions are non-reduce or
            // reducing a different production.

            boolean repartition = false;
            int lastProduction = -1;

            for (Lookahead n : ((LookaheadSet) subparser.lookahead).set) {
              getAction(n, subparser.stack);

              if (ParsingAction.REDUCE != n.getAction()
                  || -1 != lastProduction
                  && n.getActionData() != lastProduction) {
                repartition = true;
                break;
              }

              lastProduction = n.getActionData();
            }

            if (repartition) {

              // Repartition the follow-set and fork subparsers.

              LookaheadSet lookaheadSet = (LookaheadSet) subparser.lookahead;

              Collection<Lookahead> tokenSet
                = partition(lookaheadSet.set, subparser);

              processedParsers.addAll(fork(subparser, tokenSet));


              // Clean up subparser scope and presenceCondition.  It is already
              // removed from the set of subparsers.
              
              subparser.lookahead.presenceCondition.delRef();
              // No need to free LookaheadSet.  They are forked into
              // new subparsers.
              subparser.presenceCondition.delRef();
              subparser.scope.free();

            } else {
              // All parsing actions still reduce the same production.
              // Leave the subparser alone, but update the token set's
              // parsing action.

              subparser.lookahead.copyAction(((LookaheadSet) subparser.lookahead).set.get(0));

              processedParsers.add(subparser);
            }

            break;

          case SHIFT:

            if (waitToFork) {

              // Don't fork until all subparsers on this conditional
              // are ready to fork.

              // Reschedule this subparser.

              processedParsers.add(subparser);

            } else {

              // Fork the current conditional's next tokens only.  Put
              // all the rest in a single subparser.

              Collection<Lookahead> set;

              if (subparser.lookahead.token.syntax.kind() == Kind.CONDITIONAL) {
                set = lazyFork((LookaheadSet) subparser.lookahead);

              } else {

                // No need for lazy forking.  This is not a
                // conditional but an implicit conditional caused by a
                // parsing presenceCondition ambiguity, e.g. C's typedef/var
                // name ambiguity.  Just fork a subparser for each
                // token.

                set = ((LookaheadSet) subparser.lookahead).set;
              }

              processedParsers.addAll(fork(subparser, set));


              // Clean up subparser scope and presenceCondition.  It is already
              // removed from the set of subparsers.
              
              subparser.lookahead.presenceCondition.delRef();
              // No need to free LookaheadSet.  They are forked into
              // new subparsers.
              subparser.presenceCondition.delRef();
              subparser.scope.free();
            }

            break;

          default:

            // Sets of next tokens only apply to shared reductions and
            // lazy forking.

            throw new RuntimeException();
          }

        } else {

          // Get the follow set, i.e. all the possible next ordinary
          // tokens.

          // If the token is an ordinary language token, no need to
          // calculate the follow set.  It is simply the set
          // containing the single language token.

          switch (subparser.lookahead.token.syntax.kind()) {
          case EOF:
            // Fall through
          case LANGUAGE:
            followSet.clear();
            followSet
              .add(new Lookahead(subparser.lookahead.token,subparser.presenceCondition.addRef()));

            break;

          case CONDITIONAL:

            if (optimizeFollowSetCaching) {
              Collection<Lookahead> cachedFollowSet;

              if (hasCachedSet(subparser.lookahead.token)) {

                // Use the cached follow-set.

                cachedFollowSet = getCachedSet(subparser.lookahead.token);

              } else {

                // This token's follow-set is not yet cached, so compute
                // it.

                PresenceCondition T = presenceConditionManager.new PresenceCondition(true);

                cachedFollowSet = follow(subparser.lookahead.token, T).values();

                T.delRef();

                // Cache the follow-set.

                setCachedSet(subparser.lookahead.token, cachedFollowSet);

                //Remove elements from LRU cache to make room.  Don't
                //forget to clean up BDDs!
              }

              // Conjoin the subparser's presence condition with the
              // follow-set tokens' presence conditions, omitting tokens
              // with a FALSE presence condition, i.e. trimming
              // infeasible paths.

              followSet.clear();

              for (Lookahead n : cachedFollowSet) {
                PresenceCondition and = subparser.presenceCondition.and(n.presenceCondition);

                if (and.isFalse()) {
                  // Omit infeasible paths.

                  and.delRef();
                } else {
                  followSet.add(new Lookahead(n.token, and));
                }
              }

            } else {
              // Compute the follow set every time.
              followSet = follow(subparser.lookahead.token, subparser.presenceCondition).values();
            }

            break;

          default:
            // The parser cannot use tokens other than language,
            // conditional, and eof tokens.
            throw new UnsupportedOperationException();
          }

          // Apply the parsing presenceCondition to tokens in the follow set
          // only if there is a parsing presenceCondition implementation and the
          // parsing presenceCondition indicates the parser shouldReclassify.
          // If so, this will reclassify tokens' lexeme types and
          // handle implicit conditionals, e.g. due to C typedef
          // ambiguities.

          if (actions.hasContext()
              && subparser.scope.shouldReclassify(followSet)) {

            Collection<Lookahead> newTokens
              = subparser.scope.reclassify(followSet);

            // Only create a new list when their are new tokens.

            if (null != newTokens) {
              Collection<Lookahead> newSet = new LinkedList<Lookahead>();

              newSet.addAll(followSet);
              newSet.addAll(newTokens);

              followSet = newSet;
            }
          }


          if (followSet.size() == 1) {

            // Replace subparser's token with the token that has had
            // parsing presenceCondition applied to it.

            subparser.lookahead.presenceCondition.delRef();
            subparser.lookahead = followSet.iterator().next();


            // Regular LR.

            getAction(subparser.lookahead, subparser.stack);

            switch (subparser.lookahead.getAction()) {
            case SHIFT:
              shift(subparser);

              // Move to the next ordinary token or start conditional
              // (#if).  If the next token ends a branch (#elif or
              // #endif), move to the next ordinary token or start
              // conditional after the conditional.

              subparser.lookahead.token = subparser.lookahead.token.getNext();

              while (subparser.lookahead.token.syntax.kind() == Kind.CONDITIONAL
                     && subparser.lookahead.token.syntax.toConditional().tag
                     != ConditionalTag.START) {
                Conditional conditional
                  = subparser.lookahead.token.syntax.toConditional();

                switch (conditional.tag()) {
                case START:
                  // No need to move.
                  break;

                case NEXT:
                  subparser.lookahead.token
                    = skipConditional(subparser.lookahead.token);
                  break;

                case END:
                  subparser.lookahead.token
                    = subparser.lookahead.token.getNext();
                  break;

                default:
                  // No such conditional tag.
                  throw new UnsupportedOperationException();
                }
              }


              if (subparser.lookahead.token.syntax.kind() == Kind.LANGUAGE
                  || subparser.lookahead.token.syntax.kind() == Kind.EOF) {
                getAction(subparser.lookahead, subparser.stack);
              } else {
                subparser.lookahead.clearAction();
              }

              // We no longer know what the next parsing action is.
              // The next token could be either an ordinary token or a
              // conditional.  The action can be used for subparser
              // ordering, so not clearing it can lead to incorrect
              // results.
              
              // subparser.lookahead.clearAction();

              if (FAST_FINISH_EOF
                  && Kind.EOF == subparser.lookahead.token.syntax.kind()) {
                fastFinish(subparser);
              } else {
                // Re-add the subparser to the ordered set to update its
                // position in the set.

                processedParsers.add(subparser);
              }

              break;

            case REDUCE:

              reduce(subparser);
              seenReduce = true;

              getAction(subparser.lookahead, subparser.stack);

              // We no longer know what the next parsing action is.
              // The next token could be either an ordinary token or a
              // conditional.  The action can be used for subparser
              // ordering, so not clearing it can lead to incorrect
              // results.
              
              // subparser.lookahead.clearAction();


              // Re-add the subparser to the ordered set to update its
              // position in the set.

              processedParsers.add(subparser);

              break;

            case ACCEPT:

              accepted.add(subparser);

              if (showAccepts) {
                runtime.errConsole().pln("ACCEPT").flush();
              }

              break;

            case ERROR:

              // Clean up subparser scope and presenceCondition.  We will not add
              // it back to the main set of subparsers.

              subparser.lookahead.presenceCondition.delRef();
              subparser.presenceCondition.delRef();
              subparser.scope.free();

              if (showErrors) {
                runtime.error("parse error on "
                              + (subparser.lookahead.token.syntax.kind() == Kind.EOF ?
                                 "EOF" : "\"" + subparser.lookahead.token.syntax + "\"")
                              + " at " + subparser.lookahead.token.syntax.getLocation());
              }

              break;
            }

          } else if (followSet.size() > 1) {

            // A follow set with more than one token implies an
            // explicit or implicit conditional.

            // Fork subparsers on the conditional.

            assert subparser.lookahead.token.syntax.kind() == Kind.LANGUAGE
              || subparser.lookahead.token.syntax.toConditional().tag()
              == ConditionalTag.START;


            // Partition the follow-set.  Naive FMLR will not group
            // any lookaheads, but the shared reductions and lazy
            // forking optimizations will.

            Collection<Lookahead> tokenSet = partition(followSet, subparser);


            // Fork and replace the subparser with newly-forked
            // subparsers, one for each token in the follow set.

            processedParsers.addAll(fork(subparser, tokenSet));


            // Clean up subparser scope and presenceCondition.  It is removed
            // from the set of subparsers.

            subparser.lookahead.presenceCondition.delRef();
            subparser.presenceCondition.delRef();
            subparser.scope.free();


            // Hold off on lazy forking until all subparsers are ready
            // to fork.

            waitToFork = true;

          } else {
            // The follow set should never be less than one.

            throw new RuntimeException();
          }
        }
      }


      // Add the updated subparsers into the priority queue of
      // subparsers.

      for (Subparser subparser : processedParsers) {
        subparsers.add(subparser);
      }
      processedParsers.clear();


      if (subparsers.size() == 0) {
        // Done
        break;
      }


      // Merge subparsers.  We only need check the earliest subparsers for
      // a merge.

      if (subparsers.size() > 1) {
        stagedMerge(subparsers);
      }

      if (parserStatistics && ! waitToFork) {

        // Collect statistics on the number of subparsers.
        iterations++;
        if (! nsubparsers.containsKey(subparsers.size())) {
          nsubparsers.put(subparsers.size(), 0);
        }
        nsubparsers.put(subparsers.size(),
                        nsubparsers.get(subparsers.size()) + 1);
      }
    }


    if (parserStatistics) {
      int max = 0;
      runtime.errConsole().pln(String.format("iterations %d", iterations));
      for (Integer size : nsubparsers.keySet()) {
        if (size > max) max = size;

        runtime.errConsole().pln(String.format("subparsers %d %d",
                                               size, nsubparsers.get(size)));
      }
      runtime.errConsole().pln(String.format("max_subparsers %d", max)); 
      runtime.errConsole().pln(String.format("follow %d", nfollow)); 
      runtime.errConsole().pln(String.format("lazy_forks %d %d",
                                             lazyForks,
                                             lazyForksEmptyBranches));

      int empty = 0;

      for (Integer i : emptyConditionals.keySet()) {
        if (emptyConditionals.get(i)) {
          empty++;
        }
      }

      runtime.errConsole().pln(String.format("empty_conditionals %d %d",
                                             emptyConditionals.size(),
                                             empty)); 
      
      runtime.errConsole().flush();
    }

    if (actions.hasContext()) {
      actions.getInitialContext().free();
    }

    if (accepted.size() == 0) {
      // No accepted subparsers.
      return null;
    } else {
      // Merge the accepted subparsers.
      accepted = merge(accepted);

      if (accepted.size() == 1) {
        return (Node) accepted.get(0).stack.value;
      } else {
        // Combine the semantic values of the accepted subparsers.
        Node root = GNode.create(CHOICE_NODE_NAME);

        for (Subparser subparser : accepted) {
          root.add(subparser.presenceCondition.addRef());
          root.add(subparser.stack.value);

          // Clean up subparser scope and presenceCondition.
          subparser.lookahead.presenceCondition.delRef();
          subparser.presenceCondition.delRef();
          subparser.scope.free();
        }

        return root;
      }
    }
  }

  /**
   * Parse the syntax stream.
   *
   * @return The AST.
   */
  public Object parseNaively() throws IOException {

    // Initialize the first subparser.

    OrderedSyntax startOfFile = new OrderedSyntax(stream);

    Subparser firstSubparser =
      new Subparser(new Lookahead(startOfFile,
                                  presenceConditionManager.new PresenceCondition(true)), 
                    new StackFrame(STARTSTATE, 0, null, null),
                    presenceConditionManager.new PresenceCondition(true),
                    actions.getInitialContext());

    firstSubparser.lookahead.token = firstSubparser.lookahead.token.getNext();


    // Initialize the set of subparsers.  Use the default initial
    // capacity.
    
    PriorityQueue<Subparser> subparsers
      = new PriorityQueue<Subparser>(11, subparserComparator);

    subparsers.add(firstSubparser);


    // Use a choice node in case there are multiple accepting
    // subparsers.

    GNode root = GNode.create(CHOICE_NODE_NAME);

    if (parserStatistics) {

      // Initialize statistics collection.

      iterations = 0;
      nsubparsers = new HashMap<Integer, Integer>();
      nfollow = 0;
    }


    // The main parsing loop.

    while (true) {

      if (killswitch && subparsers.size() >= killswitchCutoff) {
        if (parserStatistics) {
          runtime.errConsole().pln(String.format("killswitch_subparsers %d",
                                                 subparsers.size())).flush();
        }
        throw
          new RuntimeException(String
                               .format("kill-switch tripped because "
                                       + "subparsers reached %d",
                                       subparsers.size()));
      }

      if (parserStatistics) {

        // Collect statistics on the number of subparsers.

        iterations++;
        if (! nsubparsers.containsKey(subparsers.size())) {
          nsubparsers.put(subparsers.size(), 0);
        }
        nsubparsers.put(subparsers.size(),
                        nsubparsers.get(subparsers.size()) + 1);

        // System.err.println("subparsers: " + subparsers.size());
        // LinkedList<Subparser> bob = new LinkedList<Subparser>();
        // while (! subparsers.isEmpty()) {
        //   Subparser p = subparsers.poll();

        //   System.err.println(p + ": " + p.a + ":" + p.presenceCondition);

        //   bob.add(p);
        // }

        // for (Subparser p : bob) {
        //   subparsers.add(p);
        // }
        // System.err.println();
      }


      // Get the earliest token.  The list of subparsers is ordered,
      // so we can get the earliest token from the first subparser in
      // the list.  Each subparser should be on an ordinary token or a
      // start conditional.

      OrderedSyntax earliestToken = subparsers.peek().lookahead.token;

      // System.err.println("earliest: " + earliestToken);

      assert earliestToken.syntax.kind() == Kind.CONDITIONAL
        && (earliestToken.syntax.toConditional().tag()
            == ConditionalTag.START
            || earliestToken.syntax.toConditional().tag()
            == ConditionalTag.NEXT
            || earliestToken.syntax.toConditional().tag()
            == ConditionalTag.END)
        || earliestToken.syntax.kind() == Kind.LANGUAGE
        || earliestToken.syntax.kind() == Kind.EOF;


      // Prepare a list of processed subparsers to add to the set of
      // subparsers after the parsing iteration is done

      LinkedList<Subparser> processedParsers = new LinkedList<Subparser>();


      // For all subparsers on the earliest token.  Pull each
      // subparser off of the priority queue and add it to the
      // processedParsers list.  This list is then added back to the
      // priority queue after processing.

      while (subparsers.size() > 0
             && (subparsers.peek().lookahead.token.order - earliestToken.order) == 0) {

        // Pull off the earliest subparser.

        Subparser subparser = subparsers.poll();

        // System.err.println("\n" + subparser + ":" + subparser.lookahead.token.syntax);


        // Carry out one parsing iteration for one subparser.


        // Apply the parsing presenceCondition to tokens in the follow set.
        // This will reclassify tokens and handle implicit
        // conditionals, e.g. due to C typedef ambiguities.

        if (actions.hasContext()
            && subparser.lookahead.token.syntax.kind() == Kind.LANGUAGE) {

          // Create new list, add token.  Need to fork immediately if
          // there are new tokens here.

          LinkedList<Lookahead> set = new LinkedList<Lookahead>();

          set.add(subparser.lookahead);

          Collection<Lookahead> newTokens
            = subparser.scope.reclassify(set);

          if (null != newTokens) {
            // There were new tokens during reclassification.  Fork
            // new subparsers immediately.

            processedParsers.addAll(fork(subparser, newTokens));
          }
        }


        if (subparser.lookahead.token.syntax.kind() == Kind.LANGUAGE
            || subparser.lookahead.token.syntax.kind() == Kind.EOF) {

          // Regular LR.

          getAction(subparser.lookahead, subparser.stack);

          switch (subparser.lookahead.getAction()) {
          case SHIFT:
            shift(subparser);

            // Move to the next ordinary token or start conditional
            // (#if).  If the next token ends a branch (#elif or
            // #endif), move to the next ordinary token or start
            // conditional after the conditional.

            subparser.lookahead.token = subparser.lookahead.token.getNext();

            while (subparser.lookahead.token.syntax.kind() == Kind.CONDITIONAL
                   && subparser.lookahead.token.syntax.toConditional().tag
                   != ConditionalTag.START) {
              Conditional conditional = subparser.lookahead.token.syntax.toConditional();

              switch (conditional.tag()) {
              case START:
                // No need to move.
                break;

              case NEXT:
                subparser.lookahead.token = skipConditional(subparser.lookahead.token);
                break;

              case END:
                subparser.lookahead.token = subparser.lookahead.token.getNext();
                break;

              default:
                // No such conditional tag.
                throw new UnsupportedOperationException();
              }
            }


            // We no longer know what the next parsing action is.
            // The next token could be either an ordinary token or a
            // conditional.  The action can be used for subparser
            // ordering, so not clearing it can lead to incorrect
            // results.
              
            subparser.lookahead.clearAction();


            // Re-add the subparser to the ordered set to update its
            // position in the set.

            processedParsers.add(subparser);

            break;

          case REDUCE:

            reduce(subparser);

            // We no longer know what the next parsing action is.
            // The next token could be either an ordinary token or a
            // conditional.  The action can be used for subparser
            // ordering, so not clearing it can lead to incorrect
            // results.
              
            subparser.lookahead.clearAction();


            // Re-add the subparser to the ordered set to update its
            // position in the set.

            processedParsers.add(subparser);

            break;

          case ACCEPT:

            root.add(subparser.presenceCondition.addRef());
            root.add(subparser.stack.value);


            // Clean up subparser scope and presenceCondition.  We will not add
            // it back to the main set of subparsers.

            subparser.lookahead.presenceCondition.delRef();
            subparser.presenceCondition.delRef();
            subparser.scope.free();

            if (showAccepts) {
              runtime.errConsole().pln("ACCEPT").flush();
            }

            break;

          case ERROR:

            // Clean up subparser scope and presenceCondition.  We will not add
            // it back to the main set of subparsers.

            subparser.lookahead.presenceCondition.delRef();
            subparser.presenceCondition.delRef();
            subparser.scope.free();

            if (showErrors) {
              runtime.error("parse error on "
                            + (subparser.lookahead.token.syntax.kind() == Kind.EOF ?
                               "EOF" : "\"" + subparser.lookahead.token.syntax + "\"")
                            + " at " + subparser.lookahead.token.syntax.getLocation());
            }

            break;
          }

        } else if (subparser.lookahead.token.syntax.kind() == Kind.CONDITIONAL) {

          switch (subparser.lookahead.token.syntax.toConditional().tag()) {
          case START:

            // Fork subparsers on the conditional.

            // Get the first token in each branch of the conditional.
            // Move to #endif if any branches are empty.

            Collection<Lookahead> tokenSet = new LinkedList<Lookahead>();

            OrderedSyntax a = subparser.lookahead.token;


            // Save the presence conditions of all empty branches.

            PresenceCondition emptyConditions = presenceConditionManager.new PresenceCondition(false);


            // The union of the branches conditions.  Used to determine
            // whether there is an implicit else branch or not.

            PresenceCondition union = a.syntax.toConditional().presenceCondition.addRef();


            // Loop through each branch of the conditional, find the
            // first token of each.

            while (! (a.syntax.kind() == Kind.CONDITIONAL
                      && a.syntax.toConditional().tag()
                      == ConditionalTag.END)) {

              // Get the presence condition of the branch.  It is
              // conjoined with the presence condition in which it is
              // nested.

              PresenceCondition nestedPresenceCondition
                = subparser.presenceCondition.and(a.syntax.toConditional().presenceCondition);


              // a is on the conditional starting the branch.  Get the
              // first the token after the one starting the branch.  It
              // will either be the first token in the branch, or the
              // token that ends the branch.

              a = a.getNext();

              if (a.syntax.kind() == Kind.CONDITIONAL
                  && (a.syntax.toConditional().tag()
                      == ConditionalTag.NEXT
                      || a.syntax.toConditional().tag()
                      == ConditionalTag.END)) {

                // The branch is empty.

                PresenceCondition or = emptyConditions.or(nestedPresenceCondition);

                emptyConditions.delRef();
                emptyConditions = or;

              } else {

                // We have the first token in a non-empty branch.

                tokenSet.add(new Lookahead(a,
                                           nestedPresenceCondition.addRef()));

              }

              nestedPresenceCondition.delRef();

              // Skip ahead to the next branch or stop when we find the
              // #endif

              while (true) {

                // If we have reached the next branch or are at the end
                // of the conditional, then leave the loop.

                if (a.syntax.kind() == Kind.CONDITIONAL
                    && (a.syntax.toConditional().tag() == ConditionalTag.NEXT
                        || a.syntax.toConditional().tag()
                        == ConditionalTag.END)) {
                  break;
                }


                // a is now a language token or a start conditional.
                // Move to the next token.

                if (a.syntax.kind() == Kind.CONDITIONAL) {
                  assert a.syntax.toConditional().tag() == ConditionalTag.START
                    || a.syntax.toConditional().tag() == ConditionalTag.NEXT;
                  a = skipConditional(a);
                } else {
                  a = a.getNext();
                }
              }


              // We are now on a next branch or an endif.

              if (a.syntax.kind() == Kind.CONDITIONAL
                  && a.syntax.toConditional().tag() == ConditionalTag.END) {

                // On an #endif we are done.

                break;

              } else {

                // It must be a NEXT conditional.

                assert a.syntax.toConditional().tag() == ConditionalTag.NEXT;


                // Update the union of branch presence conditions.

                PresenceCondition newUnion = union.or(a.syntax.toConditional().presenceCondition);
                union.delRef();
                union = newUnion;
              }
            }


            // Discover whether there is an implicit-else or not.  To do
            // this, we check the union of all branches conditions
            // against the presence condition (presenceCondition) of the
            // current subparser.
            //
            // union.not() is the condition of the implicit else.  If it
            // is always false under the current presence condition,
            // then there is no implicit else.

            PresenceCondition elseBranch = subparser.presenceCondition.andNot(union);
            union.delRef();


            if (! elseBranch.isFalse()) {

              // Save the presence condition of the empty, implicit
              // else.

              PresenceCondition or = emptyConditions.or(elseBranch);
              emptyConditions.delRef();
              emptyConditions = or;
            }

            elseBranch.delRef();
            

            if (! emptyConditions.isFalse()) {
              // We need to fork a subparser that sits on #endif,
              // because their were empty branches.

              tokenSet.add(new Lookahead(a, emptyConditions));
            } else {
              emptyConditions.delRef();
            }


            // Fork and replace the subparser with newly-forked
            // subparsers, one for each token in the follow set.

            processedParsers.addAll(fork(subparser, tokenSet));


            // Clean up subparser scope and presenceCondition.  It is removed
            // from the set of subparsers.

            subparser.lookahead.presenceCondition.delRef();
            subparser.presenceCondition.delRef();
            subparser.scope.free();

            break;

          case NEXT:

            // Move on and reschedule the subparser.

            subparser.lookahead.token = skipConditional(subparser.lookahead.token);

            processedParsers.add(subparser);
            break;

          case END:

            // Move on and reschedule the subparser.

            subparser.lookahead.token = subparser.lookahead.token.getNext();

            processedParsers.add(subparser);
            break;

          default:
            // Can only be #if or #endif.
            throw new RuntimeException();
          }


        } else {
          // The subparser can only be on LANGUAGE, EOF, and
          // CONDITIONAL tokens.

          throw new RuntimeException();
        }
      }


      // Add the updated subparsers into the priority queue of
      // subparsers.

      for (Subparser subparser : processedParsers) {
        subparsers.add(subparser);
      }


      if (subparsers.size() == 0) {
        // Done
        break;
      }


      // Merge subparsers.  We only need check the earliest subparsers for
      // a merge.

      if (subparsers.size() > 1) {
        stagedMerge(subparsers);
      }
    }


    if (parserStatistics) {
      int max = 0;
      runtime.errConsole().pln(String.format("iterations %d", iterations));
      for (Integer size : nsubparsers.keySet()) {
        if (size > max) max = size;

        runtime.errConsole().pln(String.format("subparsers %d %d",
                                               size, nsubparsers.get(size)));
      }
      runtime.errConsole().pln(String.format("max_subparsers %d", max)); 
      runtime.errConsole().pln(String.format("follow %d", nfollow)); 
      runtime.errConsole().flush();
    }

    if (actions.hasContext()) {
      actions.getInitialContext().free();
    }

    return root;
  }

  /**
   * Find the FOLLOW set of a given token.  When the given token is an
   * ordinary token, the set is just the token alone.  But when the
   * token is a conditional, this method returns the set of ordinary
   * tokens reachable from this conditional in all configurations.
   *
   * @param a The token to find the follow set of.
   * @param presenceCondition The presence condition of a.  This
   * presence condition will be freed, so pass a reference.
   * @return The follow set of the given token.
   */
  public Map<Integer, Lookahead> follow(OrderedSyntax a,
                                        PresenceCondition presenceCondition)
    throws IOException {
    Map<Integer, Lookahead> result = new HashMap<Integer, Lookahead>();

    presenceCondition.addRef();

    if (parserStatistics) {
      nfollow++;
    }

    while (true) {

      // Get the first token of a.

      PresenceCondition emptyCondition = first(result, a, presenceCondition);


      // Update the presence condition to be the condition of the
      // empty branches.

      presenceCondition.delRef();
      presenceCondition = emptyCondition;


      // If there are no empty branches, we need not continue.  We are
      // done finding the follow set.

      if (presenceCondition.isFalse()) {
        presenceCondition.delRef();

        return result;
      }


      // Get next token after stepping out of conditionals.

      do {
        switch (a.syntax.kind()) {
        case LANGUAGE:

          // Get the next token from the input.

          a = a.getNext();
          break;

        case CONDITIONAL:

          // Get the next token after the conditional.

          Conditional conditional = a.syntax.toConditional();

          switch (conditional.tag()) {
          case START:
            a = skipConditional(a);
            break;

          case NEXT:
            a = skipConditional(a);
            break;

          case END:
            a = a.getNext();
            break;

          default:
            throw new UnsupportedOperationException();
          }
          break;

        default:
          throw new RuntimeException("FMLR only takes language " +
                                     "and conditional tokens.");
        }

        // Until a does not end a branch.
        
      } while (a.syntax.kind() == Kind.CONDITIONAL &&
               (a.syntax.toConditional().tag() == ConditionalTag.NEXT
                || a.syntax.toConditional().tag() == ConditionalTag.END));
    }
  }

  /**
   * Find the FIRST set of a given token.  An ordinary token has
   * itself and only itself in its first set.  For a conditional, the
   * first set has the first token in each branch.  If there are empty
   * branches, it returns the presence condition of the empty
   * branches, which indicates that the follow set computation needs
   * to continue populating the follow set.
   *
   * This is a helper routine for follow.  It assumes conditionals are
   * well-formed.
   *
   * @param result The follow-set found so far.
   * @param a The token for which to find the first-set.
   * @param presenceCondition The presence condition of a.
   * @return The presence condition of empty branches.  It is
   * non-false if the follow method should continue looking for
   * tokens.
   */
  private PresenceCondition first(Map<Integer, Lookahead> result, OrderedSyntax a,
                        PresenceCondition presenceCondition) throws IOException {

    presenceCondition.addRef();

    while (true) {
      switch (a.syntax.kind()) {
      case EOF:
        // Fall through
      case LANGUAGE:

        // Add the token to the follow set.  If it is already there,
        // just update the presence condition.

        if (! result.containsKey(a.getSequenceNumber())) {

          // Add a new token to the follow-set.

          result.put(a.getSequenceNumber(),
                     new Lookahead(a, presenceCondition.addRef()));

        } else {

          // Update the presence condition.

          Lookahead n = result.get(a.getSequenceNumber());
          PresenceCondition union = n.presenceCondition.or(presenceCondition);
          n.presenceCondition.delRef();
          n.presenceCondition = union;
        }

        presenceCondition.delRef();
        return presenceConditionManager.new PresenceCondition(false);

      case CONDITIONAL:
        Conditional conditional = a.syntax.toConditional();

        switch (conditional.tag()) {
        case NEXT:
          // Fall through
        case END:

          // If the token ends a branch, i.e. NEXT or END, then we
          // need to keep looking for a first token after the end of
          // the conditional.

          return presenceCondition;

        case START:

          // Save the presence conditions of all empty branches.
          // This is necessary to attribute the correct presence
          // condition to the first token following a conditional
          // with empty branches.
          //
          // This is equivalent to the "cont" variable in the
          // FOLLOW/FIRST algorithm description.

          PresenceCondition emptyConditions = presenceConditionManager.new PresenceCondition(false);


          // The union of the branches conditions.  Used to determine
          // whether there is an implicit else branch or not.

          PresenceCondition union = a.syntax.toConditional().presenceCondition.addRef();


          // Loop through each branch of the conditional, find the
          // first token of each.

          while (! (a.syntax.kind() == Kind.CONDITIONAL
                    && a.syntax.toConditional().tag()
                    == ConditionalTag.END)) {

            // Get the presence condition of the branch.  It is
            // conjoined with the presence condition in which it is
            // nested.

            PresenceCondition nestedPresenceCondition
              = presenceCondition.and(a.syntax.toConditional().presenceCondition);


            // a is on the conditional starting the branch.  Get the
            // first the token after the one starting the branch.  It
            // will either be the first token in the branch, or the
            // token that ends the branch.

            a = a.getNext();


            if (nestedPresenceCondition.isFalse()) {

              // If the nestedPresenceCondition is false, the branch is
              // an infeasible path, so skip the branch.

            } else {

              // Get the first token in the branch if there is one.  If
              // not, then the branch is empty, and we need to find the
              // first token after the conditional.

              PresenceCondition emptyBranch = first(result, a, nestedPresenceCondition);

              if (! emptyBranch.isFalse()) {

                // Save the presence condition of the empty branch.

                PresenceCondition or = emptyConditions.or(emptyBranch);
                emptyConditions.delRef();
                emptyConditions = or;
              }

              emptyBranch.delRef();
            }

            nestedPresenceCondition.delRef();

            // Skip ahead to the next branch or stop when we find the
            // #endif

            while (true) {

              // If we have reached the next branch or are at the end
              // of the conditional, then leave the loop.

              if (a.syntax.kind() == Kind.CONDITIONAL
                  && (a.syntax.toConditional().tag() == ConditionalTag.NEXT
                      || a.syntax.toConditional().tag()
                      == ConditionalTag.END)) {
                break;
              }


              // a is now a language token or a start conditional.
              // Move to the next token.

              if (a.syntax.kind() == Kind.CONDITIONAL) {
                assert a.syntax.toConditional().tag() == ConditionalTag.START
                  || a.syntax.toConditional().tag() == ConditionalTag.NEXT;
                a = skipConditional(a);
              } else {
                a = a.getNext();
              }
            }


            // Move to the next branch or #endif.

            if (a.syntax.kind() == Kind.CONDITIONAL
                && a.syntax.toConditional().tag() == ConditionalTag.END) {

              break;

            } else {

              // It must be a NEXT conditional.

              assert a.syntax.toConditional().tag() == ConditionalTag.NEXT;


              // Update the union of branch presence conditions.

              PresenceCondition newUnion = union.or(a.syntax.toConditional().presenceCondition);
              union.delRef();
              union = newUnion;
            }
          }


          // Discover whether there is an implicit-else or not.  To do
          // this, we check the union of all branches conditions
          // against the presence condition (presenceCondition) of the
          // current subparser.
          //
          // union.not() is the condition of the implicit else.  If it
          // is always false under the current presence condition,
          // then there is no implicit else.

          PresenceCondition elseBranch = presenceCondition.andNot(union);
          union.delRef();


          if (! elseBranch.isFalse()) {

            // Save the presence condition of the empty, implicit
            // else.

            PresenceCondition or = emptyConditions.or(elseBranch);
            emptyConditions.delRef();
            emptyConditions = or;
          }

          elseBranch.delRef();
            


          // Record whether the conditional is empty.

          if (parserStatistics) {
            // Count empty conditionals.  The logic below ensures that
            // if there is at least one time when a conditional is
            // non-empty, the conditional is not marked as empty.
            // This is a more conservative way to count empty
            // conditionals.

            if (emptyConditions.isFalse()) {
              // Not empty.

              emptyConditionals.put(a.getSequenceNumber(), false);

            } else {
              // Empty.
              
              if (emptyConditionals.containsKey(a.getSequenceNumber())) {
                emptyConditionals.put(a.getSequenceNumber(),
                                      true && emptyConditionals
                                      .get(a.getSequenceNumber()));
              } else {
                emptyConditionals.put(a.getSequenceNumber(), true);
              }
            }
          }


          if (emptyConditions.isFalse()) {

            // No branch is empty.

            presenceCondition.delRef();

            return emptyConditions;
          }

          // Set the presence condition to be that of the empty
          // branches.

          presenceCondition.delRef();
          presenceCondition = emptyConditions;


          // Move a to the next token after the conditional's #endif.

          a = a.getNext();

          break;

        default:
          throw new UnsupportedOperationException();
        }
        break;

      default:
        throw new UnsupportedOperationException();
      }
    }
  }

  /**
   * Test whether the conditional token already has a follow-set
   * computed.
   *
   * @param t The conditional.
   * @return true if the follow-set is cached.
   */
  public boolean hasCachedSet(OrderedSyntax t) {
    return followCache.containsKey(t.getSequenceNumber());
  }

  /**
   * Get the cached follow-set for a conditional token.
   *
   * @param t The conditional.
   * @return The follow-set.
   */
  public Collection<Lookahead> getCachedSet(OrderedSyntax t) {
    return followCache.get(t.getSequenceNumber());
  }

  /**
   * Cache the conditional token's follow-set.
   *
   * @param t The conditional.
   */
  public void setCachedSet(OrderedSyntax t, Collection<Lookahead> follow) {
    followCache.put(t.getSequenceNumber(), follow);
  }

  /**
   * Merge subparsers in the ordered list.  This method checks an
   * internal flag, MERGE_ALL, to determine whether to merge only the
   * subparsers on the earliest token or all subparsers in the list.
   * This policy reflects a trade-off between faster merging versus
   * fewer subparsers.
   *
   * @param subparsers The ordered list of subparsers to check for and
   * perform merges.  This method assumes there is more than one
   * subparser.
   */
  private List<Subparser> processed = new LinkedList<Subparser>();
  private List<Subparser> subset = new ArrayList<Subparser>();
  private void stagedMerge(PriorityQueue<Subparser> subparsers) {
    if (MERGE_ALL) {
      // Check for the need to merge and then execute the merge for
      // all sets of subparsers on the same token.
      while (! subparsers.isEmpty()) {
        Subparser first = subparsers.poll();

        if (subparsers.isEmpty()
            || (first.lookahead.token.order - subparsers.peek().lookahead.token.order) != 0) {
          // There is only one subparser at the earliest token.  No way
          // to merge, so put it back in the priority queue.
          processed.add(first);

        } else {
          // Get the earliest token.
          OrderedSyntax earliestToken = first.lookahead.token;

          // Get the list of earliest subparsers to compare pair-wise
          // for mergeability.
          subset.add(first);

          // Pull the earliest subparsers off of the main set of
          // subparsers.
          while (! subparsers.isEmpty()
                 && (subparsers.peek().lookahead.token.order - earliestToken.order) == 0) {
            subset.add(subparsers.poll());
          }

          // Merge the subset.
          subset = merge(subset);

          // Add the processed and merged subparsers back to the main
          // set of subparsers.
          processed.addAll(subset);
          subset.clear();
        }
      }

      for (Subparser subparser : processed) {
        subparsers.add(subparser);
      }

    } else {
      // Check for the need to merge and then execute the merge only for
      // the set of subparsers on the earliest token

      Subparser first = subparsers.poll();

      if ((first.lookahead.token.order - subparsers.peek().lookahead.token.order) != 0) {
        // There is only one subparser at the earliest token.  No way
        // to merge, so put it back in the priority queue.
        subparsers.add(first);

      } else {
        // Get the list of earliest subparsers to compare pair-wise
        // for mergeability.
        subset.add(first);

        // Get the earliest token.
        OrderedSyntax earliestToken = first.lookahead.token;

        // Pull the earliest subparsers off of the main set of subparsers.
        while (subparsers.size() > 0
               && (subparsers.peek().lookahead.token.order - earliestToken.order) == 0) {
          subset.add(subparsers.poll());
        }

        // Merge the subset.
        subset = merge(subset);

        // Add the processed and merged subparsers back to the main
        // set of subparsers.
        for (Subparser subparser : subset) {
          subparsers.add(subparser);
        }
        subset.clear();
      }
    }
    processed.clear();
  }

  /**
   * Merge a set of subparsers.  This method assumes that all the
   * subparsers in the input set are on the same token already.
   *
   * @param subset The subparsers to merge.  They all should be on the
   * @param The merged set of subparsers.
   * same token.
   */
  private LinkedList<Subparser> mergedParsers = new LinkedList<Subparser>();
  private List<Subparser> merge(List<Subparser> subset) {
    // Check each pair of the earliest subparsers for mergeability.
    for (int outer = 0; outer < subset.size(); outer++) {
      Subparser subparser = subset.get(outer);

      for (int inner = 0; inner < subset.size(); inner++) {
        Subparser compareParser = subset.get(inner);

        // Can't merge with self.
        if (subparser == compareParser) continue;

        assert subparser.lookahead.token.order == compareParser.lookahead.token.order;

        // See if the subparsers can merge.  Two subparsers can merge
        // if the following hold: (1) they are on the same token (we
        // already know this since only checking earliest subparsers),
        // (2), the token is classified the same way under the parsing
        // presenceCondition, (3) they have the same parsing state, (4) they
        // have mergeable parsing presenceConditions, and (5) they aren't
        // pointing to the exact same stack frame, because this means
        // the subparsers were just forked.
        boolean sameTokenType
          = (subparser.lookahead.token.syntax.kind() == Kind.LANGUAGE
             && subparser.lookahead.token.syntax.toLanguage().tag()
             == compareParser.lookahead.token.syntax.toLanguage().tag())
          || subparser.lookahead.token.syntax.kind() != Kind.LANGUAGE;

        if (sameTokenType
            && actions.isComplete(subparser.stack.symbol)
            && subparser.scope.mayMerge(compareParser.scope)
            && subparser.stack.isMergeable(compareParser.stack)
            && subparser.stack != compareParser.stack) {

          // Save the subparser for later merging.
          mergedParsers.addLast(compareParser);


          // Remove the merged parser from the set of active
          // subparsers.
          subset.remove(inner);
          inner--;

          // Update the index for the next subparser.
          if (inner < outer) {
            outer--;
          }
        }
      }

      if (mergedParsers.size() > 0) {
        // Merge the subparsers.  Create a merged subparser with a new
        // (1) semantic value, (2) presence condition, and (3) parsing
        // presenceCondition.  The construction of each follows below.  As an
        // optimization, the current parserElement subparser is
        // replaced in-memory with the new subparser.

        // (1) Combine their semantic values.  This acheived by creating
        // a new stack fragment that is as deep as the split in the
        // stack.  Each frame in the new stack fragment has a semantic
        // value that is a conditional containing the semantic values
        // from each of the merged subparsers' stacks.

        // Find the distance down the GSS of the highest common
        // descendent of all subparsers.  The GSS is an up-tree
        // instead of a DAG, which is why the following algorithm will
        // work.

        int maxDist = 0;

        StackFrame s = subparser.stack;

        for (Subparser mergedParser : mergedParsers) {
          int dist = 0;
          StackFrame t = mergedParser.stack;

          while (s != null && s != t) {
            s = s.next;
            t = t.next;
            dist++;
          }

          if (dist > maxDist) {
            maxDist = dist;
          }
        }

        // Create the new AST CHOICE_NODE_NAME nodes to store the
        // combined semantic values and their presence conditions.
        // This creates a new stack fragment that duplicates the
        // current parserElement's stack down maxDist stack element.
        // Each new stack element contains a CHOICE_NODE_NAME node with
        // the original semantic value and the subparser's presence
        // condition.

        // Duplicate the stack fragment down to maxDist.

        // Replace the top stack frame for the merged subparser.
        subparser.stack = new StackFrame(subparser.stack.state,
                                         subparser.stack.symbol,
                                         subparser.stack.value,
                                         subparser.stack.next);

        // Duplicate the rest of the stack.
        StackFrame u = subparser.stack;

        for (int i = 0; i < maxDist - 1; i++) {
          u.next = new StackFrame(u.next.state, u.next.symbol,
                                  u.next.value, u.next.next);
          u = u.next;
        }

        // Combine all the merged parser's semantic values.
        for (Subparser mergedParser : mergedParsers) {
          subparser.stack.merge(subparser.presenceCondition, mergedParser.stack,
                            mergedParser.presenceCondition, maxDist);
        }


        // (2) Find the logical disjunction of all the merged
        // subparsers' presence conditions.
        PresenceCondition disjunction = subparser.presenceCondition;

        for (Subparser mergedParser : mergedParsers) {
          PresenceCondition or = disjunction.or(mergedParser.presenceCondition);

          disjunction.delRef();
          disjunction = or;
        }

        // Update the subparser with the new, combined presence
        // condition.
        subparser.presenceCondition = disjunction;

        subparser.lookahead.presenceCondition.delRef();

        if (! subparser.lookahead.isSet()) {
          subparser.lookahead.presenceCondition = disjunction.addRef();

        } else {
          // Replace a lookahead set with just a regular lookahead.
          // If one or more subparsers already contains a set (due to
          // shared reductions or lazy forking) then the set contains
          // the follow-set with the presence conditions only for the
          // current subparser.  We avoid have incorrect presence
          // conditions by replacing the lookahead with a new one that
          // isn't a set.  Then, the follow-set for the token will be
          // computed as normal

          ((LookaheadSet) subparser.lookahead).free();
          subparser.lookahead = new Lookahead(subparser.lookahead.token, disjunction.addRef());
        }

        // (3) Use the parsing presenceConditions merge method to construct the
        // new parsing presenceCondition.
        for (Subparser mergedParser : mergedParsers) {
          subparser.scope.merge(mergedParser.scope);
        }

        // Lastly, clean up the merged subparsers memory use.
        for (Subparser mergedParser : mergedParsers) {
          mergedParser.lookahead.presenceCondition.delRef();
          if (mergedParser.lookahead.isSet()) ((LookaheadSet) mergedParser.lookahead).free();
          mergedParser.presenceCondition.delRef();
          mergedParser.scope.free();
        }

        mergedParsers.clear();
      }
    }

    return subset;
  }

  /**
   * Fork subparser on a set of tokens.
   *
   * @param tokenSet The set of tokens.
   * @return A collection of the forked subparsers.
   */
  private Collection<Subparser> fork(Subparser subparser,
                                     Collection<Lookahead> tokenSet) {
    LinkedList<Subparser> processedParsers = new LinkedList<Subparser>();

    for (Lookahead n : tokenSet) {
      Subparser forkedSubparser = new Subparser(n,
                                                subparser.stack,
                                                n.presenceCondition.addRef(),
                                                subparser.scope.fork());
      if (FAST_FINISH_EOF
          && Kind.EOF
          == forkedSubparser.lookahead.token.syntax.kind()) {
        fastFinish(forkedSubparser);
      } else {
        processedParsers
          .addLast(forkedSubparser);
      }
    }

    return processedParsers;
  }

  
  /**
   * Partition the follow-set by shared reductions and create new
   * subparsers for the tokens and token-sets resulting from the
   * partition.
   *
   * @param tokenSet The set of tokens.
   * @param subparser The subparser that is being forked.
   * @return The partitioned set of next tokens.
   */
  private Collection<Lookahead> partition(Collection<Lookahead> tokenSet,
                                          Subparser subparser) {

    Collection<Lookahead> partition = new LinkedList<Lookahead>();

    // Partition the reduces into sets based on what production they
    // are reducing, i.e. shared reductions.
    HashMap<Integer, Lookahead> sharedReductions = null;

    // Partition the shifts into a single set for later lazy forking.
    Lookahead shifts = null;

    // Partition the token set.
    for (Lookahead n : tokenSet) {
      getAction(n, subparser.stack);

      if (optimizeSharedReductions
          && ParsingAction.REDUCE == n.getAction()) {

        // Partition ordinary tokens in the follow set by the
        // production they are reducing.

        if (null == sharedReductions) {
          sharedReductions = new HashMap<Integer, Lookahead>();
        }

        if (sharedReductions.containsKey(n.getActionData())) {

          Lookahead element = sharedReductions.get(n.getActionData());
          LookaheadSet set;

          // If there was only one token with this reduction
          // so far, then make a new lookahead set.

          if (element.isSet()) {
            set = (LookaheadSet) element;

          } else {
            // Create the lookahead set.
            set = new LookaheadSet(subparser.lookahead.token,
                                   element.presenceCondition.addRef(),
                                   element.getAction(),
                                   element.getActionData()); 
            set.add(element);

            // Add the set of lookaheads to the shared reductions.
            sharedReductions.put(n.getActionData(), set);
          }

          // Add the new token to the shared reduction set.
          set.add(n);

          // Update the set's presence condition.
          PresenceCondition union = set.presenceCondition.or(n.presenceCondition);
          set.presenceCondition.delRef();
          set.presenceCondition = union;

        } else {
          // This is the first token that is reducing this production.
          sharedReductions.put(n.getActionData(), n);
        }


      } else if (optimizeLazyForking
                 && ParsingAction.SHIFT == n.getAction()) {

        if (null == shifts) {
          // No tokens have been added yet.
          shifts = n;

        } else {
          LookaheadSet set;

          if (shifts.isSet()) {
            // We already have a set.
            set = (LookaheadSet) shifts;

          } else {
            // There is more than one shifting token, but we have only
            // seen one.  Create a new set to house both of them.
            Lookahead element = shifts;

            // Create the lookahead set.
            set = new LookaheadSet(subparser.lookahead.token,
                                   element.presenceCondition.addRef(),
                                   element.getAction(),
                                   element.getActionData()); 
            set.add(element);

            shifts = set;
          }

          // Add the new token to the set of shifting tokens.
          set.add(n);

          // Update the set's presence condition.
          PresenceCondition union = set.presenceCondition.or(n.presenceCondition);
          set.presenceCondition.delRef();
          set.presenceCondition = union;
        }

      } else {

        // Add the ordinary token by itself to the partition.  For
        // naive FMLR, no partitioning is really done; all tokens are
        // partitioned into their own trivial subsets.

        partition.add(n);
      }
    }


    // Add the shared reductions to the partition.

    if (null != sharedReductions) {
      partition.addAll(sharedReductions.values());
    }


    // Add the shifts to the partition.

    if (null != shifts) {
      partition.add(shifts);
    }


    // Return the partition.

    return partition;
  }

  /**
   * Lazily fork the set of shifts.  Partition the set of next tokens
   * into individual tokens for the current conditional and a single
   * token for the ordinary token or start conditional that follows
   * the current conditional.
   *
   * @param tokenSet The set that is being lazily forked.
   * @return The partitioned set of tokens.
   * @throws IOException because it may read tokens from input.
   * @throws InvalidCastException if subparser.lookahead is not a LookaheadSet
   * object.
   * @throws IllegalStateException if any next token does not cause a
   * shift action.  It also is thrown if the lazy forking optimization
   * is turned off but this method is called.  Additionally it is
   * thrown if tokenSet.token.syntax is not a START conditional.
   */
  private Collection<Lookahead> lazyFork(LookaheadSet tokenSet)
    throws IOException {

    if (tokenSet.token.syntax.kind() != Kind.CONDITIONAL
        || tokenSet.token.syntax.toConditional().tag() != ConditionalTag.START
        || ! optimizeLazyForking) {
      throw new IllegalStateException();
    }


    // Get the sequence numbers for the START conditional and the
    // first token after the END of this conditional.  Only the tokens
    // within this ranged will be forked.  The range includes the
    // START but is exclusive of the after token, i.e. in range
    // notation: [min, maxExclusive).

    int min = tokenSet.token.getSequenceNumber();
    OrderedSyntax after = skipConditional(tokenSet.token);
    int maxExclusive = after.getSequenceNumber();


    // Move to the next ordinary token or start conditional
    // (#if).  If the next token ends a branch (#elif or
    // #endif), move to the next ordinary token or start
    // conditional after the conditional.

    while (after.syntax.kind() == Kind.CONDITIONAL
           && after.syntax.toConditional().tag
           != ConditionalTag.START) {
      Conditional conditional = after.syntax.toConditional();

      switch (conditional.tag()) {
      case START:
        // No need to move.
        break;

      case NEXT:
        after = skipConditional(after);
        break;

      case END:
        after = after.getNext();
        break;

      default:
        // No such conditional tag.
        throw new UnsupportedOperationException();
      }
    }


    // Partition the set into two: (1) the _set_ of tokens (even if
    // there's only one, to ensure it can merge with other subparsers
    // at that conditional) that fall inside the current conditional
    // [min, maxExclusive) and (2) the _token_ (ordinary or START
    // conditional.  Make sure that (2), the token, has a presence
    // condition that is the union of all the remaining tokens for
    // correctness.

    Collection<Lookahead> forkedSet = new LinkedList<Lookahead>();

    Lookahead remainder = null;

    for (Lookahead n : tokenSet.set) {

      if (min < n.token.getSequenceNumber()
          && n.token.getSequenceNumber() < maxExclusive) {

        // The token is inside the current conditional.  Add to the
        // set of return tokens.

        forkedSet.add(n);

      } else {

        // The token is not inside the current conditional.  Create
        // the remainder token and union the presence conditions of
        // the tokens outside the conditional.

        if (null == remainder) {

          // This is the first token of the remainder.

          remainder = new Lookahead(after, n.presenceCondition.addRef());

        } else {

          // There is more than one token that is not in the current
          // conditional.  Update the remainder's presence condition.

          PresenceCondition union = remainder.presenceCondition.or(n.presenceCondition);

          remainder.presenceCondition.delRef();
          remainder.presenceCondition = union;
        }

        // Clean up these tokens.  The follow set will be called on
        // the remainder again anyway.

        n.presenceCondition.delRef();
      }
    }


    // Add the remainder token to the set of return tokens.

    if (null != remainder) {
      forkedSet.add(remainder);
    }


    // Collect statistics on empty branches.

    if (parserStatistics) {
      lazyForks++;
      if (null != remainder) {
        lazyForksEmptyBranches++;
      }
    }

    return forkedSet;
  }

  /**
   * Skip an entire conditional block.  The given token must be a
   * conditional start or next token.
   *
   * @param a The conditional start or next token.
   * @return The first token after the end of the conditional.
   */
  private OrderedSyntax skipConditional(OrderedSyntax a)
    throws IOException {

    if (a.syntax.toConditional().tag() != ConditionalTag.START
        && a.syntax.toConditional().tag() != ConditionalTag.NEXT) {
      throw new RuntimeException("skipConditional must take a " +
                                 "start or next conditional token.");
    }

    // Check the cache to see if we already found the next token for
    // this start or next conditional.

    if (skipConditionalCache.containsKey(a.getSequenceNumber())) {
      return skipConditionalCache.get(a.getSequenceNumber());
    }


    // Save the input's sequence number for later caching.

    int sequenceNumber = a.getSequenceNumber();


    // Move to the first token after the start of the conditional and
    // carefully past it, matching #ifs and #endif and keeping track
    // of other nested conditionals.

    int nesting = 1;

    do {
      a = a.getNext();

      if (a.syntax.kind() == Kind.CONDITIONAL) {
        switch (a.syntax.toConditional().tag()) {
        case START:
          nesting++;
          break;

        case END:
          nesting--;
          break;
        }
      }
                    
    } while (nesting > 0);


    // Now we are on the #endif.  Return the next token after the end
    // of the conditional.

    OrderedSyntax returnToken = a.getNext();

    // Cache the token.

    skipConditionalCache.put(sequenceNumber, returnToken);

    return returnToken;
  }

  
  /**
   * Shift the subparser.
   *
   * @param subparser The subparser to shift.
   */
  private void shift(Subparser subparser) {
    Lookahead x = subparser.lookahead;
    Language<? extends LanguageTag> token = x.token.syntax.toLanguage();
    int yystate = x.getActionData();
    int symbol = token.tag().getID();

    if (showActions) {
      runtime.errConsole().pln("shifting " + token.tag() + "("
                               + token.getTokenText() + ")").flush();
    }
    
    // Layout has no semantic value, but keep them when printing the
    // AST as C source.
    if (! runtime.test("printSource")
        && Actions.ValueType.LAYOUT
        == actions.getValueType(symbol)) {
      token = null;
    }

    // Push the new state onto the stack.
    subparser.stack = new StackFrame(yystate, symbol, token, subparser.stack);
  }

  
  /**
   * Reduce the subparser.
   *
   * @param subparser The subparser to reduce.
   */
  private void reduce(Subparser subparser) {
    int production = subparser.lookahead.getActionData();
    int yylen = ForkMergeParserTables.yyr2.table[production];
    int symbol = ForkMergeParserTables.yyr1.table[production];
    String nodeName = ForkMergeParserTables.yytname.table[symbol];;

    if (showActions) {
      runtime.errConsole().pln("reducing " + nodeName).flush();
    }

    // Get the semantic values from the stack.

    StackFrame topState = subparser.stack;
    Pair<Object> values = Pair.<Object>empty();
  
    for (int i = 0; i < yylen; i++) {
      // Don't bother adding null semantic values as children.
      if (null != topState.value) {
        values = new Pair<Object>(topState.value, values);
      }
      topState = topState.next;
    }


    // Get the goto parsing state.

    int yystate;

    yystate = ForkMergeParserTables
      .yypgoto.table[symbol - ForkMergeParserTables.YYNTOKENS] + topState.state;

    if (0 <= yystate && yystate <= ForkMergeParserTables.YYLAST
        && ForkMergeParserTables.yycheck.table[yystate] == topState.state) {

      yystate = ForkMergeParserTables.yytable.table[yystate];

    } else {
      yystate= ForkMergeParserTables
        .yydefgoto.table[symbol - ForkMergeParserTables.YYNTOKENS];
    }


    // Construct the new semantic value.

    Actions.ValueType valueType = actions.getValueType(symbol);
    Object value;
    
    switch (valueType) {
    case ACTION:
      // Semantic action nonterminals have no semantic value and
      // should be empty.  Not until new implementation of semantic
      // actions.

      if (Pair.<Object>empty() == values) {
        value = null;
        break;

      } else {
        throw new UnsupportedOperationException("semantic actions " + 
                                                "nonterminals should " +
                                                "have no semantic value");
      }
    
    case LAYOUT:
      // Layout nonterminals have no semantic values.

      value = null;
      break;

    case PASS_THROUGH:
      if (Pair.<Object>empty() == values) {
        value = null;

      } else if (values.tail() == Pair.<Object>empty()) {

        // If there is one child, then pass-through.

        value = values.head();
        break;

      } else {
        // Pass-through nonterminals only get passed-through when they
        // have one child.

        // Fall through to the default case.
      }
      
    case NODE:
      value = actions.getValue(symbol, nodeName, values);
      break;

    case LIST:
      if (values == Pair.<Object>empty()) {
        value = GNode.create(nodeName);

      } else {
        if (nodeName.equals(((Node) values.head()).getName())) {
          value = ((Node) values.head());
          values = values.tail();

        } else {
          value = GNode.create(nodeName);
        }

        for (Object o : values) {
          GNode conditionalNode = GNode.create(CHOICE_NODE_NAME);
          conditionalNode.add(subparser.presenceCondition.addRef());
          conditionalNode.add(o);
          ((Node) value).add(conditionalNode);
        }
      }
      break;

    default:
      throw new UnsupportedOperationException("unsupported node type");
    }

    // Push the new state onto the stack.
    subparser.stack = new StackFrame(yystate, symbol, value, topState);

    // Dispatch the semantic action if there is one.
    actions.dispatch(symbol, subparser);
  }


  /**
   * Get the parsing action for a token.  This method is adopted from
   * Bison's parsing algorithm.
   *
   * @param x The token to find the parsing action for.
   * @param s The state to use to find the action.
   */
  private void getAction(Lookahead x, StackFrame s) {
    if (x.token.syntax.kind() == Kind.LANGUAGE
        || x.token.syntax.kind() == Kind.EOF) {
      int yyn;
      int yystate;
      
      yystate = s.state;
      
      yyn = ForkMergeParserTables.yypact.table[yystate];
      

      if (ForkMergeParserTables.YYPACT_NINF == yyn) {
        // Decide to reduce without looking at the next token.  This
        // is a Bison thing.

        yyn = ForkMergeParserTables.yydefact.table[yystate];

        if (0 == yyn) {

          x.setAction(ParsingAction.ERROR, NODEFAULT);

        } else {

          x.setAction(ParsingAction.REDUCE, yyn);
        }

      } else {
        // Find the parsing action for the next token.

        // Get the token's Bison symbol number.

        int yytoken;
  
        if (x.token.syntax.kind() == Kind.EOF) {
          yytoken = ForkMergeParserTables.YYEOF;

        } else if (x.token.syntax.kind() == Kind.LANGUAGE) {
          Language<? extends LanguageTag> token = x.token.syntax.toLanguage();
          String str = token.getTokenText();
          LanguageTag tokentype = token.tag();

          yytoken = token.tag().getID();
        } else {
          yytoken = -1;
        }
  

        // Index into action table, state row + token column.

        yyn += yytoken;


        // Lookup the parsing action.
        
        if (yyn < 0 || ForkMergeParserTables.YYLAST < yyn
            || ForkMergeParserTables.yycheck.table[yyn] != yytoken) {

          yyn = ForkMergeParserTables.yydefact.table[yystate];

          if (0 == yyn) {
            x.setAction(ParsingAction.ERROR, NODEFAULT);

          } else {
            x.setAction(ParsingAction.REDUCE, yyn);
          }

        } else {
          yyn = ForkMergeParserTables.yytable.table[yyn];
          
          if (yyn <= 0) {
            if (0 == yyn || ForkMergeParserTables.YYTABLE_NINF == yyn) {
              x.setAction(ParsingAction.ERROR, INVALID);

            } else {
              yyn = -yyn;
              x.setAction(ParsingAction.REDUCE, yyn);
            }

          } else {
            yystate = yyn;
            
            if (ForkMergeParserTables.YYFINAL == yystate) {
              x.setAction(ParsingAction.ACCEPT, -1);
              x.action = ParsingAction.ACCEPT;

            } else {
              x.setAction(ParsingAction.SHIFT, yystate);
            }
          }
        }
      }
    } else {
      throw new UnsupportedOperationException("parser does not handle " +
                                              "any other tokens besides " +
                                              "ordinary and conditional.");
    }
  }

  void fastFinish(Subparser subparser) {
    // We know that EOF is that last token and that its
    // follow-set always contains only EOF itself.  Finish
    // up the parsing until we reach an ACCEPT or ERROR,
    // one of which must happen eventually on EOF.
    boolean done = false;
    do {
      getAction(subparser.lookahead, subparser.stack);
      switch (subparser.lookahead.getAction()) {
      case REDUCE:
        reduce(subparser);
        subparser.lookahead.clearAction();
        break;

      case ACCEPT:
        accepted.add(subparser);

        if (showAccepts) {
          runtime.errConsole().pln("ACCEPT (fast finish)").flush();
        }

        done = true;
        break;

      case ERROR:

        // Clean up subparser scope and presenceCondition.  We will not add
        // it back to the main set of subparsers.

        subparser.lookahead.presenceCondition.delRef();
        subparser.presenceCondition.delRef();
        subparser.scope.free();

        if (showErrors) {
          runtime.error("parse error on "
                        + (subparser.lookahead.token.syntax.kind() == Kind.EOF ?
                           "EOF" : "\"" + subparser.lookahead.token.syntax + "\"")
                        + " at " + subparser.lookahead.token.syntax.getLocation());
        }

        done = true;
        break;

      case SHIFT:
        throw new RuntimeException("fatal: can never shift on EOF");
      }
    } while (! done);
  }

  /** A subparser. */
  public static class Subparser {

    /** The lookahead symbol, either a token or a conditional. **/
    public Lookahead lookahead;
    
    /** The state stack. */
    public StackFrame stack;

    /** The presence condition. */
    public PresenceCondition presenceCondition;

    /** The C typedef/var symbol table. */
    public Actions.Context scope;

    /**
     * Create a new subparser.
     *
     * @param a The next token.
     * @param s The active state stack element.
     * @param presenceCondition The presence condition.
     * @param scope The parsing presenceCondition.
     */
    public Subparser(Lookahead lookahead, StackFrame stack, PresenceCondition presenceCondition,
                     Actions.Context scope) {
      this.lookahead = lookahead;
      this.stack = stack;
      this.presenceCondition = presenceCondition;
      this.scope = scope;
    }

    /**
     * Get the presence condition of the subparser.
     *
     * @return The presence condition.
     */

    public PresenceCondition getPresenceCondition() {
      return presenceCondition;
    }
  }
    
  /** A lookahead token. */
  static class Lookahead {
    /** The token. */
    public OrderedSyntax token;
    
    /** The presenceCondition. */
    public PresenceCondition presenceCondition;
    
    /** The parsing action. */
    private ParsingAction action;
    
    /** The parsing action data. */
    private int actionData;
    
    /**
     * Create a new instance.
     *
     * @param t The token.
     * @param c The presence condition.
     * @param conditional The conditional in which the token is
     * contained.  Used for lazy forking.
     */
    public Lookahead(OrderedSyntax token, PresenceCondition presenceCondition) {
      this.token = token;
      this.presenceCondition = presenceCondition;

      this.clearAction();
    }

    /**
     * Set the parsing action for this next token.
     *
     * @param action The parsing action.
     * @param actionData The parsing action data, i.e. the shift
     * state, reduced production, or the error id.
     */
    public void setAction(ParsingAction action, int actionData) {
      this.action = action;
      this.actionData = actionData;
    }

    /**
     * Clear the parsing action after taking the action.
     */
    public void clearAction() {
      action = ParsingAction.NONE;
      actionData = -1;
    }

    /**
     * Copy the parsing action from another next token.
     *
     * @param The other next token.
     */
    public void copyAction(Lookahead n) {
      this.setAction(n.getAction(), n.getActionData());
    }

    /**
     * Get the parsing action.
     *
     * @return The parsing action.
     * @throws IllegalStateException if the parsing action has not
     * been set yet.
     */
    public ParsingAction getAction() throws IllegalStateException {
      return action;
    }

    /**
     * Get the parsing action data if there is any.  For actions
     * without data, namely ACCEPT, the behavior of this method is
     * undefined.
     *
     * @return The parsing action data.
     * @throws IllegalStateException if the parsing action has not
     * been set yet.
     */
    public int getActionData() throws IllegalStateException {
      return actionData;
    }

    /**
     * Create a string representation.
     *
     * @return The string representation.
     */
    public String toString() {
      return "(" + token.syntax.toString() + ", " + action + ", "
        + actionData + ", " + token.getParentConditional()
        + ", " + presenceCondition
        + ")";
    }

    /**
     * Whether the lookahead is a single token or a set of lookahead
     * token.  Lookahead sets are used to implement shared reductions
     * and lazy forking.
     *
     * @return true if it is a set.
     */
    public boolean isSet() {
      return false;
    }
  }

  static class LookaheadSet extends Lookahead {
    public LinkedList<Lookahead> set;

    public LookaheadSet(OrderedSyntax token, PresenceCondition presenceCondition, ParsingAction action,
                        int actionData) {
      super(token, presenceCondition);

      this.setAction(action, actionData);

      this.set = new LinkedList<Lookahead>();
    }

    /**
     * Add a new lookahead to this set.
     *
     * @param l The new lookahead.
     */
    public void add(Lookahead l) {
      set.add(l);
    }

    public boolean isSet() {
      return true;
    }

    /** Free the BDDs in the set. */
    public void free() {
      for (Lookahead l : set) {
        l.presenceCondition.delRef();
      }
    }

    /**
     * Create a string representation.
     *
     * @return The string representation.
     */
    public String toString() {
      return super.toString() + ":" + set;
    }
  }
    
  /**
   * A syntax object and it's sequence number, buffered in a
   * linked-list so that multiple subparsers can read tokens from the
   * same stream.  It references a stack of nested conditions in order
   * to store the sequence number of the conditional in which each
   * token lies.
   */
  public class OrderedSyntax {
    /** The syntax */
    public final Syntax syntax;
    
    /** The stream from which to pull syntax */
    private final Stream stream;
    
    /** The ordered sequence number */
    private int order;
    
    /** The next ordered token */
    private OrderedSyntax next;

    /**
     * The sequence number of the conditional in which this token
     * lies.
     */
    private int parentConditional;
    
    /**
     * Create a new ordered syntax object.  A call to getNext() on an
     * OrderedSyntax object created with this constructor will return
     * the first token from the stream.
     *
     * @param stream The stream from which to pull new tokens.
     */
    public OrderedSyntax(Stream stream) {
      this(null, 0, 0, stream);

      nestedConditionals.push(0);
    }
    
    /**
     * Create a new ordered syntax object.
     *
     * @param stream The stream from which to pull new tokens.
     * @param syntax The token.
     * @param order The sequence number of the token.
     */
    private OrderedSyntax(Syntax syntax, int order, int parentConditional,
                          Stream stream) {
      this.syntax = syntax; 
      this.order = order;
      this.parentConditional = parentConditional;
      this.stream = stream;
    }

    /**
     * Create a copy of an ordered syntax object using a different
     * syntax object.  This is useful for reclassifying tokens due to
     * parsing presenceCondition.
     *
     * @param newSyntax The new syntax object.
     * @param old The old OrderedSyntax object to duplicate sequence
     * and next token information from.
     * @throws IOException This constructor must call getNext(), which
     * throws IOException.
     */
    public OrderedSyntax(Syntax newSyntax, OrderedSyntax old)
      throws IOException {

      this.stream = old.stream;
      this.syntax = newSyntax;
      this.parentConditional = parentConditional;
      this.order = old.order;

      // Prime the pump, by reading the next token.  This is
      // necessary, because if both the original and the copy of the
      // token have "null" as their next token, they will both call
      // stream.scan(), which will advance the read two tokens ahead.
      // Really they both want the same next token.

      old.getNext();
      this.next = old.next;
    }

    /**
     * Create a copy of this object using a new Syntax object.
     *
     * @param syntax The new syntax object.
     * @return A new OrderedSyntax object.
     * @throws IOException because it calls getNext().
     */
    public OrderedSyntax copy(Syntax syntax) throws IOException {
      return new OrderedSyntax(syntax, this);
    }

    /**
     * Get the next token from the stream and assign it the next
     * sequence number.
     *
     * @return The next token.
     */
    public OrderedSyntax getNext() throws IOException {
      if (null == this.next) {
        this.next = new OrderedSyntax(this.stream.scan(), this.order + 1,
                                      nestedConditionals.peek(), this.stream);

        if (this.next.syntax.kind() == Kind.CONDITIONAL) {
          switch (this.next.syntax.toConditional().tag()) {
          case START:
            nestedConditionals.push(this.next.order);
            this.next.parentConditional = this.next.order;
            break;

          case NEXT:
            break;

          case END:
            nestedConditionals.pop();
            break;
          }
        }
      }
      
      return next;
    }

    /**
     * Get the sequence number of this token.  The token sequence
     * numbers are strictly monotonically increasing from the start of
     * the file to the end.
     *
     * @return The sequence number.
     */
    public int getSequenceNumber() {
      return order;
    }

    /**
     * Get the sequence number of the this token's parent conditional.
     * This method is undefined when the token is a conditonal itself.
     *
     * @return The sequence number of this token's parent conditional.
     */
    public int getParentConditional() {
      return parentConditional;
    }

    /**
     * Get the string representation.
     *
     * @return The string representation.
     */
    public String toString() {
      return this.order + ":" + this.syntax.toString() + this.syntax.getClass();
    }
  }

  /** A frame of the parsing state stack. */
  public static class StackFrame {
    /** The state number */
    public int state;

    /** The semantic value. */
    public Object value;

    /** The symbol id. */
    public int symbol;
    
    /** The next state in the stack */
    public StackFrame next;

    /** The height of the stack.  Maintained internally. */
    private int height;

    /**
     * Make a new state.
     *
     * @param state The state number.
     * @param value The semantic value.
     * @param next The next state stack element in the stack.
     */
    public StackFrame(int state, int symbol, Object value, StackFrame next) {
      this.state = state;
      this.value = value;
      this.symbol = symbol;
      this.next = next;

      if (null == next) {
        height = 1;
      } else {
        height = next.height + 1;
      }
    }
    
    /**
     * Get the ith state down the stack, "1" returning this state.
     *
     * @param i The state to return.
     * @return The ith state down the stack.
     */
    public StackFrame get(int i) {
      StackFrame state;
      
      state = this;
      
      while (i > 1) {
        state = state.next;
        i--;
      }
      
      return state;
    }

    /**
     * Get the height of the stack.
     *
     * @return The height.
     */
    public int getHeight() {
      assert checkHeight() == height;

      return height;
    }

    /**
     * Check the height of the stack by following the links.
     *
     * @return The height.
     */
    private int checkHeight() {
      int h = 0;
      StackFrame s = this;

      while (null != s) {
        h++;
        s = s.next;
      }

      return h;
    }

    /**
     * Recursively merge the semantic values from the given state
     * stack into this state stack.  The number of elements to merge
     * is controlled by the dist parameter.  This method assumes that
     * this stack's semantic values are already CHOICE_NODE_NAME nodes.
     *
     * This version is inefficient in that shared semantics values
     * from shared stack elements get referenced twice.
     *
     * @param other The other state stack.
     * @param otherPresenceCondition the presenceCondition of the other state stack's
     * semantic value.
     * @param dist The distance down the stack to merge.
     */
    public void merge(PresenceCondition thisPresenceCondition, StackFrame other,
                      PresenceCondition otherPresenceCondition, int dist) {
      if (dist == 0) return;

      int flags
        = (null != this.value ? 1 : 0)
        | (null != other.value ? 2 : 0);

      switch (flags) {
      case 0:
        // Both are null.  Do nothing.
        break;

      case 1:
        // other.value is null, but this.value is not.  There is
        // nothing to add to this semantic value, so do nothing.
        break;

      case 2:
        // this.value is null, but other.value is not.  Create a new
        // conditional to store the non-null other.value and its
        // presence condition.

        GNode conditionalNode = GNode.create(CHOICE_NODE_NAME);

        conditionalNode.add(otherPresenceCondition.addRef());
        conditionalNode.add(other.value);

        this.value = conditionalNode;
        break;

      case 3:
        // Neither are null.  Add other.value and its presence
        // condition.

        if (this.value == other.value) {

          // Both are already pointing to the same list node.  Don't
          // create a conditional.

        } else if (! ((Node) this.value).getName().equals(CHOICE_NODE_NAME)) {

          // Combine the two value, this and other, into a choice
          // node.

          GNode cnode = GNode.create(CHOICE_NODE_NAME);

          cnode.add(thisPresenceCondition.addRef());
          cnode.add(this.value);
          cnode.add(otherPresenceCondition.addRef());
          cnode.add(other.value);
          this.value = cnode;

        } else {

          // This value is already a conditional, so just add the
          // other value.

          ((Node) this.value).add(otherPresenceCondition.addRef());
          ((Node) this.value).add(other.value);
        }

        break;

      }
      
      if (this.next != null) {
        this.next.merge(thisPresenceCondition, other.next, otherPresenceCondition, dist - 1);
      }
    }
    
    /**
     * Get the string representation.
     *
     * @return The string representation.
     */
    public String toString() {
      return value + ":" + next;
    }

    /**
     * Check whether this parsing state can merge with another.
v     *
     * @param other The other parsing state.
     * @return true if it can merge with this state.
     */
    public boolean isMergeable(StackFrame other) {
      return isMergeable(this, other);
    }

    /**
     * Check whether two parsing state can merge.
     *
     * @param s The first parsing state.
     * @param t The second parsing state.
     * @return true if they can merge.
     */
    private static boolean isMergeable(StackFrame s, StackFrame t) {
      if (s == t) {
        return true;
      } else if (s == null || t == null) {
        return false;
      } else if (s.state != t.state) {
        return false;
      } else {
        return isMergeable(s.next, t.next);
      }
    }
  }

  /**
   * Determine whether a token is parseable.  The only parseable
   * tokens are Language tokens and EOF.
   *
   * @param syntax The syntax to test for parseability.
   * @return true if the syntax is a Language or EOF token.
   */
  public static boolean isParseable(Syntax syntax) {
    return syntax.kind() == Kind.LANGUAGE || syntax.kind() == Kind.EOF;
  }
}
