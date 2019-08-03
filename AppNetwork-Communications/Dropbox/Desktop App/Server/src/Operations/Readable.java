package Operations;

import java.nio.ByteBuffer;
import java.nio.channels.*;
import Sockets.*;
import Main.*;

public class Readable {
	
	private static SocketChannel ch;
	private static String [ ] split;
	public static String directory;
	private static ByteBuffer b;
	private static String recv;
	private static int n;

	public static void read ( ) throws Exception {
		
		ch = ( SocketChannel ) Main.k.channel ( );
		b = ByteBuffer.allocate ( 1000 );
		b.clear ( );
		n = ch.read ( b );
		b.flip ( );
		recv = new String ( b.array ( ), 0, n );
		split = recv.split ( ":" );
		
		if ( split [ 0 ].equalsIgnoreCase ( "<login>" ) ) {
			/* Receive a log in request and the client send the email ( split [ 1 ] ) and the password ( split [ 2 ] ). */
			if ( Queries.logIn ( split [ 1 ], split [ 2 ] ) ) {
				Writable.logInFlag = true;
			} else {
				Writable.logInFlag = false;
			} // End if.
		} // End if.
		if ( split [ 0 ].equalsIgnoreCase ( "<signin>" ) ) {
			/* Receive a sign in request, to store in the database the client send the name ( split [ 1 ] ) the last name
			 * ( split [ 2 ] ) the nickname ( split [ 3 ] ) the email ( split [ 4 ] ) and the password ( split [ 5 ] ).
			 */
			User u = new User ( split [ 1 ], split [ 2 ], split [ 3 ], split [ 4 ], split [ 5 ] );
			Queries.signIn ( u );
		} // End if.
		if ( split [ 0 ].equalsIgnoreCase ( "<download>" ) ) {
			/* Receive a request of download a file and the nickname of the user that its requesting the service
			 * ( split [ 1 ] ) and the file name ( split [ 2 ] ). 
			 */
			sendFile.download ( Main.hm.get ( split [ 1 ] ).getServer ( ), split [ 2 ] );
		} // End if.
		if ( split [ 0 ].equalsIgnoreCase ( "<store>" ) ) {
			/* Receive a request of store a new file, and receive the nickname of the user ( split [ 1 ] ). */
			recvFile.recv ( Main.hm.get ( split [ 1 ] ).getServer ( ), split [ 1 ] );
		} // End if.
		if ( split [ 0 ].equalsIgnoreCase ( "<filelist>" ) ) {
			/* Receive from the client the nickname of the user that its requesting for his file list ( split [ 1 ] ). */
			Writable.u = Main.hm.get ( split [ 1 ] );
			Writable.sendFilesFlag = true;
			directory = split [ 2 ];
		} // End if.
		if ( split [ 0 ].equalsIgnoreCase ( "<sharedocuments>" ) ) {
			/* Receive from the client the nickname ( split [ 1 ] ), the friend nickname ( split [ 2 ] ) who want to share 
			 * his documents with and the directory name ( split [ 3 ] ) that wants to share.
			 */
			Queries.shareDocuments ( split [ 1 ], split [ 2 ], split [ 3 ] );
		} // End if.
		if ( split [ 0 ].equalsIgnoreCase ( "<delete>" ) ) {
			/* Receive from the client the nickname ( split [ 1 ] ), the file to delete ( split [ 2 ] ) and the directory
			 * where the file is stored ( split [ 3 ] ).
			 */
			Queries.deleteDocuments ( split [ 1 ], split [ 2 ], split [ 3 ] ) ;
		} // End if.
	} // End method. 
	
} // End class.
