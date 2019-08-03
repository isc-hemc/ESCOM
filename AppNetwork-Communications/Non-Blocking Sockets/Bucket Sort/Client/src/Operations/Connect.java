package Operations;

import java.nio.channels.*;
import Main.Main;

public class Connect {
	
	public static void connect ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Main.k.channel ( );
		if ( ch.isConnectionPending ( ) ) {
			ch.finishConnect ( );
		} // End if.
		ch.register ( Main.sel, SelectionKey.OP_READ | SelectionKey.OP_WRITE );
		
	} // End method.

} // End class.
