import java.net.*;
import java.io.*;

public class S_ECHO {
  public static void main ( String [ ] args ) {
    try {
      int pto = 5100;
      ServerSocket s = new ServerSocket ( pto );
      s.setReuseAddress ( true );
      System.out.println ( "\n\n\tECHO service initialized... Waiting for client." );
      for ( ; ; ) {
        Socket cl = s.accept ( );
        System.out.println ( "\n\tClient connected from: " + cl.getInetAddress ( ) + ": " + cl.getPort ( ) );
        PrintWriter pw = new PrintWriter ( new OutputStreamWriter ( cl.getOutputStream ( ) ) );
        BufferedReader br = new BufferedReader ( new InputStreamReader ( cl.getInputStream ( ) ) );
        String msg = "";
        for ( ; ; ) {
          msg = br.readLine ( );
          if ( msg.compareToIgnoreCase ( "Exit" ) == 0 ) {
            System.out.println ( "\n\tClient finish." );
            br.close ( );
            pw.close ( );
            cl.close ( );
            break;
          } else {
            System.out.print ( "\n\tMensage received: " + msg + "." );
            String echo = msg + "ECHO";
            pw.println ( echo );
            pw.flush ( );
            continue;
          } // End of f - else.
        } // End of nested loop.
      } // End of loop.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of class.
