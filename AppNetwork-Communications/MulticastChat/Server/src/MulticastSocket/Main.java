package MulticastSocket;

import java.net.UnknownHostException;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.net.MulticastSocket;
import java.net.DatagramPacket;
import PrivateSocket.Private;
import java.net.InetAddress;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

	protected static ArrayList <String> aList;
	private static MulticastSocket s;
	public static InetAddress group;
	public static int ports, portc;
	public static String address;
	
	public static void main ( String [ ] args ) {
		
		Runnable t = ( ) -> { Private.PrivateServerSocket ( ); };
		new Thread ( t ).start ( );

		try {
			aList = new ArrayList <String> ( );
			System.setProperty ( "java.net.preferIPv4Stack", "true" );
			ports = 9000;
			portc = 9001;
			address = "230.1.1.1";
			s = new MulticastSocket ( ports );
			System.out.println ( "\n\tMulticast service initialized..." );
			group = null;
			try {
				group = InetAddress.getByName ( address );
			} catch ( UnknownHostException e ) {
				System.err.println ( "\n\tInvalid address." );
				System.exit ( 0 );
			} // End try - catch.
			s.joinGroup ( group );
			s.setTimeToLive ( 200 );
			for ( ; ; ) {
				DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
				s.receive ( p );
				String msg = new String ( p.getData ( ), 0, p.getLength ( ) );
				System.out.println ( "\n\tMessage received from: " + p.getAddress ( ) + " : " + p.getPort ( ) + "\n\tMessage: " + msg );
				Type ( msg );
				try {
					Thread.sleep ( 5000 );
				} catch ( InterruptedException ie ) { } // End try - catch.
			} // End for.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.	
		
	} // End main.
	
	/* The type of the message received from the client
	 * can be <msg>, <init> or <private>. If it's <msg>, the
	 * server will send the message to the common chat window, 
	 * <init> if a new user wants to join to the conversation,
	 * and <private> to open a personal chat with another user.
	 */
	
	public static void Type ( String msg ) throws IOException {
		
		String [ ] sp = msg.split ( " " );
		msg = "";
		
		if ( sp [ 0 ].equalsIgnoreCase ( "<init>" ) ) {
			String type = "<init>";
			String userName = "";
			byte [ ] b = type.getBytes ( );
			byte [ ] b1;
			String user;
			DatagramPacket p = new DatagramPacket ( b, b.length, group, portc );
			s.send ( p );
			for ( int i = 1 ; i < sp.length ; i++ ) {
				userName = userName + sp [ i ] + " ";  
			} // End for.
			aList.add ( userName );
			OnlineUsers ( );
			for ( int i = 0 ; i < aList.size ( ) ; i++ ) {
				user = aList.get ( i );
				b1 = user.getBytes ( );
				DatagramPacket p1 = new DatagramPacket ( b1, b1.length, group, portc );
				s.send ( p1 );
			} // End for.
		} // End if.
		
		if ( sp [ 0 ].equalsIgnoreCase ( "<msg>" ) ) {
			String type = "<msg>";
			String aux = "";
			byte [ ] b1 = type.getBytes ( );
			DatagramPacket p1 = new DatagramPacket ( b1, b1.length, group, portc );
			s.send ( p1 );
			for ( int i = 1 ; i < sp.length ; i++ ) {
				msg = msg + sp [ i ] + " ";  
			} // End for.
			aux = Emoticon ( msg );
			msg = aux;
			byte [ ] b = msg.getBytes ( );
			DatagramPacket p = new DatagramPacket ( b, b.length, group, portc );
			s.send ( p );
		} // End if.
		
		if ( sp [ 0 ].equalsIgnoreCase ( "<private>" ) ) {
			String msgFrom = sp [ sp.length - 1 ];
			String msgFor = "";
			for ( int i = 1 ; i < sp.length - 2 ; i++ ) {
				msgFor = msgFor + sp [ i ];  
			} // End for.
			System.out.println( "\n\tPrivate Message for: " + msgFor + ". From: " + msgFrom + "." );
			String type = "<private>";
			byte [ ] b = type.getBytes ( );
			DatagramPacket p = new DatagramPacket ( b, b.length, group, portc );
			s.send ( p );
			b = msgFrom.getBytes ( );
			DatagramPacket p1 = new DatagramPacket ( b, b.length, group, portc );
			s.send ( p1 );
			b = msgFor.getBytes ( );
			DatagramPacket p2 = new DatagramPacket ( b, b.length, group, portc );
			s.send ( p2 );
		} // End if.
		
	} // End Type.
	
	/* The client needs to know how man users are online, the method OnlineUsers
	 * gets the size of the arraylist, convert the integer into a byte array,
	 * and the server send the information as a datagram packet.
	 */
	
	public static void OnlineUsers ( ) throws IOException {
		
		int size = aList.size ( );
		ByteArrayOutputStream baos = new ByteArrayOutputStream ( );
		DataOutputStream dos = new DataOutputStream ( baos );
		dos.writeInt ( size );
		dos.flush ( );
		byte [ ] b = baos.toByteArray ( );
		DatagramPacket p = new DatagramPacket ( b, b.length, group, portc );
		s.send ( p );
		baos.close ( );
		dos.close ( );
		
	} // End OnlineUsers.
	
	/* Emoticon method search for the substring :), :D, :P, :*, ;) and :v, and replace those 
	 * substring for a HTML img label, this new string is sended to the client, and
	 * the JEditoPane detects the label ans search for the specified image URL.
	 */
	
	public static String Emoticon ( String msg ) {
		
		String smile = "<img src=https://4.bp.blogspot.com/-yKm9Ut8ivrM/WO4_inw5LDI/AAAAAAAAAL4/2mHIvQuQ0VQzha-Qdze0eBLTjJynyQ6swCLcB/s1600/smile.jpg>";		
		String tongue = "<img src =https://1.bp.blogspot.com/-Yha7BWFETLQ/WO4_jA2wesI/AAAAAAAAAL8/c_agpWNuceASznB8r39VM4yWdQ1SBRIIACLcB/s1600/tongue.jpg>";
		String pacman = "<img src =https://4.bp.blogspot.com/-cTSVg6w-nC0/WO4_iSJ-YwI/AAAAAAAAALs/ydOYFdGtWIQEZQDusm43FIYfJ9OutLD7QCLcB/s1600/pacman.png>";
		String happy = "<img src =https://4.bp.blogspot.com/-mtmUefTEVQE/WO4_iZLGT2I/AAAAAAAAALo/atK-68NJXi4NjQ0V2b-xx5io7jo0IG0XACLcB/s1600/happy.jpg>";
		String sad = "<img src =https://3.bp.blogspot.com/-InFa3OHlmL8/WO4_iinW5PI/AAAAAAAAALw/f0nKNKUB_b0_hGHDLJE_obLDSA1RzDbhQCLcB/s1600/sad.jpg>";
		String kiss = "<img src =https://1.bp.blogspot.com/-hUXG4mMs6vc/WO4_ieeS4_I/AAAAAAAAALk/lfopvxIAxyM3N-SQWMPyrZNQUPenGYS8QCLcB/s1600/kiss.jpg>";
		String rick = "<img src =https://4.bp.blogspot.com/-_KymSfA9VWM/WO4_ith6YYI/AAAAAAAAAL0/MFXPNfQz0fMBTmdT1bVcSUrJDxawRfMagCLcB/s1600/rick.jpg>";
		String aux = "";
		
		for ( int i = 0 ; i < msg.length ( ) ; i++ ) {
			if ( msg.charAt ( i ) == ':' ) {
				if ( msg.charAt ( i + 1 ) == 'D' ) {
					aux = aux + smile + " ";
					i += 2;
				} else if ( msg.charAt ( i + 1 ) == 'P' ) {
					aux = aux + tongue + " ";
					i += 2;
				} else if ( msg.charAt ( i + 1 ) == 'v' ) {
					aux = aux + pacman + " ";
					i += 2;
				} else if ( msg.charAt ( i + 1 ) == ')' ) {
					aux = aux + happy + " ";
					i += 2;
				} else if ( msg.charAt ( i + 1 ) == '*' ) {
					aux = aux + kiss + " ";
					i += 2; 
				} else if ( msg.charAt ( i + 1 ) == '(' ) {
					aux = aux + sad + " ";
					i += 2;
				} else {
					aux = aux + msg.charAt ( i );
				} // End nested if - else. 
			} else if ( msg.charAt ( i ) == '.' ) {
				if ( msg.charAt ( i + 1 ) == '|' ) {
					if ( msg.charAt ( i + 2 ) == '.' ) {
						aux = aux + rick + " ";
						i += 3;
					} else {
						aux = aux + msg.charAt ( i );
					} // End else - if.
				} else {
					aux = aux + msg.charAt ( i );
				} // End if - else.
			} else {
				aux = aux + msg.charAt ( i );
			} // End if - else.
		} // End for.
		
		return aux;
		
	} // End Emoticon.

} // End class.
