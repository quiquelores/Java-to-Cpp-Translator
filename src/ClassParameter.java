public class ClassParameter
{
  private String type;
  private int dimensions;

  public ClassParameter(String t)
  {
    type = t;
    dimensions = 0;
  }

  public ClassParameter(String t, int d)
  {
    type = t;
    dimensions = d;
  }

  public String getType()
  {
    return type;
  }

  public int getDimensions()
  {
    return dimensions;
  }
}
