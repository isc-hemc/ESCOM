package Operations;

import java.nio.ByteBuffer;
import java.nio.channels.*;

public class Write {
	
	public static String difficult;
	
	public static void write ( ) throws Exception {
		
		if ( Hangman.Main.flag ) {
			SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
			ByteBuffer b;
			String difficult = "";
			while ( difficult.equalsIgnoreCase ( "easy" ) == false && difficult.equalsIgnoreCase ( "hard" ) == false ) {
				System.out.print( "\tSelect option: " );
				difficult = Hangman.Main.br.readLine ( );
			} // End while.
			if ( difficult.equalsIgnoreCase ( "easy" ) ) {
				Hangman.Main.attempts = 3;
			} else {
				Hangman.Main.attempts = 1;
			} // End if - else.
			difficult = "<difficult> " + difficult;
			b = ByteBuffer.wrap ( difficult.getBytes ( ) );
			ch.write ( b );
			Hangman.Main.k.interestOps ( SelectionKey.OP_READ );
			Hangman.Main.flag = false;
		} else {
			SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
			ByteBuffer b;
			System.out.print ( "\n\tAnswer: " );
			String str = "<answer> " + Hangman.Main.br.readLine ( );
			b = ByteBuffer.wrap ( str.getBytes ( ) );
			ch.write ( b );
			Hangman.Main.k.interestOps ( SelectionKey.OP_READ );
		} // End if - else.
		
	} // End write.

} // End class.
