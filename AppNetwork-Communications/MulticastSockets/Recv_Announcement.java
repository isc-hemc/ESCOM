import java.net.*;
import java.io.*;

public class Recv_Announcement {
  public static void main ( String [ ] args ) {
    try {
      int port = 9001;
      String address = "227.1.1.1";
      MulticastSocket cl = new MulticastSocket ( port );
      System.out.println ( "\n\tMulticast Service initialized... reading announcement." );
      String msg = "Announcement";
      InetAddress group = null;
      try {
        group = InetAddress.getByName ( address );
      } catch ( UnknownHostException e ) {
        System.err.println ( "\n\tInvalid Address." );
        System.exit ( 0 );
      } // End of try - catch.
      cl.joinGroup ( group );
      cl.setTimeToLive ( 200 );
      for ( ; ; ) {
        DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
        cl.receive ( p );
        String data = new String ( p.getData ( ), 0, p.getLength ( ) );
        if ( data.compareToIgnoreCase ( msg ) == 0 ) {
          System.out.println ( "\n\tService at: " + p.getAddress ( ) );
        } // End of if.
      } // End of for.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End od Receive_Announcement class.
