import java.net.*;
import java.io.*;

public class C_HW_D {
  public static void main ( String [ ] args ) {
    try {
      BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
      DatagramSocket cl = new DatagramSocket ( );
      int port = 9709;
      System.out.print ( "\n\tWrite the server address: " );
      String host = br.readLine ( );
      System.out.print ( "\n\tWrite a message: " );
      String msg = br.readLine ( );
      byte [ ] b = msg.getBytes ( );
      DatagramPacket p = new DatagramPacket ( b, b.length, InetAddress.getByName ( host ), port );
      cl.send ( p );
      System.out.println ( "\n\tMessage send...\n" );
      cl.close ( );
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of C_HW_D class.
