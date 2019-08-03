import java.net.*;
import java.io.*;

public class S_ECHO_D {
  public static void main ( String [ ] args ) {
    try {
      BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
      int port = 7000;
      DatagramSocket s = new DatagramSocket ( port );
      System.out.println ( "\n\tECHO service initialized... Waiting client..." );
      for ( ; ; ) {
        DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
        s.receive ( p );
        System.out.println ( "\n\tMessage received from: " + p.getAddress ( ) + " : " + p.getPort ( ) );
        String data = new String ( p.getData ( ), 0, p.getLength ( ) );
        System.out.println ( "\tMenssage: " + data );
        s.send ( p );
      } // End of For.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of S_ECHO_D class..
