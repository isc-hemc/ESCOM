import javax.swing.JFileChooser;
import java.net.*;
import java.io.*;

public class C_Send {
  public static void main ( String [ ] args ) {
    try {
      String host = "127.0.0.1";
      int pto = 8000;
      int porcentage = 0;
      Socket cl = new Socket ( host, pto );
      JFileChooser fc = new JFileChooser ( );
      fc.setMultiSelectionEnabled ( true );
      int r = fc.showOpenDialog ( null );
      if ( r == JFileChooser.APPROVE_OPTION ) {
        File f = fc.getSelectedFile ( );
        String name = f.getName ( );
        String path = f.getAbsolutePath ( );
        long size = f.length ( );
        DataOutputStream dos = new DataOutputStream ( cl.getOutputStream ( ) );
        dos.writeUTF ( name );
        dos.flush ( );
        dos.writeLong ( size );
        dos.flush ( );
        DataInputStream dis = new DataInputStream ( new FileInputStream ( path ) );
        long sent = 0;
        while ( sent < size ) {
          byte [ ] b = new byte [ 2000 ];
          int n = dis.read ( b );
          sent = sent + n;
          dos.write ( b, 0, n );
          dos.flush ( );
          porcentage = ( int ) ( ( sent * 100 ) / size );
          System.out.print ( "\n\t" + porcentage + "% sent." );
        } // End of while.
        System.out.println ( "\n\n\tFile sent...\n" );
        dis.close ( );
        dos.close ( );
        cl.close ( );
      } // End of if.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End of try - catch.
  } // End of main method.
} // End of class.
