import java.io.*;
import java.net.*;

public class C_Send_O {
  public static void main ( String [ ] args ) {
    try {
      String host = "127.0.0.1";
      int port = 9709;
      Socket cl = new Socket ( host, port );
      System.out.println ( "\n\tConnection established... sending object..." );
      ObjectOutputStream oos = new ObjectOutputStream ( cl.getOutputStream ( ) );
      ObjectInputStream ois = new ObjectInputStream ( cl.getInputStream ( ) );
      C_Object o = new C_Object ( "David", "Martinez", 22, 12345 );
      oos.writeObject ( o );
      oos.flush ( );
      System.out.println ( "\n\tThe object has been send with the data:\n\n\tName: " + o.name + "\n\tLast Name: " + o.lastName + "\n\tAge: " + o.age + "\n\tPass Number: " + o.passNumber );
      C_Object o1 = ( C_Object ) ois.readObject ( );
      System.out.println ( "\n\tThe object has been received with the data:\n\n\tName: " + o1.name + "\n\tLast Name: " + o1.lastName + "\n\tAge: " + o1.age + "\n\tPass Number: " + o1.passNumber + "\n" );
      oos.close ( );
      ois.close ( );
      cl.close ( );
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of C_Send_O class.
