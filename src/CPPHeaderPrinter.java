import xtc.tree.GNode;
import xtc.tree.Node;
import xtc.tree.Printer;
import xtc.tree.Visitor;

/** Naive C++ Header Printer based off the JavaAST.
 *  (C) Shady Gabal, Stephen Hu, Enrique Lores, Brandon Mazey, William Neville, Doris Tang
 */
public class CPPHeaderPrinter extends Visitor
{
  private Printer out; //The printer
 
  /** Constructor - takes a Printer
   * @param p Printer that will print C++ code off of JavaAST nodes
   */
  public CPPHeaderPrinter(Printer p)
  {
    out = p;
  }

  /** visit - Visit the nodes of the tree
   * @param n The node to begin visiting from (i.e. root)
   */
  public void visit(Node n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  /** visitClassDeclaration - Visit a Class Declaration GNode
   * @param n the GNode
   */
  public void visitClassDeclaration(GNode n)
  {
    out.indent();

    //dispatch((Node) n.get(0)); // Print modifiers

    out.pln("struct __" + n.getString(1) + ";"); // Print class declaration
/*
    out.indent();
    out.pln("{");

    out.incr();

    dispatch((Node) n.get(5)); // Dispatch into the class body

    out.decr();

    out.indent();
    out.pln("};");
*/
    out.indent();
    out.p("struct __");
    out.p(n.getString(1));
    out.pln("_VT;");
    out.pln();
  }

  /** visitCompilationUnit - Visit a Compilation Unit GNode
   * @param n the GNode
   */
  public void visitCompilationUnit(GNode n)
  {
    out.indent();
    out.pln("#include <iostream>");
    out.indent();
    out.pln("#include \"java_lang.cc\"");
    out.indent();
    out.pln("#include \"ptr.h\"");
    out.pln();
    out.indent();
    out.pln("using namespace std;");
    out.indent();
    out.pln("using namespace java::lang;");
    out.pln();

    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }

    out.flush();
  }

  /** visitConstructorDeclaration - Visit a Constructor Declaration GNode
   * @param n the GNode
   */
  public void visitConstructorDeclaration(GNode n)
  {
    out.indent();

    // dispatch((Node) n.get(0)); // Print modifiers

    out.p(n.getString(2));
    out.p("(");

    dispatch((Node) n.get(3)); // Print the parameters

    out.pln(");");
  }

  /** visitDeclarator - Visit a Declarator GNode
   * @param n the GNode
   */
  public void visitDeclarator(GNode n)
  {
    out.p(n.getString(0));
  }

  /** visitDeclarators - Visit multiple Delcarator GNodes
   * @param n the GNode (root of declarators)
   */
  public void visitDeclarators(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  /** visitFieldDeclaration - Visit a Field Declaration Node
   * @param n the GNode
   */
  public void visitFieldDeclaration(GNode n)
  {
    out.indent();
    // dispatch((Node) n.get(0)); // Print modifiers

    dispatch((Node) n.get(1)); // Print data type

    out.p(" ");

    dispatch((Node) n.get(2)); // Print variable names

    out.pln(";");
  }

  /** visitFormalParamter - Visit a Formal Parameter Node
   * @param n the GNode
   */
  public void visitFormalParameter(GNode n)
  {
    // Print modifiers
    for(Object c : ((Node) n.get(0)))
    {
      if(c != null && c instanceof Node)
      {
        out.p(((Node) c).getString(0) + " ");
      }
    }

    dispatch((Node) n.get(1)); // Print the type of the parameter

    out.p(" ");
    out.p(n.getString(3)); // Print parameter name
  }
  
  /** visitFormalParamters - Visit a multiple Formal Parameter Nodes
   * @param n the GNode (Root)
   */
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
  
  /** visitMethodDeclaration - Visit a Method Declaration Node
   * @param n the GNode
   */
  public void visitMethodDeclaration(GNode n)
  {
    if(!n.getString(3).equals("main"))
    {
      out.indent();

      // dispatch((Node) n.get(0)); // Print modifiers

      dispatch((Node) n.get(2)); // Print return type

      out.p(" ");
      out.p(n.getString(3));
      out.p("(");

      dispatch((Node) n.get(4)); // Print the parameters

      out.pln(");");
    }
  }

  /** visitModifier - Visit a Modifier Node
   * @param n the GNode
   */
  public void visitModifier(GNode n)
  {
    out.p(n.getString(0) + " ");
  }

  /** visitModifiers - Visit multiple Modifier Nodes
   * @param n the GNode (root)
   */
  public void visitModifiers(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
        dispatch((Node) c);
    }
  }

  /** visitPrimitiveType - Visit a Primitive Type Node
   * @param n the GNode
   */
  public void visitPrimitiveType(GNode n)
  {
    if(n.getString(0).equals("boolean"))
      out.p("bool");
    else out.p(n.getString(0));
  }

  /** visitQualifiedIdentifier - Visit a Qualified Identifier Node
   * @param n the GNode
   */ 
  public void visitQualifiedIdentifier(GNode n)
  {
    out.p(n.getString(0));
  }
  
  /** visitType - Visit a Type Node, begin dispatching.
   * @param n the GNode (Root)
   */
  public void visitType(GNode n)
  {
    for(Object c : n)
    {
      if(c != null && c instanceof Node)
      {
        dispatch((Node) c);
      }
    }
  }

  /** visitVoidType - Visit a Void Type Node
   * @param n the GNode
   */
  public void visitVoidType(GNode n)
  {
    out.p("void");
  }
}
