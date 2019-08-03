import java.net.*;
import java.io.*;

public class C_ECHO_D {
  public static void main ( String [ ] args ) {
    try {
      String host = "127.0.0.1";
      int port = 7000;
      DatagramSocket cl = new DatagramSocket ( );
      BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
      for ( ; ; ) {
        System.out.print ( "\n\tWrite message: " );
        String msg = br.readLine ( );
        byte [ ] b = msg.getBytes ( );
        if ( b.length > 1500 ) {
          ByteArrayInputStream bais = new ByteArrayInputStream ( b );
          int n = 0;
          byte [ ] tmp = new byte [ 1500 ];
          while ( ( n = bais.read ( tmp ) ) != -1 ) {
            DatagramPacket p = new DatagramPacket ( tmp, n, InetAddress.getByName ( host ), port );
            cl.send ( p );
            if ( msg.indexOf ( "Exit" ) >= 0 ) {
              System.out.println ( "\n\tEnd application..." );
              bais.close ( );
              cl.close ( );
              System.exit ( 0 );
            } // End of if.
            DatagramPacket p1 = new DatagramPacket ( new byte [ 1500 ], 1500 );
            cl.receive ( p1 );
            System.out.println ( "\n\tECHO received from: " + p1.getAddress ( ) + " : " + p1.getPort ( ) + " with ECHO: " + new String ( p1.getData ( ), 0, p1.getLength ( ) ) );
          } // End of while.
        } else {
          DatagramPacket p = new DatagramPacket ( b, b.length, InetAddress.getByName ( host ), port );
          cl.send ( p );
          if ( msg.indexOf ( "Exit" ) >= 0 ) {
            System.out.println ( "\n\tEnd application..." );
            cl.close ( );
            System.exit ( 0 );
          } // End of if.S
          DatagramPacket p1 = new DatagramPacket ( new byte [ 1500 ], 1500 );
          cl.receive ( p1 );
          System.out.println ( "\n\tECHO received from: " + p1.getAddress ( ) + " : " + p1.getPort ( ) + " with ECHO: " + new String ( p1.getData ( ), 0, p1.getLength ( ) ) );
        } // End of if - else.
      } // End of for.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of C_ECHO_D class.
