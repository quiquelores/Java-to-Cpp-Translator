import java.util.ArrayList;

import xtc.tree.Printer;
import xtc.tree.Node;

public class ClassNode implements Comparable<String>
{
  private String name;
  private ArrayList<ClassMethod> methods;
  private ArrayList<ClassMember> members; // TODO: Add code so that you can initialization a data member on declaration
  private ArrayList<ArrayList<ClassParameter>> constructors;
  private Node defaultConstructor = null;

  private ArrayList<ClassNode> children;

  private String superclass;
  private ClassNode superclassNode = null;

  private boolean toPrint = true;

  public ClassNode(String n)
  {
    name = n;

    methods = new ArrayList<ClassMethod>();

    members = new ArrayList<ClassMember>();

    constructors = new ArrayList<ArrayList<ClassParameter>>();
    constructors.add(new ArrayList<ClassParameter>()); // Class must have default constructor

    children = new ArrayList<ClassNode>();
  }

  public ClassNode(String n, ClassNode inherited)
  {
    name = n;

    methods = new ArrayList<ClassMethod>();
    methods.addAll(inherited.getMethods());

    members = new ArrayList<ClassMember>();
    members.addAll(inherited.getMembers());

    constructors = new ArrayList<ArrayList<ClassParameter>>();
    constructors.add(new ArrayList<ClassParameter>()); // Class must have default constructor

    children = new ArrayList<ClassNode>();

    superclass = inherited.getName();
    superclassNode = inherited;
  }

  public String getName()
  {
    return name;
  }

  public void addMethod(ClassMethod m) // FIXME: Allow overloading (will need to change compareTo for ClassMethod)
  {
    int index = -1;

    int i;

    for(i = 0; i < methods.size() && index < 0; i++)
    {
      if(m.equals(methods.get(i)))
        index = i;
    }

    if(index < 0)
      methods.add(m);
    else methods.set(index, m);
  }

  public void addMember(ClassMember m)
  {
    members.add(m);
  }

  public void addConstructor(ArrayList<ClassParameter> args)
  {
    if(args.size() != 0) // Already added if args.size() == 0
      constructors.add(args);
  }

  public ArrayList<ClassMethod> getMethods()
  {
    return methods;
  }

  public ArrayList<ClassMember> getMembers()
  {
    return members;
  }

  public void addChild(ClassNode child)
  {
    children.add(child);
  }

  public boolean hasDefaultConstructor()
  {
    return defaultConstructor != null;
  }

  public void setDefaultConstructor(Node n)
  {
    defaultConstructor = n;
  }

  public Node getDefaultConstructor()
  {
    return defaultConstructor;
  }

  public String getSuperclass()
  {
    return superclass;
  }

  public ClassNode getSuperclassNode()
  {
    return superclassNode;
  }

  public ArrayList<ClassNode> getAncestors(ArrayList<ClassNode> list)
  {
    if(superclassNode != null)
    {
      list.add(superclassNode);
      return superclassNode.getAncestors(list);
    }
    else return list;
  }

  public boolean extendsObject()
  {
    return superclass.equals("Object");
  }

  public void setPrint(boolean p)
  {
    toPrint = p;
  }

  public ClassNode getClass(String n)
  {
    if(name.equals(n))
      return this;

    int i;
    ClassNode cn = null;

    for(i = 0; i < children.size() && cn == null; i++)
    {
      cn = children.get(i).getClass(n);
    }

    return cn;
  }

  public ClassMethod getMethod(String n)
  {
    for(ClassMethod m : methods)
    {
      if(m.getName().equals(n))
        return m;
    }

    return null;
  }

  public int compareTo(String other)
  {
    return name.compareTo(other);
  }

