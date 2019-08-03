package Hangman;

import java.nio.channels.*;
import java.util.Iterator;
import Operations.*;
import java.net.*;
import java.io.*;

public class Main {
	
	private static Iterator <SelectionKey> it;
	public static BufferedReader br;
	private static SocketChannel cl;
	public static SelectionKey k;
	public static Selector sel;
	public static boolean flag;
	private static String host;
	public static int attempts;
	public static String easy;
	public static String hard;
	private static int port;
	
	public static void Init ( ) throws Exception {
		
		host = "127.0.0.1";
		port = 9709;
		br = new BufferedReader ( new InputStreamReader ( System.in ) );
		cl = SocketChannel.open ( );
		cl.configureBlocking ( false );
		sel = Selector.open ( );
		cl.connect ( new InetSocketAddress ( host, port ) );
		easy = "Hello World";
		hard = "Applications for network communications";
		cl.register ( sel, SelectionKey.OP_CONNECT );
		
	} // End Init.

	public static void main ( String [ ] args ) {
		
		try {
			Init ( );
			while ( true ) {
				sel.select ( );
				it = sel.selectedKeys ( ).iterator ( );
				while ( it.hasNext ( ) ) {
					k = ( SelectionKey ) it.next ( );
					it.remove ( );
					if ( k.isConnectable ( ) ) {
						Connect.Connection ( );
						continue;
					} // End if.
					if ( k.isReadable ( ) ) {
						Receive.receive ( );
						continue;
					} // End if.
					if ( k.isWritable ( ) ) {
						Write.write ( );
						continue;
					} // End if.
				} // End while.
			} // End while.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End main.

} // End class.
