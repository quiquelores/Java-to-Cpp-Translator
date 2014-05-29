import xtc.tree.GNode;
import xtc.tree.Node;
import xtc.tree.Printer;
import xtc.tree.Visitor;

/*
 *  C++ TypeDef Printer
 *  - Based off of Java AST
 *
 */
public class CPPTypeDefPrinter extends Visitor
{
  private Printer out;

  public CPPTypeDefPrinter(Printer p)
  {
    out = p;
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

  public void visitClassDeclaration(GNode n)
  {
    String className = n.getString(1);

    out.indent();
    out.pln("typedef __rt::Ptr<__" + className + ", __rt::object_policy> " + className + ";");
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
    out.flush();
  }
}
