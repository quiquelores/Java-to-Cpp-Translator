/** Translator - The Driver class that runs the Java to C++ Translator.
 * (C) Shady Gabal, Stephen Hu, Enrique Lores, Brandon Mazey, William Neville, Doris Tang
 */

import java.io.File;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.Reader;

import xtc.lang.JavaFiveParser;
import xtc.lang.JavaPrinter;

import xtc.parser.ParseException;
import xtc.parser.Result;

import xtc.tree.GNode;
import xtc.tree.Node;
import xtc.tree.Printer;
import xtc.tree.Visitor;

import xtc.util.Tool;

public class Translator extends Tool
{
  private String mainClass;

  /** Create a new translator. */
  public Translator() {
    // Nothing to do.
  }

  public String getName() {
    return "Java to C++ Translator";
  }

  public String getCopy() {
    return "(C) 2013 <Group Name>";
  }

  public void init() {
    super.init();

    // Declare command line arguments.
    runtime.
      bool("printJavaAST", "printJavaAST", false, "Print Java AST.").
      bool("printJavaCode", "printJavaCode", false, "Print Java code.").
      bool("countMethods", "countMethods", false, "Count all Java methods.").
      bool("testHeaderPrint", "testHeaderPrint", false, "Print out the header file for a corresponding C++ file.").
      bool("testVTPrint", "testVTPrint", false, "Print the VTables needed for the translation of the Java program into a C++ program.").
      bool("testSourcePrint", "testSourcePrint", false, "Print out the source file for a corresponding C++ file.").
      bool("testFullPrint", "testFullPrint", false, "Print out all C++ source to make a C++ program that works like the corresponding Java program.");
  }

  public void prepare() {
    super.prepare();

    // Perform consistency checks on command line arguments.
  }

  public File locate(String name) throws IOException {
    File file = super.locate(name);
    if (Integer.MAX_VALUE < file.length())
    {
      throw new IllegalArgumentException(file + ": file too large");
    }
    else
    {
      mainClass = file.getName();
      if(mainClass.indexOf('.') >= 0)
        mainClass = mainClass.substring(0, mainClass.lastIndexOf('.'));
    }
    return file;
  }

  public Node parse(Reader in, File file) throws IOException, ParseException {
    JavaFiveParser parser =
      new JavaFiveParser(in, file.toString(), (int)file.length());
    Result result = parser.pCompilationUnit(0);
    return (Node)parser.value(result);
  }

  public void process(Node node) {
    if (runtime.test("printJavaAST")) {
      runtime.console().format(node).pln().flush();
    }

    if (runtime.test("printJavaCode")) {
      new JavaPrinter(runtime.console()).dispatch(node);
      runtime.console().flush();
    }

    if (runtime.test("countMethods")) {
      new Visitor() {
        private int count = 0;

        public void visitCompilationUnit(GNode n) {
          visit(n);
          runtime.console().p("Number of methods: ").p(count).pln().flush();
        }

        public void visitMethodDeclaration(GNode n) {
          runtime.console().p("Name of node: ").p(n.getName()).pln();
          runtime.console().p("Name of method: ").p(n.getString(3)).pln();
          visit(n);
          count++;
        }

        public void visit(Node n) {
          for (Object o : n) if (o instanceof Node) dispatch((Node) o);
        }

      }.dispatch(node);
    }

    if(runtime.test("testHeaderPrint"))
    {
      new CPPHeaderPrinter(new Printer(System.out)).dispatch(node);
    }

    if(runtime.test("testVTPrint"))
    {
      new CPPClassPrinter(new Printer(System.out)).dispatch(node);
    }

    if(runtime.test("testSourcePrint"))
    {
      new CPPPrinter(new Printer(System.out)).dispatch(node);
    }

    if(runtime.test("testFullPrint"))
    {
      FileOutputStream out = null;
      try
      {
        out = new FileOutputStream(new File(mainClass + ".cpp"));
      }
      catch(IOException e)
      {
        System.out.println("ERROR: Output file could not be created");
      }

      Printer printer = new Printer(out);

      CPPHeaderPrinter hp = new CPPHeaderPrinter(printer);
      hp.dispatch(node);

      CPPTypeDefPrinter tdp = new CPPTypeDefPrinter(printer);
      tdp.dispatch(node);

      CPPClassPrinter cp = new CPPClassPrinter(printer);
      cp.dispatch(node);

      CPPPrinter p = new CPPPrinter(printer, mainClass, cp.getClassTree());
      p.dispatch(node);

      try
      {
        out.close();
      }
      catch(IOException e)
      {
        System.out.println("ERROR: Output file was never open.");
      }
    }
  }

  /**
   * Run the translator with the specified command line arguments.
   *
   * @param args The command line arguments.
   */
  public static void main(String[] args) {
    new Translator().run(args);
  }

}
