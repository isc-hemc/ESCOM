package Sockets;

import java.net.UnknownHostException;
import java.io.IOException;
import java.net.Socket;

public class Client {
	
	public Socket cl;
	public String host;
	public Integer port;
	
	public Client ( String h, Integer port ) {
		
		this.host = h;
		this.port = port;
		
	} // End Constructor.
	
	public void connect ( ) throws UnknownHostException, IOException {
		this.cl = new Socket ( this.host, this.port );
		System.out.println ( "\n\t\tTCP socket service succesfully initialized... " + cl.getInetAddress ( ).getHostAddress ( ) + ":" + cl.getPort ( ) );
	} // End method.
	
	public String getHost ( ) {
		return this.host;
	} // End getHost method.
	
	public int getPort ( ) {
		return this.port;
	} // End getPort method.
	
	public Socket getSocket ( ) {
		return this.cl;
	} // End method.
		
} // End Client class.
