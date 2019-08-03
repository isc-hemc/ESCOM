package Operations;

import java.nio.channels.SocketChannel;
import java.nio.ByteBuffer;

public class Write {
	
	public static boolean flag;
	
	public static void write ( ) throws Exception {
			
			if ( Receive.flag1 ) {
				SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
				String str = Hangman.Main.hm.get ( ch.socket ( ).getPort ( ) );
				ByteBuffer b = ByteBuffer.wrap ( str.getBytes ( ) );
				ch.write ( b );
				Receive.flag1 = false;
			} else if ( Receive.flag2 ) {
				SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
				String str = "Congratulations: " + Hangman.Main.hm.get ( ch.socket ( ).getPort ( ) );
				ByteBuffer b = ByteBuffer.wrap ( str.getBytes ( ) );
				ch.write ( b );
				Hangman.Main.k.cancel ( );
				ch.socket ( ).close ( );
				Receive.flag2 = false;
			} else {
				if ( Receive.flag ){
					SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
					String str = Hangman.Main.hm.get ( ch.socket ( ).getPort ( ) );
					ByteBuffer b = ByteBuffer.wrap ( str.getBytes ( ) );
					ch.write ( b );
					Receive.flag = false;
				} else {
					SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
					String str = "Try again.";
					ByteBuffer b = ByteBuffer.wrap ( str.getBytes ( ) );
					ch.write ( b );
				} // End nested if - else.
			} // End if - else.
			
		} // End Write.

} // End class.
