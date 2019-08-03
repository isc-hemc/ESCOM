package Main;

import GUI.*;

public class Main {

	public static void main ( String [ ] args ) throws Exception {
	
	SocketClient cl = new SocketClient ( );
	cl.Launch ( );
	LogIn li = new LogIn ( );
	li.init ( );
	
	} // End main.
	
} // End class.
