import javax.swing.JFileChooser;
import java.nio.file.*;
import java.net.*;
import java.io.*;

public class C_Send_D {

  public static void main ( String [ ] args ) {

    try {
      String host = "127.0.0.1";
      int port = 9709;
      int index = 0; // ID of the object.
      DatagramSocket cl = new DatagramSocket ( );
      JFileChooser fc = new JFileChooser ( );
      int r = fc.showOpenDialog ( null );
      if ( r == JFileChooser.APPROVE_OPTION ) {
        File f = fc.getSelectedFile ( );
        String name = f.getName ( );
        long size = f.length ( );
        byte [ ] b = Files.readAllBytes ( f.toPath ( ) );
        /* File partitions. */
        int partitions = Split ( b );
        /* Size of the objects. */
        int objSize = getObjectSize ( b, partitions, name );
        /* Send object size. */
        sendObjectSize ( objSize, cl, host, port );
        /* Send datagrams. */
        ByteArrayInputStream bais = new ByteArrayInputStream ( b );
        byte [ ] tmp = new byte [ 1500 ];
        int aux = 0;
        while ( ( aux = bais.read ( tmp ) ) != -1 ) {
          D_Object object = new D_Object ( tmp, name, aux, partitions, index );
          ByteArrayOutputStream baos = new ByteArrayOutputStream ( );
          ObjectOutputStream oos = new ObjectOutputStream ( baos );
          oos.writeObject ( object );
          byte [ ] data = baos.toByteArray ( );
          DatagramPacket p = new DatagramPacket ( data, data.length, InetAddress.getByName ( host ), port );
          cl.send ( p );
          index++;
        } // End while.
      } // End if.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

  } // End main.

  public static int Split ( byte [ ] b ) {

    int p = 0;

    try {
      ByteArrayInputStream bais = new ByteArrayInputStream ( b );
      byte [ ] tmp = new byte [ 1500 ];
      int aux = 0;
      while ( ( aux = bais.read ( tmp ) ) != -1 ) {
        p = p + 1;
      } // End while.
      bais.close ( );
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

    return p;

  } // End method.

  public static int getObjectSize ( byte [ ] b, int partitions, String name ) {

    ByteArrayInputStream bais = new ByteArrayInputStream ( b );
    byte [ ] tmp = new byte [ 1500 ];
    int aux = 0;
    int objSize = 0;
    int index = 0;

      try {
        while ( ( aux = bais.read ( tmp ) ) != -1 ) {
          D_Object object = new D_Object ( tmp, name, aux, partitions, index );
          ByteArrayOutputStream baos = new ByteArrayOutputStream ( );
          ObjectOutputStream oos = new ObjectOutputStream ( baos );
          oos.writeObject ( object );
          byte [ ] data = baos.toByteArray ( );
          objSize = data.length;
          index++;
        } // End while.
        bais.close ( );
      } catch ( Exception e ) {
        e.printStackTrace ( );
      } // End try- catch.
    return objSize;

  } // End method.

  public static void sendObjectSize ( int objSize, DatagramSocket cl, String host, int port ) {

    try {
      ByteArrayOutputStream baos = new ByteArrayOutputStream ( );
      DataOutputStream dos = new DataOutputStream ( baos );
      dos.writeInt ( objSize );
      dos.flush ( );
      byte [ ] b = baos.toByteArray ( );
      DatagramPacket p = new DatagramPacket ( b, b.length, InetAddress.getByName ( host ), port );
      cl.send ( p );
      dos.close ( );
      baos.close ( );
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

  } // End method.
} // End class.
