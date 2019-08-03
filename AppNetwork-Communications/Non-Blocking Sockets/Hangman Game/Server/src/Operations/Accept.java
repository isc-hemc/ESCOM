package Operations;

import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.channels.SelectionKey;
import Hangman.Main;

public class Accept {
	
	protected static SocketChannel sc;

	public static void acceptClient ( ServerSocketChannel ssc ) throws Exception {
		
		sc = ssc.accept ( );
	    System.out.println ( "\tPlayer accepted from: " + sc.socket ( ).getInetAddress ( ).getHostAddress ( ) + " : " + sc.socket ( ).getPort ( ) );
	    sc.configureBlocking ( false );
	    sc.register ( Main.selector, SelectionKey.OP_READ );
		
	} // End accepClient.

} // End class.
