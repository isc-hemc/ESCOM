package PrivateSocket;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import MulticastSocket.Main;
import java.net.InetAddress;
import java.util.Hashtable;

public class Private {
	
	protected static Hashtable <String, Integer> ht;
	protected static String host;
	private static DatagramSocket s;

	public static void PrivateServerSocket ( ) {
		
		ht = new Hashtable <String, Integer> ( );
		host = "127.0.0.1";
		
		try {
			int port = 9709;
			s = new DatagramSocket ( port );
			System.out.println ( "\n\tPrivate Service initialized..." );
			for ( ; ; ) {
				DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
				s.receive ( p );
				String pmsg = new String ( p.getData ( ), 0, p.getLength ( ) );
				System.out.println ( "\n\tPrivate message received from: " + p.getAddress ( ) + " : " + p.getPort ( ) + "\n\tMessage: " + pmsg );
				String [ ] s = pmsg.split ( " " ); 
				String msg = "";
				
				if ( s [ 0 ].equalsIgnoreCase ( "<init>" ) ) {
					for ( int i = 1 ; i < s.length ; i++ ) {
						msg = msg + s [ i ];
					} // End for.
					Init ( p, msg );
				} // End if.
				
				if ( s [ 0 ].equalsIgnoreCase ( "<msg>" ) ) {
					for ( int i = 2 ; i < s.length ; i++ ) {
						msg = msg + s [ i ] + " ";
					} // End for.
					Message ( p, msg, s [ 1 ] );
				} // End if.
				
			} // End forever.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End PrivateServerSocket.
	
	public static void Init ( DatagramPacket p, String user ) {
		
		ht.put ( user, p.getPort ( ) );
		
	} // End Init.
	
	public static void Message ( DatagramPacket p, String msg, String user ) throws Exception {
		
		msg = Main.Emoticon ( msg );
		byte [ ] b = msg.getBytes ( ); 
		DatagramPacket p1 = new DatagramPacket ( b, b.length, p.getAddress ( ), p.getPort ( ) );
		s.send ( p1 );
		p = new DatagramPacket ( b, b.length, InetAddress.getByName ( host ), ht.get ( user ) );
		s.send ( p );
		
	} // End Message.

} // End Private class.
