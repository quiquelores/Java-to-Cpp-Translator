import java.util.ArrayList;

import xtc.tree.GNode;
import xtc.tree.Node;
import xtc.tree.Printer;
import xtc.tree.Visitor;

/*
 *  Naive C++ Source Printer
 *  - Based off of Java AST
 *
 *  * Only allows one-dimensional arrays
 *  * Need to incorporate modifiers (private, static, final, etc.)
 *
 */
public class CPPPrinter extends Visitor
{
  protected static Printer out = null;

  private int printCode = 0;
  // 0 = nothing found
  // 1 = reference to some out member found
  // 2 = reference to System.out found => rewrite the print or println statement and reset printCode to 0

  private int dimensions = 0; // Dimension of array (for array variable declaration)

  private boolean printMain = false; // Whether or not to print main methods
  private boolean hasDefaultConstructor = false; // Whether or not the current class creates its own default constructor

  private String inClass = null; // What class you are in
  private String className = null; // Standard Java class name
  private ClassNode currClass = null; // ClassNode of the current class

  private boolean inMethod = false; // If you are currently in a method
  private ArrayList<String> localVars = null; // List of local variables within a method (including parameters)
  // FIXME: Allow for multiple scopes (i.e. Methods in methods)

  private String qualifiedId = null; // If the previously retrieved type was a qualified identifier, this contains the data type.  Otherwise, this contains null.

  private ClassTree classes = null; // Class tree, to be retrieved from CPPClassPrinter, if necessary

  private String mainClass; // The name of the main class in the Java program

  private boolean isStatic = false; // If there is a static modifier

  private boolean inConstructor = false; // If you are printing a constructor
  private boolean inInitializer = false; // If you are printing an initializer

  public CPPPrinter(Printer p)
  {
    out = p;
  }

  public CPPPrinter(Printer p, String mc)
  {
    out = p;
    mainClass = mc;
  }

  public CPPPrinter(Printer p, String mc, ClassTree c)
  {
    out = p;
    mainClass = mc;
    classes = c;
  }

  // Move along, nothing to see here
  public void visit(Node n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  public void visitAdditiveExpression(GNode n)
  {
    dispatch((Node) n.get(0)); // Print first value

    out.p(" " + n.getString(1) + " ");

    dispatch((Node) n.get(2)); // Print second value
  }

  public void visitArguments(GNode n)
  {
    Node nextArg = null;

    for(Object c : n)
    {
      if(c != null && c instanceof Node)
      {
        if(nextArg != null)
        {
          dispatch(nextArg);

          // Insert commas between arguments
          out.p(", ");
        }

        nextArg = (Node) c;
      }
    }

    if(nextArg != null)
    {
      dispatch(nextArg);
    }
  }

  public void visitBasicCastExpression(GNode n)
  {
    out.p("(");
    dispatch((Node) n.get(0)); // Print type to be casted into
    out.p(")");

    out.p(" (");
    dispatch((Node) n.get(2)); // Print what is to be casted
    out.p(")");
  }

  public void visitBasicForControl(GNode n)
  {
    // Dispatch declarations of for loop
    dispatch((Node) n.get(0));
    dispatch((Node) n.get(1));

    out.p(" ");

    dispatch((Node) n.get(2));

    out.p("; ");

    dispatch((Node) n.get(3)); // Dispatch conditionals of for loop

    out.p("; ");

    dispatch((Node) n.get(4)); // Dispatch updates of for loop
  }

  public void visitBlock(GNode n)
  {
    out.indent();
    out.pln("{");
    out.incr();

    if(inConstructor)
    {
      out.indent();
      out.pln("__" + currClass.getSuperclass() + "::init((__" + currClass.getSuperclass() + "*) this);");
    }

    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }

    out.decr();
    out.indent();
    out.pln("}");
  }

  public void visitBooleanLiteral(GNode n)
  {
    out.p(n.getString(0));
  }

  public void visitBreakStatement(GNode n)
  {
    out.indent();
    out.p("break");

    if(n.get(0) != null)
      out.p(" " + n.getString(0));

    out.pln(";");
  }

