package Operations;

import java.nio.channels.*;
import Main.Main;

public class Acceptable {

	public static void accept ( ) throws Exception {
		
		SocketChannel sc = Main.ssc.accept ( );
		sc.configureBlocking ( false );
		sc.register ( Main.sel, SelectionKey.OP_READ );
		System.out.println ( "\n\n\tClient accepted from: " + sc.socket ( ).getInetAddress ( ).getHostAddress ( ) + " : " + sc.socket ( ).getPort ( ) + "." );
		
	} // End method.
	
} // End class.