  public void print(Printer out) // TODO: Print the actual class (along with the already printed vtable)
  {
    if(toPrint) // TODO: Add constructors in class struct
    {
      int t, i, j;
      int dims;

      // Print the class
      out.indent();
      out.pln("struct __" + name);
      out.indent();
      out.pln("{");

      out.incr();

      out.indent();
      out.pln("__" + name + "_VT* __vptr;");
      out.pln();

      for(t = 0; t < members.size(); t++)
      {
         out.indent();
         out.pln(members.get(t).getType() + " " + members.get(t).getName() + ";");
      }

      out.pln();

      for(t = 0; t < constructors.size(); t++)
      {
        out.indent();

        out.p("__" + name + "(");

        for(i = 0; i < constructors.get(t).size(); i++)
        {
          dims = constructors.get(t).get(i).getDimensions();

          for(j = 0; j < dims; j++)
          {
            out.p("__rt::Ptr<__rt::Array<");
          }

          out.p(constructors.get(t).get(i).getType());

          for(j = 0; j < dims; j++)
          {
            out.p(">, __rt::array_policy>");

            if(j < dims - 1)
              out.p(" ");
          }

          if(i < constructors.get(t).size() - 1)
            out.p(", ");
        }

        out.pln(");");
      }

      out.pln();

      out.indent();
      out.pln("static __" + name + "* init(__" + name + "*);");

      out.pln();

      for(t = 0; t < methods.size(); t++)
      {
        ClassMethod m = methods.get(t);

        dims = m.getReturnType().getDimensions();

        out.indent();
        out.p("static ");

        for(j = 0; j < dims; j++)
        {
          out.p("__rt::Ptr<__rt::Array<");
        }

        out.p(m.getReturnType().getType() + " " + m.getName() + "(");

        for(j = 0; j < dims; j++)
        {
          out.p(">, __rt::array_policy>");

          if(j < dims - 1)
            out.p(" ");
        }

        if(!m.isStatic())
        {
          out.p(m.getDefiningClass());

          if(m.getParameters().size() > 0)
            out.p(", ");
        }

        for(i = 0; i < m.getParameters().size(); i++)
        {
          dims = m.getParameters().get(i).getDimensions();

          for(j = 0; j < dims; j++)
          {
            out.p("__rt::Ptr<__rt::Array<");
          }

          out.p(m.getParameters().get(i).getType());

          for(j = 0; j < dims; j++)
          {
            out.p(">, __rt::array_policy>");

            if(j < dims - 1)
              out.p(" ");
          }

          if(i < m.getParameters().size() - 1)
            out.p(", ");
        }

        out.pln(");");
      }

      out.pln();

      out.indent();
      out.pln("static Class __class();");
      out.indent();
      out.pln("static __" + name + "_VT __vtable;");

      out.decr();

      out.indent();
      out.pln("};");
      out.pln();


      // Print the vtable
      out.indent();
      out.pln("struct __" + name + "_VT");
      out.indent();
      out.pln("{");

      out.incr();

      out.indent();
      out.pln("Class __isa;");
      out.indent();
      out.pln("void (*__delete)(__" + name + "*);");

      for(t = 0; t < methods.size(); t++)
      {
        ClassMethod m = methods.get(t);

        if(!m.isStatic())
        {
          dims = m.getReturnType().getDimensions();

          out.indent();

          for(j = 0; j < dims; j++)
          {
            out.p("__rt::Ptr<__rt::Array<");
          }

          out.p(m.getReturnType().getType());

          for(j = 0; j < dims; j++)
          {
            out.p(">, __rt::array_policy>");

            if(j < dims - 1)
              out.p(" ");
          }

          out.p(" (*" + m.getName() + ")");

          out.p("(");

          if(m.getName().equals("getClass"))
            out.p(name);
          else out.p(m.getDefiningClass());

          if(m.getParameters().size() > 0)
            out.p(", ");

          for(i = 0; i < m.getParameters().size(); i++)
          {
            out.p(m.getParameters().get(i).getType());

            if(i < m.getParameters().size() - 1)
              out.p(", ");
          }

          out.pln(");");
        }
      }

      out.pln();

      out.indent();
      out.pln("__" + name + "_VT() :");

      out.incr();

      out.indent();
      out.pln("__isa(__" + name + "::__class()),");
      out.indent();
      out.p("__delete(__rt::__delete<__" + name + ">)");

      for(t = 0; t < methods.size(); t++)
      {
        ClassMethod m = methods.get(t);

        if(!m.isStatic())
        {
          out.pln(",");
          out.indent();

          out.p(m.getName() + "(");

          if(m.getName().equals("getClass"))
            out.p("(Class(*)(" + name + "))&__" + m.getDefiningClass() + "::" + m.getName());
          else out.p("&__" + m.getDefiningClass() + "::" + m.getName());

          out.p(")");
        }
      }

      out.pln();

      out.decr();

      out.indent();
      out.pln("{");
      out.indent();
      out.pln("}");

      out.decr();
      out.indent();
      out.pln("};");
      out.pln();

      // Print internal __class() method
      out.indent();
      out.pln("Class __" + name + "::__class()");
      out.indent();
      out.pln("{");

      out.incr();

      out.indent();
      out.pln("static Class k = new __Class(__rt::literal(\"" + name + "\"), __" + superclass + "::__class());");

      out.indent();
      out.pln("return k;");

      out.decr();

      out.indent();
      out.pln("}");

      out.pln();
    }

    int k;

    for(k = 0; k < children.size(); k++)
    {
      children.get(k).print(out);
    }
  }
}
