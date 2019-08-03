package Main;

import java.net.StandardSocketOptions;
import java.net.InetSocketAddress;
import java.nio.channels.*;
import java.util.Iterator;

/* The class Main only contains and initialized the principal non-blocking server,
 * this server connects with NB clients, and receives the number of buckets that
 * the server must be prepared to create.
 */

public class Main {
	
	public static Iterator <SelectionKey> it;
	public static ServerSocketChannel ssc;
	public static SelectionKey k;
	public static Selector sel;
	public static String host;
	public static int ports;
	
	public static void init ( ) throws Exception {
		
		ssc = ServerSocketChannel.open ( );
		ssc.configureBlocking ( false );
		ssc.setOption ( StandardSocketOptions.SO_REUSEADDR, true );
		ssc.socket ( ).bind ( new InetSocketAddress ( ports ) );
		sel = Selector.open ( );
		ssc.register ( sel, SelectionKey.OP_ACCEPT );
		
	} // End method.

	public static void main ( String [ ] args ) {
		
		try {
			host = "127.0.0.1";
			ports = 9710;
			init ( );
			for ( ; ; ) {
				try {
					sel.select ( );
					it = sel.selectedKeys ( ).iterator ( );
					while ( it.hasNext ( ) ) {
						k = ( SelectionKey ) it.next ( );
						it.remove ( );
						if ( k.isAcceptable ( ) ) {
							Operations.Acceptable.accept ( );
							continue;
						} // End if.
						if ( k.isReadable ( ) ) {
							Operations.Readable.read ( );
							continue;
						} // End if.
						if ( k.isWritable ( ) ) {
							Operations.Writable.write ( );
							continue;
						} // End if.
					} // End while.
				} catch ( Exception e1 ) { }
			} // End forever.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End main.
	
} // End class.
