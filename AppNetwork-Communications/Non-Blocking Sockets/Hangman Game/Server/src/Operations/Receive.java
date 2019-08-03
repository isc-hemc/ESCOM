package Operations;

import java.nio.channels.SocketChannel;
import java.nio.ByteBuffer;
import Hangman.Answer;

public class Receive {
	
	public static String [ ] split;
	public static boolean flag2;
	public static boolean flag1;
	public static boolean flag;
	public static String recv;
	public static int n;
	
	public static void receive ( ) throws Exception {
		
		SocketChannel ch = ( SocketChannel ) Hangman.Main.k.channel ( );
		ByteBuffer b = ByteBuffer.allocate ( 100 );
		b.clear ( );
		n = ch.read ( b );
		b.flip ( );
		recv = new String ( b.array ( ), 0, n );
		split = recv.split ( " " );
		
		if ( split [ 0 ].equalsIgnoreCase ( "<difficult>" ) ) {
			Integer port = ch.socket ( ).getPort ( );
			Hangman.Main.difficult.put ( port, split [ 1 ] );
			if ( split [ 1 ].equalsIgnoreCase ( "easy" ) ) {
				String str = "H*__o Wo$_d";
				Hangman.Main.hm.put ( ch.socket ( ).getPort ( ), str );
			} else {
				String str = "_**l.c_t.#ns f#r N?tw#rk C#¿¿un.c_t.#ns";
				Hangman.Main.hm.put ( ch.socket ( ).getPort ( ), str );
			} // End nested if - else.
			flag1 = true;
		} // End if.
		
		if ( split [ 0 ].equalsIgnoreCase ( "<answer>" ) ) {
			flag = Answer.Compare ( split [ 1 ], ch.socket ( ).getPort ( ) );
		} // End if.
		
		if ( Hangman.Main.hm.get ( ch.socket ( ).getPort ( ) ).equalsIgnoreCase ( Hangman.Main.easy ) ) {
			flag2 = true;
		} // End if.
		if ( Hangman.Main.hm.get ( ch.socket ( ).getPort ( ) ).equalsIgnoreCase ( Hangman.Main.hard ) ) {
			flag2 = true;
		} // End if.
		
	} // End Receive.

} // End class.
