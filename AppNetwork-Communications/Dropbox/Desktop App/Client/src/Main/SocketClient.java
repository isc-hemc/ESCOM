package Main;

import java.nio.channels.*;
import java.net.*;

public class SocketClient {
	
	public static SocketChannel cl;
	private static String host;
	private static int port;
	
	public void Launch ( ) throws Exception {
		
		host = "127.0.0.1";
		port = 9710;
		cl = SocketChannel.open ( );
		cl.configureBlocking ( false );
		cl.connect ( new InetSocketAddress ( host, port ) );
		
		if ( cl.isConnectionPending ( ) ) {
			cl.finishConnect ( );
		} // End if.
		
	} // End Launch.
	
} // End class.
