import java.io.*;
import java.net.*;

public class S_Receive_O {
  public static void main ( String [ ] args ) {
    try {
      int port = 9709;
      ServerSocket s = new ServerSocket ( port );
      s.setReuseAddress ( true );
      System.out.println ( "\n\tService initialized... Waiting for client." );
      for ( ; ; ) {
        Socket cl = s.accept ( );
        ObjectOutputStream oos = new ObjectOutputStream ( cl.getOutputStream ( ) );
        ObjectInputStream ois = new ObjectInputStream ( cl.getInputStream ( ) );
        System.out.println ( "\n\tClient connected from: " + cl.getInetAddress ( ) + " : " + cl.getPort ( ) );
        C_Object s_o = ( C_Object ) ois.readObject ( );
        System.out.println ( "\n\tThe object has been received with the data:\n\n\tName: " + s_o.name + "\n\tLast Name: " + s_o.lastName + "\n\tAge: " + s_o.age + "\n\tPass Number: " + s_o.passNumber );
        C_Object s_o1 = new C_Object ( "Carlos", "Hernandez", 22, 12345 );
        oos.writeObject ( s_o1 );
        oos.flush ( );
        System.out.println ( "\n\tThe object has been send with the data:\n\n\tName: " + s_o1.name + "\n\tLast Name: " + s_o1.lastName + "\n\tAge: " + s_o1.age + "\n\tPass Number: " + s_o1.passNumber );
        oos.close ( );
        ois.close ( );
        cl.close ( );
      } // End of for.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of S_Receive_O class.
