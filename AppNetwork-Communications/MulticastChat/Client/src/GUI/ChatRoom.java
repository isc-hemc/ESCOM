package GUI;

import java.awt.event.ActionListener;
import javax.swing.DefaultListModel;
import java.io.ByteArrayInputStream;
import java.awt.event.MouseAdapter;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import java.net.DatagramPacket;
import javax.swing.JScrollPane;
import javax.swing.JEditorPane;
import java.io.DataInputStream;
import javax.swing.JTextField;
import javax.swing.ImageIcon;
import java.net.InetAddress;
import java.io.IOException;
import ClientSocket.Client;
import java.util.ArrayList;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import java.awt.Image;
import java.awt.Color;
import java.awt.Font;

public class ChatRoom extends JFrame implements ActionListener, Runnable {

	private static final long serialVersionUID = 1L;
	public static DefaultListModel <String> dlm;
	public static JList <String> onlineUsers;
	protected static JScrollPane scroller1;
	public static ArrayList <String> aList;
	protected static JScrollPane scroller;
	protected static String username;
	public static String privateMsg;
	protected static JEditorPane ep;
	protected static JTextField tf;
	protected static JLabel label;
	protected static JLabel logo;
	public static int counter;
	public static String aux;
	public static String un;
	public static Thread t;
	
	public ChatRoom ( String s ) {
		
		super ( "TeamWork-Chat" );
		this.getContentPane ( ).setBackground( Color.white );
		dlm = new DefaultListModel <String> ( );
		onlineUsers = new JList <String> ( dlm );
		aList = new ArrayList <String> ( );
		label = new JLabel ( "Online Users:" );
		ep = new JEditorPane ( );
		t = new Thread ( this );
		tf = new JTextField ( );
		logo = new JLabel ( );
		scroller1 = new JScrollPane ( onlineUsers, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER );
		scroller = new JScrollPane ( ep, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER );
		un = s + ":";
		username = s;
		counter = -1;
		t.start ( );
		aux = "";
		
	} // End constructor.

	public void Components ( ) {
		
		setDefaultCloseOperation ( JFrame.EXIT_ON_CLOSE );
		setLocationRelativeTo ( null );
		setResizable ( false );
		setSize ( 400, 400 );
		setVisible ( true );
		setLayout ( null );
		Logotype ( );
		Attributes ( );
		
	} // End Components.
	
	public void Attributes ( ) {
		
		/* Attributes. */
		onlineUsers.setBounds ( 300, 125, 70, 160 );
		scroller1.setBounds ( 300, 125, 80, 170 );
		scroller.setBounds ( 20, 20, 260, 280 );
		label.setBounds ( 300, 80, 120, 50 );
		logo.setBounds ( 300, 10, 90, 70 );
		tf.setBounds ( 15, 330, 270, 20 );

		onlineUsers.setForeground ( Color.LIGHT_GRAY );
		tf.setForeground ( Color.blue );
		ep.setForeground ( Color.blue );
		
		onlineUsers.setFont ( new Font ( "Comic Sans MS", Font.BOLD, 12 ) );
		tf.setFont ( new Font ( "Comic Sans MS", Font.BOLD, 12 ) );
		ep.setFont ( new Font ( "Comic Sans MS", Font.BOLD, 12 ) );
		label.setFont ( new Font ( "Helvetica", Font.BOLD, 14 ) );
		
		/* Mouse event listener. */
		onlineUsers.addMouseListener ( new MouseAdapter ( ) {
			public void mouseClicked ( MouseEvent event ) {
				JList list = ( JList ) event.getSource ( );
				if ( event.getClickCount() == 2 ) {
					int index = list.locationToIndex( event.getPoint ( ) );
					String msgFor = ( String ) list.getModel ( ).getElementAt ( index );
					privateMsg = "<private> " + list.getModel ( ).getElementAt ( index ) + "from " + username;
					counter++;
					try {
						PrivateMessage ( msgFor );
					} catch (IOException e) {
						e.printStackTrace();
					} // End try - catch.
				} // End if.
			} // End method.
		} );
		
		ep.setContentType( "text/html" );
		onlineUsers.setModel ( dlm );
		ep.setEditable ( false );

		add ( scroller1 );
		add ( scroller );
		add ( label );
		add ( logo );
		add ( tf );
		
		/* Action Performed. */
		tf.addActionListener ( this );
		
	} // End Attributes.
	
