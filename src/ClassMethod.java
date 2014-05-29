import java.util.ArrayList;

public class ClassMethod implements Comparable<ClassMethod>
{
  private String name;
  private ClassParameter returnType;
  private ArrayList<ClassParameter> parameters;

  private String classDefined; // Which class defined this version of the method

  private boolean isStatic;

  public ClassMethod(String n, ClassParameter r, ArrayList<ClassParameter> p, String def, boolean s)
  {
    name = n;
    returnType = r;
    parameters = p;
    classDefined = def;
    isStatic = s;
  }

  public String getName()
  {
    return name;
  }

  public ClassParameter getReturnType()
  {
    return returnType;
  }

  public ArrayList<ClassParameter> getParameters()
  {
    return parameters;
  }

  public String getDefiningClass()
  {
    return classDefined;
  }

  public void setStatic(boolean s)
  {
    isStatic = s;
  }

  public boolean isStatic()
  {
    return isStatic;
  }

  public int compareTo(ClassMethod other)
  {
    if(name.compareTo(other.getName()) != 0)
      return name.compareTo(other.getName());

    if(parameters == null && other.getParameters() != null)
      return -1 * other.getParameters().size();

    if(parameters != null && other.getParameters() == null)
      return parameters.size();

    if(parameters != null && other.getParameters() != null && parameters.size() != other.getParameters().size())
      return parameters.size() - other.getParameters().size();
/* Add this back when method overloading is allowed
    int i;

    for(i = 0; i < parameters.size(); i++)
    {
      if(parameters.get(i).compareTo(other.getParameters().get(i)) != 0)
        return parameters.get(i).compareTo(other.getParameters().get(i));
    }
*/
    return 0;
  }

  public boolean equals(ClassMethod other)
  {
    return this.compareTo(other) == 0;
  }
}
