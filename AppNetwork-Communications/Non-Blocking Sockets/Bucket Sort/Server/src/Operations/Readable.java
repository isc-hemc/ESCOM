package Operations;

import java.nio.ByteBuffer;
import java.nio.channels.*;
import java.util.Random;
import Servers.Sockets;
import Bucket.Bucket;
import Main.Main;

/* The class Readable receive from the client the number of buckets that the server
 * must be prepared to receive, then the server creates 'n' number of threads, this
 * threads are blocking servers, each sub server will receive a bucket and will sort
 * the content using the bubble sort algorithm.
 */

public class Readable {
	
	public static String [ ] portsList;
	public static Integer numBuckets;
	private static boolean sFlag;
	private static String recv;
	private static int counter;
	private static Integer rnd;
	private static int n;

	public static void read ( ) throws Exception {
		
		SocketChannel sc = ( SocketChannel ) Main.k.channel ( );
		ByteBuffer b = ByteBuffer.allocate ( 10 );
		counter = 0;
		
		b.clear ( );
		n = sc.read ( b );
		b.flip ( );
		recv = new String ( b.array ( ), 0, n );
		numBuckets = Integer.parseInt ( recv );
		portsList = new String [ numBuckets ];
		
		System.out.println ( "\n\t\tMessage received from: " + sc.socket ( ).getInetAddress ( ).getHostAddress ( ) + " : " + sc.socket ( ).getPort ( ) + ".\n\t\tNumber of buckets to receive: " + numBuckets + "." );

		while ( counter < numBuckets ) {
			sFlag = false;
			subServers ( );
			counter++;
		} // End while.
				
		Main.k.interestOps ( SelectionKey.OP_WRITE );
		
	} // End method.
	
	public static void subServers ( ) throws Exception {
		
		Runnable t = ( ) -> { 
			Bucket b;
			while ( sFlag == false ) {
				rnd = ( int ) ( new Random ( System.currentTimeMillis ( ) ).nextDouble ( ) * 65535 + 1024 );
				sFlag = Sockets.init ( rnd );
				portsList [ counter ] = rnd.toString ( );
			} // End while.
			try { 
				b = Sockets.recv ( ); 
				Sockets.send ( b );
			} catch ( Exception e ) { e.printStackTrace ( ); }
		}; new Thread ( t ).start ( );
		Thread.sleep ( 500 );
		
	} // End method.
	
} // End class.
