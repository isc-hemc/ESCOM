import java.net.*;
import java.io.*;

public class Send_Announcement {
  public static void main ( String [ ] args ) {
    try {
      int ports = 9000, portc = 9001;
      String address = "227.1.1.1";
      MulticastSocket s = new MulticastSocket( ports );
      System.out.println ( "\n\tMulticast service initialized..." );
      String msg = "Announcement";
      byte [ ] b = msg.getBytes ( );
      InetAddress group = null;
      try {
        group = InetAddress.getByName ( address );
      } catch ( UnknownHostException e ) {
        System.err.println ( "\n\tInvalid address." );
        System.exit ( 0 );
      } // End of try - catch.
      s.joinGroup ( group );
      s.setTimeToLive ( 200 );
      for ( ; ; ) {
        DatagramPacket p = new DatagramPacket ( b, b.length, group, portc );
        s.send ( p );
        try {
          Thread.sleep ( 5000 );
        } catch ( InterruptedException ie ) { } // End try - catch.
      } // End of for.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of Send_Announcement class.
