package Operations;

import java.nio.ByteBuffer;
import java.nio.channels.*;
import Clients.Sockets;
import Bucket.Bucket;
import Main.Main;

/* This class receives from the server the list of ports that the sub client most bind,
 * there will be one sub client per sub server. Then, the client will initialize all
 * the sub clients to start the communication.
 */

public class Readable {
	
	public static String [ ] portsList;
	public static Integer subrange;
	private static Integer counter;
	private static boolean cFlag;
	private static String recv;
	private static Integer aux;
	private static int id;
	private static int n;
	
	public static void read ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Main.k.channel ( );
		ByteBuffer b = ByteBuffer.allocate ( 100 );
		subrange = 1000 / Writable.numBuckets;
		counter = 0;
		aux = 0;
		id = 0;
		
		b.clear ( );
		n = ch.read ( b );
		b.flip ( );
		recv = new String ( b.array ( ), 0, n );
		portsList = recv.split ( " " );
		subClients ( );
		
		Main.k.interestOps ( SelectionKey.OP_WRITE );
		
	} // End method.
	
	public static void subClients ( ) throws Exception {
		
		Runnable t = ( ) -> {
			Bucket b;
			while ( counter < portsList.length ) {
				cFlag = Sockets.init ( Integer.parseInt ( portsList [ counter ] ), aux );
				if ( cFlag ) {
					System.out.println ( "\n\n\tConnection established... sending bucket." );
					try {
						Sockets.send ( id );
						b = Sockets.recv ( );
						b.getBucket ( );
						id++;
					} catch ( Exception e ) { e.printStackTrace ( ); }
				} // End if.
				aux = aux + subrange;
				counter++;
			} // End while.
		}; new Thread ( t ).start ( );
		Thread.sleep ( 500 );
		
	} // End method.

} // End class.
