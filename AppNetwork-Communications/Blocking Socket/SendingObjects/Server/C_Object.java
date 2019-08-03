import java.io.Serializable;

public class C_Object implements Serializable {

  String name;
  String lastName;
  int age;
  int passNumber;

  public C_Object ( String n, String l, int a, int p ) {
    
    this.name = n;
    this.lastName = l;
    this.age = a;
    this.passNumber = p;

  } // End of Data method.
} // End of C_Object class.