  public void visitCallExpression(GNode n)
  {
    printCode = 0;

    dispatch((Node) n.get(0)); // Print the object whose method is being called

    if(printCode == 2)
    {
      printCode = 0;

      if(n.getString(2).equals("print"))
      {
        out.p("cout << ");

        dispatch((Node) n.get(3)); // Print the value to be printed
        // FIXME: Allow printing even when toString() is never called for an object
      }
      else if(n.getString(2).equals("println"))
      {
        out.p("cout << ");

        dispatch((Node) n.get(3)); // Print the value to be printed

        out.p(" << endl");
        // FIXME: Allow printing even when toString() is never called for an object
      }
      else // Other System.out calls not supported
      {
        out.p("System->out->");
        out.p(n.getString(2));
        out.p("(");

        dispatch((Node) n.get(3)); // Print the arguments

        out.p(")");
      }
    }
    else
    {
      out.p("->__vptr->");
      out.p(n.getString(2));
      out.p("(");

      dispatch((Node) n.get(0)); // Print the object whose method is being called (FIXME: What about static functions?)

      Node args = (Node) n.get(3);

      if(args.size() > 0) // Print comma only if there are other parameters
        out.p(", ");

      dispatch((Node) n.get(3)); // Print the arguments

      out.p(")");
    }
  }

  public void visitCaseClause(GNode n)
  {
    out.indent();
    out.p("case ");

    dispatch((Node) n.get(0)); // Print case value

    out.pln(":");
    out.incr();

    for(int i = 1; i < n.size(); i++)
    {
      dispatch((Node) n.get(i)); // Dispatch into case code
    }

    out.decr();
  }

  public void visitCatchClause(GNode n)
  {
    out.indent();
    out.p("catch(");

    dispatch((Node) n.get(0)); // Print exception to be caught

    out.pln(")");

    dispatch((Node) n.get(1)); // Dispatch into catch block
  }

  public void visitClassBody(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  public void visitClassDeclaration(GNode n)
  {
    out.indent();

    // dispatch((Node) n.get(0)); // Check modifiers

    className = n.getString(1);
    inClass = "__" + className;
    currClass = classes.findClass(className); // Find the ClassNode for this class in the ClassTree

    hasDefaultConstructor = false;

    dispatch((Node) n.get(5)); // Dispatch into the class body

    if(!hasDefaultConstructor)
    {
      out.pln();
      out.indent();
      out.pln(inClass + "::" + inClass + "() : __vptr(&__vtable)");
      out.indent();
      out.pln("{");
      out.indent();
      out.pln("}");
    }

    inInitializer = true;

    out.pln();
    out.indent();
    out.pln(inClass + "* " + inClass + "::init(" + inClass + "* __this)");
    out.indent();
    out.pln("{");
    out.incr();

    out.indent();
    out.pln("__" + currClass.getSuperclass() + "::init((__" + currClass.getSuperclass() + "*) __this);");
    out.pln();

    if(currClass.hasDefaultConstructor())
    {
      Node constructorBlock = (Node) currClass.getDefaultConstructor().get(5);

      for(Object c : constructorBlock)
      {
        if(c != null && c instanceof Node)
          dispatch((Node) c);
      }
    }

    out.indent();
    out.pln("return __this;");

    out.decr();
    out.indent();
    out.pln("}");

    inInitializer = false;

    out.pln();

    out.indent();
    out.pln(inClass + "_VT " + inClass + "::__vtable;");

    className = null;
    inClass = null;
    currClass = null;
  }

  public void visitCompilationUnit(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }

    out.pln();
    out.pln();

    out.indent();
    out.pln("int main(int argc, char* argv[])");
    out.indent();
    out.pln("{");

    out.incr();
    out.indent();
    out.pln("__rt::Ptr<__rt::Array<String> > args = new __rt::Array<String>(argc - 1);");
    out.indent();
    out.pln("for (int32_t i = 1; i < argc; i++)");
    out.indent();
    out.pln("{");

    out.incr();
    out.indent();
    out.pln("(*args)[i - 1] = __rt::literal(argv[i]);");

    out.decr();
    out.indent();
    out.pln("}");
    out.indent();
    out.pln("__" + mainClass + "::main(args);");
    out.indent();
    out.pln("return 0;");

    out.decr();
    out.indent();
    out.pln("}");

    out.flush();
  }

