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

import java.lang.*;

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;

import java.util.HashSet;
import java.util.HashMap;

/**
 * This class generates a base class for semantic actions for a
 * grammar.  It takes "name, type" pairs from the standard input.
 *
 * @author Paul Gazzillo
 * @version $Revision: 1.12 $
 */
public class ActionGenerator {
  public static void main(String args[]) throws Exception {
    BufferedReader inputStream = null;
    PrintWriter outputStream = null;

    if (args.length != 1) {
      System.err.println("Please specify a class name.");
      System.exit(1);
    }

    String className = args[0];
    
    try {
      String l;
      HashSet<Integer> list;
      HashMap<Integer, String> action;
      HashSet<Integer> layout;
      HashSet<Integer> passthrough;
      HashSet<Integer> complete;

      outputStream = new PrintWriter(System.out);
      
      outputStream.print("" +
"/*\n" +
" * xtc - The eXTensible Compiler\n" +
" * Copyright (C) 2009-2012 New York University\n" +
" *\n" +
" * This program is free software; you can redistribute it and/or\n" +
" * modify it under the terms of the GNU General Public License\n" +
" * version 2 as published by the Free Software Foundation.\n" +
" *\n" +
" * This program is distributed in the hope that it will be useful,\n" +
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n" +
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" +
" * GNU General Public License for more details.\n" +
" *\n" +
" * You should have received a copy of the GNU General Public License\n" +
" * along with this program; if not, write to the Free Software\n" +
" * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,\n" +
" * USA.\n" +
" */\n" +
"package xtc.lang.cpp;\n" + 
"\n" +  
"import xtc.lang.cpp.ForkMergeParser.Subparser;\n" +  
"\n" +  
"/**\n" +
" * This class is generated from grammar annotations and provides semantic\n" +
" * value and action support.\n" +
" */\n"
                         );
      inputStream = new BufferedReader(new InputStreamReader(System.in));

      list = new HashSet<Integer>();
      layout = new HashSet<Integer>();
      action = new HashMap<Integer, String>();
      passthrough = new HashSet<Integer>();
      complete = new HashSet<Integer>();
      while ((l = inputStream.readLine()) != null) {
        String[] a = l.split(" ");
        String name = a[0];
        String type = a[1];
        int sym = -1;
        
        for (int i = 0; i < ForkMergeParserTables.yytname.table.length; i++) {
          if (ForkMergeParserTables.yytname.table[i].equals(name)) {
            sym = i;
            break;
          }
        }
        
        if (sym >= 0) {
          if (type.equals("list")) {
            list.add(sym);
          } else if (type.equals("layout")) {
            layout.add(sym);
          } else if (type.equals("action")) {
            action.put(sym, name);
          } else if (type.equals("passthrough")) {
            passthrough.add(sym);
          } else if (type.equals("complete")) {
            complete.add(sym);
          } else {
            System.err.println("error: node " + name + " has unknown " +
              "type " + type);
          }
        } else {
          System.err.println("error: there is no node " + name + " in the " +
            "grammar");
        }
      }

      boolean isAbstract = false;
      if (action.size() > 0) {
        // Then this class an abstract one that needs to be
        // overridden.
        isAbstract = true;
      }

      outputStream.print("" +
"public" + (isAbstract ? " abstract" : "") + " class " + className +
" extends Actions {\n" +
"\n"
                         );


      outputStream.print("" + 
"  public ValueType getValueType(int id) {\n");

      // Find out the ranges [0,frontStreak) and (backStreak,SIZE)
      // where production id is the default NODE types.
      int frontStreak, backStreak;

      for (frontStreak = 0;
           frontStreak < ForkMergeParserTables.yytname.table.length
             && ! list.contains(frontStreak)
             && ! layout.contains(frontStreak)
             && ! action.containsKey(frontStreak)
             && ! passthrough.contains(frontStreak);
           frontStreak++);

      for (backStreak = ForkMergeParserTables.yytname.table.length - 1;
           backStreak >= 0
             && ! list.contains(backStreak)
             && ! layout.contains(backStreak)
             && ! action.containsKey(backStreak)
             && ! passthrough.contains(backStreak);
           backStreak--);

      outputStream.print("" +
"    if (0 <= id && id < " + frontStreak);
      if (backStreak < ForkMergeParserTables.yytname.table.length - 1) {
        outputStream.print("" +
" || " + backStreak + " < id");
      }

      outputStream.print("" +
") {\n" +
"      return ValueType.NODE;\n" +
"    }\n");

      int c; // Used to emit return statement;

      outputStream.print("" +
"    switch (id - " + frontStreak + ") {\n");
      c = 0;
      for (int i = 0; i < ForkMergeParserTables.yytname.table.length; i++) {
        if (list.contains(i)) {
          outputStream.print("" +
"      case " + (i - frontStreak) + ": // " + ForkMergeParserTables.yytname.table[i] + " (" + i + ")\n");
          if (c < list.size() - 1) {
          outputStream.print("" +
"        // Fall through\n");
          } else {
          outputStream.print("" +
"        return ValueType.LIST;\n\n");
          }
          c++;
        }
      }

      c = 0;
      for (int i = 0; i < ForkMergeParserTables.yytname.table.length; i++) {
        if (layout.contains(i)) {
          outputStream.print("" +
"      case " + (i - frontStreak) + ": // " + ForkMergeParserTables.yytname.table[i] + " (" + i + ")\n");
          if (c < layout.size() - 1) {
          outputStream.print("" +
"        // Fall through\n");
          } else {
          outputStream.print("" +
"        return ValueType.LAYOUT;\n\n");
          }
          c++;
        }
      }

      c = 0;
      for (int i = 0; i < ForkMergeParserTables.yytname.table.length; i++) {
        if (action.containsKey(i)) {
          outputStream.print("" +
"      case " + (i - frontStreak) + ": // " + ForkMergeParserTables.yytname.table[i] + " (" + i + ")\n");
          if (c < action.keySet().size() - 1) {
          outputStream.print("" +
"        // Fall through\n");
          } else {
          outputStream.print("" +
"        return ValueType.ACTION;\n\n");
          }
          c++;
        }
      }

      c = 0;
      for (int i = 0; i < ForkMergeParserTables.yytname.table.length; i++) {
        if (passthrough.contains(i)) {
          outputStream.print("" +
"      case " + (i - frontStreak) + ": // " + ForkMergeParserTables.yytname.table[i] + " (" + i + ")\n");
          if (c < passthrough.size() - 1) {
            outputStream.print("" +
"        // Fall through\n");
          } else {
            outputStream.print("" +
"        return ValueType.PASS_THROUGH;\n\n");
          }
          c++;
        }
      }
      outputStream.print("" +
"      default:\n" +
"        return ValueType.NODE;\n" +
"    }\n" +
"  }\n");

      outputStream.print("" + 
"  public boolean isComplete(int id) {\n" +
"    switch(id) {\n");
      c = 0;
      for (Integer i : complete) {
        outputStream.print("" +
"    case " + i + ": " + "// " + ForkMergeParserTables.yytname.table[i] + "\n");
        if (c < complete.size() - 1) {
          outputStream.print("" +
"      // Fall through\n");
        } else {
          outputStream.print("" +
"      return true;\n\n"); 
        }
        c++;
      }
      outputStream.print("" +
"    default:\n" +
"      return false;\n" +
"    }\n" +
"  }\n" +
"\n");

      if (action.size() > 0) {
        outputStream.print("" + 
"  public void dispatch(int id, Subparser subparser) {\n" +
"    switch(id) {\n");
        for (Integer i : action.keySet()) {
          String name = action.get(i);
        
          outputStream.print("" +
"    case " + i + ":\n" +
"      " + name + "(subparser);\n" +
"      break;\n\n"); 
        }
        outputStream.print("" +
"    default:\n" +
"      // Do nothing\n" +
"      break;\n" +
"    }\n" +
"  }\n" +
"\n");

        for (Integer i : action.keySet()) {
          outputStream.print("" +
"  public abstract void " + action.get(i) + "(Subparser subparser);\n\n"); 
        }
      }

      outputStream.print("" + 
"}\n");

    } catch (Exception e) {
      e.printStackTrace();

    } finally {

      if (inputStream != null) {
          inputStream.close();
      }

      if (outputStream != null) {
          outputStream.close();
      }
    }
    
  }
}
