package Operations;

import java.nio.ByteBuffer;
import java.nio.channels.*;
import Main.Main;

/* When the sub servers finish the initialization, this class sent to the client the list
 * of the ports that the sub clients must bind.
 */

public class Writable {
	
	private static String wr;
	
	public static void write ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Main.k.channel ( );
		wr = "";
		
		for ( int i = 0 ; i < Readable.portsList.length ; i++ ) {
			if ( i != Readable.portsList.length - 1 ) {
				wr = wr + Readable.portsList [ i ] + " ";
			} else {
				wr = wr + Readable.portsList [ i ];
			} // End if.
		} // End for.
		
		ByteBuffer b = ByteBuffer.wrap ( wr.getBytes ( ) );
		ch.write ( b );
		
		Main.k.interestOps ( SelectionKey.OP_READ );
		
	} // End method.
	
} // End class.