  public void visitConcreteDimensions(GNode n)
  {
    dispatch((Node) n.get(0)); // FIXME: Only allowing one dimension for now
  }

  public void visitConditionalStatement(GNode n)
  {
    out.indent();
    out.p("if(");

    dispatch((Node) n.get(0)); // Print condition

    out.pln(")");

    dispatch((Node) n.get(1)); // dispatch into if statement

    if(n.get(2) != null)
    {
      out.indent();
      out.pln("else");

      dispatch((Node) n.get(2)); // dispatch into else statement
    }
  }

  public void visitConstructorDeclaration(GNode n)
  {
    inConstructor = true;

    out.indent();

    // dispatch((Node) n.get(0)); // Check modifiers

    out.p(inClass + "::" + inClass + "(");

    if(((Node) n.get(3)).size() == 0)
      hasDefaultConstructor = true;

    dispatch((Node) n.get(3)); // Print the parameters

    out.p(") : __vptr(&__vtable)");

    for(ClassMember cm : currClass.getMembers())
    {
      if(cm.hasInitialization())
        out.p(", " + cm.getName() + "(" + cm.getInitialization() + ")");
    }

    out.pln();

    dispatch((Node) n.get(5));

    inConstructor = false;
  }

  public void visitDeclarator(GNode n)
  {
    out.p(n.getString(0)); // Finish printing declaration

    if(localVars != null)
      localVars.add(n.getString(0));

    // If it exists, print the initialization
    if(n.get(2) != null && n.get(2) instanceof Node)
    {
      out.pln(";");

      if(qualifiedId != null && !((Node) n.get(2)).hasName("NewClassExpression"))
      {
        out.indent();
        out.p("if(__" + qualifiedId + "::__class()->__vptr->isInstance(__" + qualifiedId + "::__class(), (Object) ");
        dispatch((Node) n.get(2));
        out.pln("))");

        out.incr();

        out.indent();
        out.p(n.getString(0));
        out.p(" = (" + qualifiedId + ") ");

        dispatch((Node) n.get(2));

        out.pln(";");

        out.decr();

        out.indent();
        out.p("else throw new ClassCastException()");
      }
      else
      {
        out.indent();
        out.p(n.getString(0));
        out.p(" = ");

        dispatch((Node) n.get(2));
      }
    }
  }

