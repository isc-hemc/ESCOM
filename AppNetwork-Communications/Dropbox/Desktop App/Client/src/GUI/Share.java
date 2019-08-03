package GUI;

import java.awt.event.ActionListener;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.JFrame;
import java.awt.Color;

public class Share extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;
	private JTextField friend;
	private String nickname;

	public Share ( String nickname ) { 
		
		this.nickname = nickname;
		
	} // End constructor.
	
	public void init ( ) {
		
		initializeComponents ( );
		this.getContentPane ( ).setBackground ( Color.WHITE );
		setDefaultCloseOperation ( JFrame.DISPOSE_ON_CLOSE );
		setLocationRelativeTo ( null );
		setTitle ( "Share your directory..." );
		setAlwaysOnTop ( true );
		setResizable ( false );
		setSize ( 200, 70 );
		setLayout ( null );
		components ( );
		
	} // End method.
	
	private void initializeComponents (  ) {
		
		friend = new JTextField ( );
		
	} // End method.
	
	private void components ( ) {
		
		friend.setBounds ( 10, 10, 180, 20 );
		add ( friend );
		setVisible ( true );
		
		friend.addActionListener ( this );
		
	} // End method.

	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == friend ) {
			String str = "<sharedocuments>:" + nickname + ":" + friend.getText ( ) + ":" + "Shared " + nickname;
			ByteBuffer b = ByteBuffer.wrap ( str.getBytes ( ) );
			try {
				Main.SocketClient.cl.write ( b );
			} catch ( IOException ioe ) {
				ioe.printStackTrace ( );
			} // End try - catch.
			dispose ( );
		} // End if.
		
	} // End actionPerformed. 
	
} // End class.
