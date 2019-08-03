package Hangman;

import java.nio.channels.*;
import java.util.Iterator;
import java.util.HashMap;
import Operations.*;
import java.net.*;

public class Main {
	
	public static HashMap <Integer, String> difficult;
	public static HashMap <Integer, String> hm;
	private static Iterator <SelectionKey> it;
	private static ServerSocketChannel ssc;
	public static Selector selector;
	public static SelectionKey k;
	public static String easy;
	public static String hard;
	public static int port;
	
	public static void Init ( ) throws Exception {
		
		difficult = new HashMap <Integer, String> ( );
		hm = new HashMap <Integer, String> ( );
		ssc = ServerSocketChannel.open ( );
		ssc.configureBlocking ( false );
		ssc.setOption ( StandardSocketOptions.SO_REUSEADDR, true );
		port = 9709;
		ssc.socket ( ).bind ( new InetSocketAddress ( port ) );
		selector = Selector.open ( );
		ssc.register ( selector, SelectionKey.OP_ACCEPT );
		easy = "Hello World";
		hard = "Applications for network communications";
		System.out.println ( "\n\n\tHangman Game... waiting for players." );

	} // End Init.
	
	public static void main ( String [ ] args ) {
		
		try {
			Init ( );
			for ( ; ; ) {
				try {
					selector.select ( );
					it = selector.selectedKeys ( ).iterator ( );
					while ( it.hasNext ( ) ) {
						k = ( SelectionKey ) it.next ( );
						it.remove ( );
						if ( k.isAcceptable ( ) ) {
							Accept.acceptClient ( ssc );
							continue;
						} // End if.
						if ( k.isReadable ( ) ) {
							Receive.receive ( );
							k.interestOps ( SelectionKey.OP_WRITE );
							continue;
						} else if ( k.isWritable ( ) ) {
							Write.write ( );
							k.interestOps ( SelectionKey.OP_READ );
							continue;
						} // End if - else.
					} // End while.
				} catch ( Exception cke ) { } // End try - catch.
			} // End forever.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch;
		
	} // End main.

} // End class.