  public void visitDeclarators(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  public void visitDefaultClause(GNode n)
  {
    out.indent();
    out.pln("default:");
    out.incr();

    for(int i = 1; i < n.size(); i++)
    {
      dispatch((Node) n.get(i)); // Dispatch into case code
    }

    out.decr();
  }

  public void visitDimensions(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof String)
        dimensions++;
    }
  }

  public void visitDoWhileStatement(GNode n)
  {
    out.indent();
    out.pln("do");

    dispatch((Node) n.get(0)); // Print the body of the do-while statement

    out.indent();
    out.p("while(");

    dispatch((Node) n.get(1)); // Print the condition of the do-while statement

    out.pln(");");
  }

  public void visitEqualityExpression(GNode n)
  {
    dispatch((Node) n.get(0)); // Print first value

    out.p(" " + n.getString(1) + " ");

    dispatch((Node) n.get(2)); // Print second value
  }

  public void visitExpression(GNode n)
  {
    dispatch((Node) n.get(0)); // Print first value

    out.p(" " + n.getString(1) + " ");

    dispatch((Node) n.get(2)); // Print second value
  }

  public void visitExpressionList(GNode n)
  {
    Node nextExp = null;

    for(Object c : n)
    {
      if(c != null && c instanceof Node)
      {
        if(nextExp != null)
        {
          dispatch(nextExp);

          // Insert commas between expressions
          out.p(", ");
        }

        nextExp = (Node) c;
      }
    }

    if(nextExp != null)
    {
      dispatch(nextExp);
    }
  }

  public void visitExpressionStatement(GNode n)
  {
    printArrayChecks(n);

    out.indent();

    dispatch((Node) n.get(0)); // Print the expression

    out.pln(";");
  }

  public void visitFieldDeclaration(GNode n)
  {
    if(inClass == null || inMethod)
    {
      out.indent();
      // dispatch((Node) n.get(0)); // Check modifiers

      dispatch((Node) n.get(1)); // Print data type

      out.p(" ");

      dispatch((Node) n.get(2)); // Print variable names

      out.pln(";");
    }
  }

  public void visitFormalParameter(GNode n)
  {
    /* Print modifiers
    for(Object c : ((Node) n.get(0)))
    {
      if(c != null && c instanceof Node)
      {
        out.p(((Node) c).getString(0) + " ");
      }
    }
    */

    dispatch((Node) n.get(1)); // Print the type of the parameter

    out.p(" ");
    out.p(n.getString(3)); // Print parameter name

    if(localVars != null)
      localVars.add(n.getString(3));
  }

  public void visitFormalParameters(GNode n)
  {
    Node nextParam = null;

    for(Object c : n)
    {
      if(c != null && c instanceof Node)
      {
        if(nextParam != null)
        {
          dispatch(nextParam);

          // Insert commas between parameters
          out.p(", ");
        }

        nextParam = (Node) c;
      }
    }

    if(nextParam != null)
    {
      dispatch(nextParam);
    }
  }

  public void visitForStatement(GNode n)
  {
    out.indent();
    out.p("for(");

    dispatch((Node) n.get(0)); // Print internal of for loop

    out.pln(")");

    dispatch((Node) n.get(1)); // Dispatch the loop
  }

  public void visitIntegerLiteral(GNode n)
  {
    out.p(n.getString(0));
  }

  public void visitMethodDeclaration(GNode n)
  {
    inMethod = true;
    localVars = new ArrayList<String>();

    out.indent();

    dispatch((Node) n.get(0)); // Check modifiers

    dispatch((Node) n.get(2)); // Print return type

    out.p(" " + inClass + "::" + n.getString(3) + "(");

    if(!isStatic)
    {
      out.p(className + " __this");

      if(((Node) n.get(4)).size() > 0)
        out.p(", ");
    }

    dispatch((Node) n.get(4)); // Print the parameters

    out.pln(")");

    dispatch((Node) n.get(7)); // Dispatch into method

    localVars = null;

    isStatic = false;
  }

  public void visitModifier(GNode n)
  {
    if(n.getString(0).equals("static"))
      isStatic = true;
  }

  public void visitModifiers(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  public void visitMultiplicativeExpression(GNode n)
  {
    dispatch((Node) n.get(0)); // Print first value

    out.p(" " + n.getString(1) + " ");

    dispatch((Node) n.get(2)); // Print second value
  }

  public void visitNewArrayExpression(GNode n)
  { // FIXME:  Make multi-dimensional arrays work
    out.p("new __rt::Array<");

    dispatch((Node) n.get(0)); // Print array type

    out.p(">(");

    dispatch((Node) n.get(1)); // Print array size

    out.p(")");
  }

  public void visitNewClassExpression(GNode n)
  {
    out.p("new __");

    dispatch((Node) n.get(2)); // Print class name

    out.p("(");

    dispatch((Node) n.get(3)); // Print arguments

    out.p(")");
  }

  public void visitPostfixExpression(GNode n)
  {
    dispatch((Node) n.get(0)); // Print variable

    out.p(n.getString(1)); // Print postfix operator
  }

  public void visitPrimaryIdentifier(GNode n)
  {
    if(printCode == 1 && n.getString(0).equals("System"))
      printCode = 2;
    else if((inClass != null && inMethod && !localVars.contains(n.getString(0))) || inInitializer)
      out.p("__this->" + n.getString(0));
    else out.p(n.getString(0));
  }

  public void visitPrimitiveType(GNode n)
  {
    if(n.getString(0).equals("boolean"))
      out.p("bool");
    else out.p(n.getString(0));
  }

  public void visitQualifiedIdentifier(GNode n)
  {
    qualifiedId = n.getString(0);

    out.p(n.getString(0));
  }

  public void visitRelationalExpression(GNode n)
  {
    dispatch((Node) n.get(0)); // Print first term

    out.p(" " + n.getString(1) + " ");

    dispatch((Node) n.get(2)); // Print second term
  }

  public void visitReturnStatement(GNode n)
  {
    out.indent();
    out.p("return ");

    dispatch((Node) n.get(0)); // Print value

    out.pln(";");
  }

  public void visitSelectionExpression(GNode n)
  {
    if(n.getString(1).equals("out"))
      printCode = 1;

    dispatch((Node) n.get(0));

    if(printCode < 2)
    {
      out.p("->");
      out.p(n.getString(1));
    }
  }

  public void visitStringLiteral(GNode n)
  {
    out.p("__rt::literal(");
    out.p(n.getString(0));
    out.p(")");
  }

  public void visitSubscriptExpression(GNode n)
  { // Assumes subscript is for an array access
    // Need to do array notNull and index within bounds checks before entering here

    dispatch((Node) n.get(0)); // Print variable name

    out.p("->__data[");

    dispatch((Node) n.get(1)); // Print index

    out.p("]");
  }

  public void visitSwitchStatement(GNode n)
  {
    out.indent();
    out.p("switch(");

    dispatch((Node) n.get(0)); // Print the value of the switch

    out.pln(")");

    out.indent();
    out.pln("{");
    out.incr();

    for(int i = 1; i < n.size(); i++)
    {
      if(n.get(i) != null && n.get(i) instanceof Node)
        dispatch((Node) n.get(i)); // Print case statements

    }

    out.decr();
    out.indent();
    out.pln("}");
  }

  public void visitThisExpression(GNode n)
  {
    out.p("this");
  }

  public void visitTryCatchFinallyStatement(GNode n)
  {
    out.indent();
    out.pln("try");

    dispatch((Node) n.get(1)); // Dispatch into try statement

    if(n.get(2) != null) // Dispatch into catch statement if it exists
      dispatch((Node) n.get(2));

    if(n.get(3) != null) // Dispatch into finally statement if it exists
    {
      out.indent();
      out.pln("finally");

      dispatch((Node) n.get(3));
    }
  }

  public void visitType(GNode n)
  {
    qualifiedId = null; // Reset variable

    int i;

    if(n.get(1) != null && n.get(1) instanceof Node) // Check if this is an array
    {
      dimensions = 0;

      dispatch((Node) n.get(1)); // If it is, find the number of dimensions
    }

    if(dimensions > 0)
    {
      for(i = 0; i < dimensions; i++)
      {
        out.p("__rt::Ptr<__rt::Array<");
      }
    }

    dispatch((Node) n.get(0));

    if(dimensions > 0)
    {
      for(i = 0; i < dimensions; i++)
      {
        out.p(">, __rt::array_policy>");

        if(i < dimensions - 1)
          out.p(" ");
      }

      dimensions = 0;
    }
  }

  public void visitVoidType(GNode n)
  {
    out.p("void");
  }

  public void visitWhileStatement(GNode n)
  {
     out.indent();
     out.p("while(");

     dispatch((Node) n.get(0)); // Print condition

     out.pln(")");

     dispatch((Node) n.get(1)); // Dispatch into loop
  }

  protected void printArrayChecks(GNode n)
  {
    new Visitor()
    {
      public void visit(Node n)
      {
        for(Object c : n)
        {
          if(c != null && c instanceof Node)
            dispatch((Node) c);
        }
      }

      public void visitSubscriptExpression(GNode n)
      {
        out.indent();
        out.p("__rt::checkNotNull(");
        out.p(((Node) n.get(0)).getString(0));
        out.pln(");");

        out.indent();
        out.p("__rt::checkIndex(");
        out.p(((Node) n.get(0)).getString(0) + ", " + ((Node) n.get(1)).getString(0));
        out.pln(");");
      }
    }.dispatch(n);
  }
}
