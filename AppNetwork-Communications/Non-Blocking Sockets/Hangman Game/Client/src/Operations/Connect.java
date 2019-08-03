package Operations;

import java.nio.channels.SelectionKey;
import java.nio.channels.SocketChannel;

public class Connect {
		
	public static void Connection ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
		if ( ch.isConnectionPending ( ) ) {
			ch.finishConnect ( );
			Menu ( );
		} // End if.
		ch.register ( Hangman.Main.sel, SelectionKey.OP_READ | SelectionKey.OP_WRITE );
		Hangman.Main.flag = true;
		
	} // End Connection.

	public static void Menu ( ) {
		
		System.out.println ( "\n\n\t\tHANGMAN GAME:" );
		System.out.println ( "\n\tSelect one of the following options:" );
		System.out.println ( "\t1.- Easy." );
		System.out.println ( "\t2.- Hard." );

	} // End Menu.
	
} // End Connect.
