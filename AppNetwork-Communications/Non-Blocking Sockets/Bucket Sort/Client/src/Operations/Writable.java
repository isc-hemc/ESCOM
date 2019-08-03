package Operations;

import java.nio.ByteBuffer;
import java.nio.channels.*;
import java.util.Random;
import Main.Main;

public class Writable {
	
	public static Integer numBuckets;
	
	public static void write ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Main.k.channel ( );
		ByteBuffer b = ByteBuffer.wrap ( numBuckets ( ) );
		ch.write ( b );
		Main.k.interestOps ( SelectionKey.OP_READ );
		
	} // End method.
	
	/* The method numBuckets calculates the finite 'n' number of buckets for the storage of the subrange
	 * of numbers, this value is sent to the server and both create 'n' threads depending of the number
	 * previously calculated.
	 */
	
	public static byte [ ] numBuckets ( ) {
		
		numBuckets = ( int ) ( new Random ( ).nextDouble ( ) * 10 + 1 );
		return numBuckets.toString ( ).getBytes ( );
		
	} // End method.

} // End class.
