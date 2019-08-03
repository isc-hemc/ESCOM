import java.net.*;
import java.io.*;

public class C_ECHO {
  public static void main ( String [ ] args ) {
    try {
      InetAddress dir = null;
      String host = "";
      int pto = 5100;
      BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
      while ( true ) {
        System.out.print ( "\n\n\tWrite the address of the server: " );
        host = br.readLine ( );
        try {
          dir = InetAddress.getByName ( host );
        } catch ( UnknownHostException u ) {
            System.err.println ( "\n\tInvalid address." );
        } // End of nested try - catch.
        break;
      } // End of while.
      Socket cl = new Socket ( dir, pto );
      System.out.print ( "\n\tConnection established.\n" );
      PrintWriter pw = new PrintWriter ( new OutputStreamWriter ( cl.getOutputStream ( ) ) );
      BufferedReader br1 = new BufferedReader ( new InputStreamReader ( cl.getInputStream ( ) ) );
      String msg = "";
      for ( ; ; ) {
        System.out.print ( "\n\tWrite message: " );
        msg = br.readLine ( );
        pw.println ( msg );
        pw.flush ( );
        if ( msg.compareToIgnoreCase ( "Exit" ) == 0 ) {
            System.out.println ( "\n\tEnd application.\n" );
            br1.close ( );
            br.close ( );
            pw.close ( );
            cl.close ( );
            System.exit ( 0 );
        } else {
          String echo = br1.readLine ( );
          System.out.println ( "\n\t*Echo received: " + echo );
        } // End of if - else.
      } // End of for.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of class.
