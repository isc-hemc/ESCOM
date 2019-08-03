package ClientSocket;

import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;

public class Client {
	
	public static MulticastSocket cl;
	public static int portc, ports;
	public static String address;
	public static InetAddress group;
	
	public void Launch ( ) {
		
		try { 
			System.setProperty ( "java.net.preferIPv4Stack", "true" );
			ports = 9000;
			portc = 9001;
			address = "230.1.1.1";
			cl = new MulticastSocket ( portc );
			group = null;
			try {
				group = InetAddress.getByName ( address );
			} catch ( UnknownHostException e ) {
				System.err.println ( "\n\tInvalid Address." );
				System.exit ( 0 );
			} // End try - catch.
			cl.joinGroup ( group );
			cl.setTimeToLive ( 200 );
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
	
	} // End Launch.

} // End class.