	/* When the user press the enter key in the TextField "tf",
	 * the messages will be sended to the server with a type of
	 * message, in this case will be "<msg>" for message in 
	 * the common chat room.
	 */
	
	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == tf ) {
			String s = tf.getText ( );
			s = "<msg> " + un + " " + s;
			byte [ ] b = s.getBytes ( );
			try {
				DatagramPacket p = new DatagramPacket ( b, b.length, Client.group, Client.ports );
				Client.cl.send ( p );
			} catch ( Exception e1 ) {
				e1.printStackTrace ( );
			} // End try - catch.
			tf.setText( "" );
		} // End if.
		
	} // End actionPerformed.
	
	public void Logotype ( ) {
		
		ImageIcon ic = new ImageIcon ( "Logo.png" );
		Image im = ic.getImage ( );
		ImageIcon ic1 = new ImageIcon ( im.getScaledInstance ( 90, 70, Image.SCALE_SMOOTH ) );
		logo.setIcon ( ic1 );
		
	} // End Logotype.

	/* This thread will be waiting the datagrams in a for ever loop from the server,
	 * in the thread there is a auxiliar string that concatenates all the messages,
	 * this string it's the one that the EditorPane will display. Also will update the
	 * online users list.
	 */
	
	@Override
	public void run ( ) {

		for ( ; ; ) {
			/* Receive the type of the datagram packet; <msg>, <init> or <private>,
			 * depending the message there is an if sentence for any case.
			 */
			String type = "";
			try {
				DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
				Client.cl.receive ( p );
				type = new String ( p.getData ( ), 0, p.getLength ( ) );
			} catch (IOException e) {
				e.printStackTrace();
			} // End try - catch.
			
			if ( type.equalsIgnoreCase ( "<init>" ) ) {
				dlm.clear ( );
				aList.clear ( );
				try {
					int numUsers = OnlineUsers ( );
					String user = "";
					for ( int i = 0 ; i < numUsers ; i++ ) {
						DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
						Client.cl.receive ( p );
						user = new String ( p.getData ( ), 0, p.getLength ( ) );
						aList.add ( user );
						dlm.addElement ( aList.get ( i ) );
					} // End for.
				} catch (IOException e) {
					e.printStackTrace();
				} // End try - catch.
				
			} // End if.

			if ( type.equalsIgnoreCase ( "<msg>" ) ) {
				String msg = "";
				try {
					DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
					Client.cl.receive ( p );
					msg = new String ( p.getData ( ), 0, p.getLength ( ) );
					System.out.println ( "\n\tMessage received from: " + p.getAddress ( ) + " : " + p.getPort ( ) + "\n\tMessage: " + msg );
				} catch ( IOException e ) {
					e.printStackTrace();
				} // End try - catch.
				aux = aux + msg + "<BR>";
				ep.setText ( aux );
			} // End if.
			
			if ( type.equalsIgnoreCase ( "<private>" ) ) {
				DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
				String msgFrom = "";
				String msgFor = "";
				try {
					Client.cl.receive ( p );
					msgFrom = new String ( p.getData ( ), 0, p.getLength ( ) );
					p = new DatagramPacket ( new byte [ 1500 ], 1500 );
					Client.cl.receive ( p );
					msgFor = new String ( p.getData ( ), 0, p.getLength ( ) );
				} catch ( IOException e ) {
					e.printStackTrace();
				} // End try - catch.
				System.out.println( "\n\tPrivate Message for: " + msgFor + ". From: " + msgFrom + "." );
				if ( msgFor.equalsIgnoreCase ( username ) ) {
					Private pmsg = new Private ( );
					String s = "<init> <" + username + ">";
					byte [ ] b = s.getBytes ( );
					try {
						p = new DatagramPacket ( b, b.length, InetAddress.getByName ( Private.host ), Private.ports );
						Private.cl.send ( p );
					} catch ( Exception e ) {
						e.printStackTrace();
					} // End try - catch.
					pmsg.Components ( username, msgFrom );
				} // End if.
			} // End if.
			
		} // End forever.
		
	} // End Thread.
	
	/* Method called from the thread, avoid the client to know how many users
	 * are online, the information it's sended by the server, the method returns
	 * an integer an it will be the number of packets that the client must 
	 * expect receive from the server.
	 */
	
	public static int OnlineUsers ( ) throws IOException {
		
		int numUsers = 0;
		DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
		Client.cl.receive ( p );
		ByteArrayInputStream bais = new ByteArrayInputStream ( p.getData ( ) );
		DataInputStream dis = new DataInputStream ( bais );
		numUsers = ( int ) dis.readInt ( );
		
		return numUsers;
		
	} // End OnlineUsers.
	
	/* Method called from a nested method if the program detect a mouse event,
	 * send a string to the socket with the label "<private>", opens a new
	 * JDialog for private texting with another user. At the same time sends a
	 * message to the UDP socket server with the label <init> to store the port,
	 * and the username of the requester user.
	 */
	
	public static void PrivateMessage ( String msgFor ) throws IOException {
		
		String [ ] s1 = msgFor.split ( " " ); 
		msgFor = s1 [ 0 ];
		byte [ ] b = privateMsg.getBytes ( );
		DatagramPacket p = new DatagramPacket ( b, b.length, Client.group, Client.ports );
		Client.cl.send ( p );
		Private pmsg = new Private ( );
		String s = "<init> <" + username + ">";
		b = s.getBytes ( );
		p = new DatagramPacket ( b, b.length, InetAddress.getByName ( Private.host ), Private.ports );
		Private.cl.send ( p );
		pmsg.Components ( username, msgFor );
		
	} // End PrivateMessage.

} // End class.
