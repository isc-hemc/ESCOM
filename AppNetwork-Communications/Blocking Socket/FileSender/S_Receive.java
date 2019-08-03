import java.net.*;
import java.io.*;

public class S_Receive {
  public static void main ( String [ ] args ) {
    try {
      int port = 8000;
      int porcentage = 0;
      ServerSocket s = new ServerSocket ( port );
      s.setReuseAddress ( true );
      System.out.println ( "\n\n\tService initialized... Waiting for client." );
      for ( ; ; ) {
        Socket cl = s.accept ( );
        cl.setSoLinger ( true, 10 );
        System.out.println ( "\n\n\tClient connected from: " +cl.getInetAddress ( ) + ": " + cl.getPort ( ) );
        DataInputStream dis = new DataInputStream ( cl.getInputStream ( ) );
        String name;
        int len;
        long size;
        long recv = 0;
        name = dis.readUTF ( );
        size = dis.readLong ( );
        BufferedOutputStream bos = new BufferedOutputStream ( new FileOutputStream ( name ) );
        BufferedInputStream bis = new BufferedInputStream ( cl.getInputStream ( ) );
        while ( recv < size ) {
          byte [ ] b = new byte [ 2000 ];
          int n = bis.read ( b );
          recv = recv + n;
          bos.write ( b, 0, n );
          porcentage = ( int ) ( ( recv * 100 ) / size );
          System.out.print ( "\n\t" + porcentage + "% received." );
        } // End of while.
        dis.close ( );
        bos.close ( );
      } // End of for.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of class.
