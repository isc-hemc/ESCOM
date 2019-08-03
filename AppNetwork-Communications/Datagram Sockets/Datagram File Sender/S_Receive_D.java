import java.util.ArrayList;
import java.net.*;
import java.io.*;

public class S_Receive_D {

  public static void main ( String [ ] args ) {

    try {
      int port = 9709;
      DatagramSocket s = new DatagramSocket ( port );
      ArrayList <D_Object> aList = new ArrayList <D_Object> ( );
      System.out.println ( "\n\n\tService initialized... waiting for packets.\n" );
      for ( ; ; ) {
        /* Receive object size. */
        int objSize = getObjectSize ( s );
        /* Receive objects packages. */
        ByteArrayInputStream bais;
        ObjectInputStream ois;
        int i = 0;
        do {
          DatagramPacket p = new DatagramPacket ( new byte [ objSize ], objSize );
          s.receive ( p );
          bais = new ByteArrayInputStream ( p.getData ( ) );
          ois = new ObjectInputStream ( bais );
          D_Object object = ( D_Object ) ois.readObject ( );
          aList.add ( object );
          System.out.println ( "\tCounter: " + ( i + 1 ) + ".\tPartitions: " + aList.get ( 0 ).getPartitions ( ) + ".\tObject Size: " + objSize + "." );
          i++;
        } while ( i < aList.get ( 0 ).getPartitions ( ) );
        for ( int g = 0 ; g < aList.size ( ) ; g++ ) {
          FileOutputStream fos = new FileOutputStream ( new File ( aList.get ( 0 ).getName ( ) ), true );
          fos.write ( aList.get ( g ).getData ( ), 0, ( int ) ( aList.get ( g ).getSize ( ) ) );
        }
        System.out.println ( "\n\tFile Received.\n" );
        aList.clear ( );
      } // End for-ever.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

  } // End main.

  public static int getObjectSize ( DatagramSocket s ) {

    int objSize = 0;
    try {
      DatagramPacket p = new DatagramPacket ( new byte [ 4 ], 4 );
      s.receive ( p );
      ByteArrayInputStream bais = new ByteArrayInputStream ( p.getData ( ) );
      DataInputStream dis = new DataInputStream ( bais );
      objSize = ( int ) dis.readInt ( );
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

    return objSize;

  } // End method.

} // End class.
