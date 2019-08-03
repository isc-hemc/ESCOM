package Main;

import java.nio.channels.*;
import java.util.Iterator;
import java.util.Random;
import java.net.*;

/* The class Main only contains and initialized the principal non-blocking client,
 * this client connects with a NB server, and sends the number of buckets that the
 * server must be prepared to receive.
 */

public class Main {
	
	public static Iterator <SelectionKey> it;
	public static SocketChannel cl;
	public static int [ ] numList;
	public static SelectionKey k;
	public static Selector sel;
	public static String host;
	public static int ports;
	
	public static void init ( ) throws Exception {
		
		cl = SocketChannel.open ( );
		cl.configureBlocking ( false );
		cl.connect ( new InetSocketAddress ( host, ports ) );
		sel = Selector.open ( );
		cl.register( sel, SelectionKey.OP_CONNECT );
		
	} // End method.
	
	public static void numList ( ) {
		
		numList = new int [ 3500 ];
		for ( int i = 0 ; i < 3500 ; i++ ) {
			numList [ i ] = ( int ) ( new Random ( ).nextDouble ( ) * 1000 + 1 );
		} // End for.
		
	} // End method.

	public static void main ( String [ ] args ) {
		
		try {
			host = "127.0.0.1";
			ports = 9710;
			init ( );
			numList ( );
			for ( ; ; ) {
				sel.select ( );
				it = sel.selectedKeys ( ).iterator ( );
				while ( it.hasNext ( ) ) {
					k = ( SelectionKey ) it.next ( );
					it.remove ( );
					if ( k.isConnectable ( ) ) {
						Operations.Connect.connect ( );
						continue;
					} // End if.
					if ( k.isReadable ( ) ) {
						Operations.Readable.read ( );
						Thread.sleep ( 10000 * 10000 );
						continue;
					} // End if.
					else if ( k.isWritable ( ) ) {
						Operations.Writable.write ( );
						continue;
					} // End if.
				} // End while.
			} // End forever.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End main
	
} // End class.
