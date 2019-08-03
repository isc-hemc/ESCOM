package Operations;

import java.nio.channels.*;
import Main.*;

public class Acceptable {
	
	protected static SocketChannel sc;
	
	public static void accept ( ServerSocketChannel ssc ) throws Exception {
		
		sc = ssc.accept ( );
	    System.out.println ( "\n\tClient accepted from: " + sc.socket ( ).getInetAddress ( ).getHostAddress ( ) + " : " + sc.socket ( ).getPort ( ) );
	    sc.configureBlocking ( false );
	    sc.register ( Main.sel, SelectionKey.OP_READ );
	    
	} // End accept.

} // End class.
