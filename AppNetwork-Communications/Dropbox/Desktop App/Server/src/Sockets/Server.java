package Sockets;

import java.net.*;

public class Server {

	private ServerSocket s;
	private Integer port;
	private Socket cl;
	
	public Server ( ) { }

	public Server ( Integer port ) {
		
		this.port = port;
		
	} // End constructor.
	
	public boolean initSocket ( ) {
		
		try {
			this.s = new ServerSocket ( this.port );
			s.setReuseAddress ( true );
			return true;
		} catch ( Exception e ) {
			return false;
		} // End try - catch.

	} // End method.
	
	public void accept ( ) throws Exception {
		
		this.cl = this.s.accept ( );
		this.cl.setSoLinger ( true, 10 );
		System.out.println ( "\t\tClient TCP accepted from: " + this.cl.getInetAddress ( ).getHostAddress ( ) + ":" + this.cl.getPort ( ) + ". Local port: " + s.getLocalPort ( ) + "." );
		
	} // End method.
		
	public ServerSocket getServer ( ) { 
		return this.s; 
	} // End getter.
	
	public Socket getClient ( ) {
		return this.cl;
	} // End getter.
	
	public Integer getPort ( ) { 
		return this.port; 
	} // End getter.
	
} // End class.
