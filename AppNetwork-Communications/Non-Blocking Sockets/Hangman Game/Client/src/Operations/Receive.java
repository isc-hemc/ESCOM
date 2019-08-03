package Operations;

import java.nio.channels.SelectionKey;
import java.nio.channels.SocketChannel;
import java.nio.ByteBuffer;

public class Receive {
	
	public static int n;
	
	public static void receive ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
		ByteBuffer b = ByteBuffer.allocate ( 100 );
		b.clear ( );
		n = ch.read ( b );
		b.flip ( );
		String str = new String ( b.array ( ), 0, n );
		if ( str.equalsIgnoreCase ( "Try again." ) ) {
			Hangman.Main.attempts++;
		} else {
			System.out.println ( "\n\t" + str );
		} // End if - else.
		
		if ( str.equalsIgnoreCase ( "Congratulations: " + Hangman.Main.easy ) ) {
			System.exit ( 0 );
		} // End if.
		if ( str.equalsIgnoreCase ( "Congratulations: " + Hangman.Main.hard ) ) {
			System.exit ( 0 );
		} // End if.

		Hangman.Main.k.interestOps ( SelectionKey.OP_WRITE );
		
	} // End receive.

} // End class.
