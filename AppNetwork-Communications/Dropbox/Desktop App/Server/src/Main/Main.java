package Main;

import java.nio.channels.*;
import java.util.Iterator;
import Operations.Queries;
import java.util.HashMap;
import Database.*;

import java.net.*;

public class Main {

	public static Iterator <SelectionKey> it;
	public static HashMap <String, User> hm;
	public static ServerSocketChannel ssc;
	public static SelectionKey k;
	public static DataAccess da;
	public static Selector sel;
	public static int port;
	
	public static void init ( ) throws Exception {
		
		ssc = ServerSocketChannel.open ( );
		ssc.configureBlocking ( false );
		ssc.setOption ( StandardSocketOptions.SO_REUSEADDR, true );
		port = 9710;
		ssc.socket ( ).bind ( new InetSocketAddress ( port ) ); 
		sel = Selector.open ( );
		ssc.register ( sel, SelectionKey.OP_ACCEPT );
		da = new DataAccess ( );
		hm = new HashMap <String, User> ( );
		
	} // End init. 
	
	public static void main ( String [ ]  args ) {
		
		try {
			init ( );
			Queries.clientObjects ( );
			for ( ; ; ) {
				try {
					sel.select ( );
					it = sel.selectedKeys ( ).iterator ( );
					while ( it.hasNext ( ) ) {
						k = ( SelectionKey ) it.next ( );
						it.remove ( );
						if ( k.isAcceptable ( ) ) {
							Operations.Acceptable.accept ( ssc );
							continue;
						} // End if.
						if ( k.isReadable ( ) ) {
							Operations.Readable.read ( );
							k.interestOps ( SelectionKey.OP_WRITE );
							continue;
						} // End if.
						if ( k.isWritable ( ) ) {
							Operations.Writable.write ( );
							k.interestOps ( SelectionKey.OP_READ );
							continue;
						} // End if.
					} // End while.
				} catch ( Exception e ) { } // End try - catch.
			} // End forever.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End main.

} // End class. 
