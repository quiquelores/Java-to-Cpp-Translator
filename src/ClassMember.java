public class ClassMember
{
  private String type;
  private String name;
  private String initialization;

  public ClassMember(String t, String n)
  {
    type = t;
    name = n;
    initialization = null;
  }

  public ClassMember(String t, String n, String i)
  {
    type = t;
    name = n;
    initialization = i;
  }

  public String getType()
  {
    return type;
  }

  public String getName()
  {
    return name;
  }

  public void setInitialization(String i)
  {
    initialization = i;
  }

  public String getInitialization()
  {
    return initialization;
  }

  public boolean hasInitialization()
  {
    return initialization != null;
  }
}
