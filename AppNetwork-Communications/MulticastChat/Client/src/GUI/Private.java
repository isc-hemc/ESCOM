package GUI;

import java.awt.event.ActionListener;
import java.io.IOException;
import java.awt.event.ActionEvent;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import javax.swing.JEditorPane;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Font;

/* This class allows two clients to interact each other sending
 * private messages, the messages won't be sended to the common chat
 * instead, they will have a personal window.
 */

public class Private extends JFrame implements ActionListener, Runnable {

	private static final long serialVersionUID = 1L;
	protected static JScrollPane scroller;
	protected static DatagramSocket cl;
	protected static String username;
	protected static JEditorPane ep;
	protected static JTextField tf;
	protected static String host;
	protected static String user;
	protected static String aux;
	protected static int portc;
	protected static int ports;
	public static Thread t;
	
	public Private ( ) {
		
		super ( "Private Chat." );
		this.getContentPane ( ).setBackground ( Color.WHITE );
		ep = new JEditorPane ( );
		tf = new JTextField ( );
		t = new Thread ( this );
		host = "127.0.0.1";
		ports = 9709;
		aux = "";
		scroller = new JScrollPane ( ep, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER );

	} // End constructor.
	
	public void Components ( String username, String user ) {
		
		setDefaultCloseOperation ( JFrame.DISPOSE_ON_CLOSE );
		setLocationRelativeTo ( null );
		setResizable ( false );
		setSize ( 300, 340 );
		setVisible ( true );
		setLayout ( null );
		Private.username = username;
		Private.user = user;
		t.start ( );
		Attributes ( );
		
	} // End Components. 
	
	public void Attributes ( ) {
		
		/* Attributes. */
		scroller.setBounds ( 20, 20, 260, 240 );
		tf.setBounds ( 20, 280, 260, 20 );
		
		ep.setContentType( "text/html" );
		tf.setForeground ( Color.RED );
		ep.setForeground ( Color.RED );
		
		tf.setFont ( new Font ( "Comic Sans MS", Font.BOLD, 12 ) );
		ep.setFont ( new Font ( "Comic Sans MS", Font.BOLD, 12 ) );
		ep.setEditable ( false );
		
		add ( scroller );
		add ( tf );
		
		/* Action Performed. */
		tf.addActionListener ( this );
		
	} // End Attributes.
	
	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == tf ) {
			String s = tf.getText ( );
			s = "<msg> <" + user + "> " + username + ": " + s;
			byte [ ] b = s.getBytes ( );
			try {
				DatagramPacket p = new DatagramPacket ( b, b.length, InetAddress.getByName ( host ), ports );
				cl.send ( p );
			} catch ( Exception e1 ) {
				e1.printStackTrace ( );
			} // End try - catch.
			tf.setText ( "" );
		} // End if.
	} // End actionPerformed.
	
	public static void Launch ( ) {
		
		try {
			cl = new DatagramSocket ( );
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End Launch.

	@Override
	public void run() {
		
		for ( ; ; ) {
			DatagramPacket p = new DatagramPacket ( new byte [ 1500 ], 1500 );
			try {
				cl.receive ( p );
			} catch (IOException e) {
				e.printStackTrace();
			} // End try - catch.
			String msg = new String ( p.getData ( ), 0, p.getLength ( ) );
			System.out.println ( "\n\tMessage received from: " + p.getAddress ( ) + " : " + p.getPort ( ) + "\n\tMessage: " + msg );
			aux = aux + msg + "<BR>";
			ep.setText ( aux );	
		} // End forever.
		
	} // End Thread.

} // End class.
