package GUI;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.net.DatagramPacket;
import javax.swing.JTextField;
import java.io.IOException;
import ClientSocket.Client;
import javax.swing.JButton;
import javax.swing.JDialog;

public class Init extends JDialog implements ActionListener {

	private static final long serialVersionUID = 1L;
	public static JTextField userName;
	public static JButton confirm;
	public static JButton cancel;
	
	public void Launch ( ) {
		
		 setDefaultCloseOperation ( JDialog.DISPOSE_ON_CLOSE );
		 setLocationRelativeTo ( null );
		 setTitle ( "Login" );
		 setSize ( 400, 120 );
		 setVisible ( true );
		 setLayout ( null );
		 Components ( );
		 
	} // End Launch.
	
	public void Components ( ) {
		
		/* Buttons. */
		confirm = new JButton ( "Confirm" );
		cancel = new JButton ( "Cancel" );
		
		/* TextField*/
		userName = new JTextField ( "Enter your user name..." );
		
		/* Attributes. */
		userName.setBounds ( 20, 20, 360, 20 );
		confirm.setBounds ( 20, 60, 95, 20 );
		cancel.setBounds ( 135, 60, 95, 20 );
		add ( userName );
		add ( confirm );
		add ( cancel );	
		
		confirm.addActionListener ( this );
		cancel.addActionListener ( this );
		
	} // End Components.
	
	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == confirm ) {
			String s = userName.getText ( );
			ChatRoom cr = new ChatRoom ( s );
			newUser ( s );
			cr.Components ( );
			dispose ( );
		} else if ( e.getSource ( ) == cancel ) {
			dispose ( );
		} // End if - else.
		
	} // End actionPerformer.
	
	public void newUser ( String s ) {
		
		s = "<init> " + s;
		byte [ ] b = s.getBytes ( );
		DatagramPacket p = new DatagramPacket ( b, b.length, Client.group, Client.ports );
		try { 
			Client.cl.send ( p ); 
		} catch ( IOException e ) { 
			e.printStackTrace ( ); 
		} // End try - catch.
		
	} // End newUser.
	
} // End class.
