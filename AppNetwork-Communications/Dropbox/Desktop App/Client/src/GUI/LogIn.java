package GUI;

import java.awt.event.ActionListener;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.util.regex.*;
import java.awt.Image;
import java.awt.Color;
import java.awt.Font;
import javax.swing.*;
import Sockets.*;
import Main.*;

public class LogIn extends JFrame implements ActionListener {
	
	private static final String PATTERN_EMAIL = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@" + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
	private static final long serialVersionUID = 1L;
	private JPasswordField signPassword;
	private JPasswordField logPassword;
	private JLabel logPasswordLabel;
	private ImageIcon dropboxIcon;
	private JLabel logEmailLabel;
	private JTextField signEmail;
	private JLabel invalidEmail;
	private JLabel dropboxLabel;
	private JTextField nickname;
	private JTextField logEmail;
	private JTextField lastName;
	private JLabel errorSignIn;
	private JButton signButton;
	private Image dropboxImage;
	private ImageIcon signIcon;
	private JLabel errorLogIn;
	private JButton logButton;
	private ImageIcon logIcon;
	private JLabel signLabel;
	private JLabel logoLabel;
	private Image signImage;
	private JPanel logPanel;
	private JTextField name;
	private Image logImage;
	private int n;
	
	public LogIn ( ) { } // End constructor.
	
	public void init ( ) {
		
		initializeComponents ( );
		this.getContentPane ( ).setBackground (  Color.decode ( "#483D4B" ) );
		setDefaultCloseOperation ( JFrame.DISPOSE_ON_CLOSE );
		setLocationRelativeTo ( null );
		setTitle ( "Dropbox: Login" );
		setResizable ( false );
		setSize ( 600, 650 );
		setLayout ( null );
		components ( );
		
	} // End constructor.
	
	private void initializeComponents ( ) {
		
		// Panel.
		logPanel = new JPanel ( new BorderLayout ( ) );
		// ImageIcons.
		dropboxIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/LogIn/Logotype.png" ) );
		signIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/LogIn/Signin.png" ) );
		logIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/LogIn/Login.png" ) );
		// Labels.
		errorLogIn = new JLabel ( "Incorrect email or password." );
		errorSignIn = new JLabel ( "Oops, something goes wrong." );
		invalidEmail = new JLabel ( "Invalid email." );
		logPasswordLabel = new JLabel ( "Password" );
		signLabel = new JLabel ( "Sign In..." );
		logEmailLabel = new JLabel ( "Email" );
		dropboxLabel = new JLabel ( );
		logoLabel = new JLabel ( );
		// TextFields.
		nickname = new JTextField ( "Choose a Nickname" );
		signEmail = new JTextField ( "Your Email" );
		lastName = new JTextField ( "Last Name" );
		name = new JTextField ( "First Name" );
		logEmail = new JTextField ( );
		// Images.
		dropboxImage = dropboxIcon.getImage ( );
		signImage = signIcon.getImage ( );
		logImage = logIcon.getImage ( );
		// PasswordFields.
		signPassword = new JPasswordField ( "Password" );
		logPassword = new JPasswordField ( );
		// Buttons.
		signButton = new JButton ( );
		logButton = new JButton ( );
		
	} // End method.
	
	private void components ( ) {
		
		// Panel.
		logPanel.setBackground ( Color.decode ( "0x696969" ) );
		logPanel.setBounds ( 0, 0, 1300, 65 );
		add ( logPasswordLabel );
		add ( logEmailLabel );
		add ( logPassword );
		add ( logPassword );
		add ( errorLogIn );
		add ( logButton );
		add ( logEmail );
		// ImageIcons.
		dropboxIcon = new ImageIcon ( dropboxImage.getScaledInstance ( 150, 150, Image.SCALE_SMOOTH ) );
		signIcon = new ImageIcon ( signImage.getScaledInstance ( 190, 65, Image.SCALE_SMOOTH ) );
		logIcon = new ImageIcon ( logImage.getScaledInstance ( 100, 30, Image.SCALE_SMOOTH ) );
		// Buttons.
		signButton.setContentAreaFilled ( false );
		signButton.setBounds ( 45, 510, 190, 65 );
		signButton.setRolloverEnabled ( true );
		signButton.setBorderPainted ( false );
		signButton.setIcon ( signIcon );
		logButton.setContentAreaFilled ( false );
		logButton.setBounds ( 480, 15, 110, 30 );
		logButton.setRolloverEnabled ( true );
		logButton.setBorderPainted ( false );
		logButton.setIcon ( logIcon );
		// Labels.
		signLabel.setFont ( new Font ( "Time New Roman", Font.BOLD, 50 ) );
		signLabel.setForeground ( Color.decode ( "0xD3D3D3" ) );
		signLabel.setBounds ( 60, 80, 300, 100 );
		logPasswordLabel.setForeground ( Color.decode ( "0xD3D3D3" ) );
		logPasswordLabel.setBounds ( 260, 5, 200, 10 );
		logEmailLabel.setForeground ( Color.decode ( "0xD3D3D3" ) );
		logEmailLabel.setBounds ( 40, 5, 200, 10 );
		errorSignIn.setForeground ( Color.decode ( "0x8B0000") );
		errorSignIn.setBounds ( 60, 485, 300, 20 );
		errorSignIn.setVisible ( false );
		errorLogIn.setForeground ( Color.decode ( "0x8B0000") );
		errorLogIn.setBounds ( 40, 40, 300, 20 );
		errorLogIn.setVisible ( false );
		invalidEmail.setForeground ( Color.decode ( "0x8B0000") );
		invalidEmail.setBounds ( 60, 485, 300, 20 );
		invalidEmail.setVisible ( false );
		dropboxLabel.setBounds ( 350, 110, 150, 150 );
		dropboxLabel.setIcon ( dropboxIcon );
		logoLabel.setBounds ( 350, 110, 150, 150 );
		logoLabel.setIcon ( dropboxIcon );
		// TextFileds.
		signPassword.setBounds ( 60, 440, 200, 40 );
		logPassword.setBorder ( BorderFactory.createLineBorder ( Color.BLACK ) );
		logPassword.setBounds ( 260, 20, 200, 20 );
		signEmail.setBounds ( 60, 380, 200, 40 );
		nickname.setBounds ( 60, 320, 200, 40 );
		lastName.setBounds ( 60, 260, 200, 40 );
		logEmail.setBorder ( BorderFactory.createLineBorder ( Color.BLACK ) );
		logEmail.setBounds ( 40, 20, 200, 20 );
		name.setBounds ( 60, 200, 200, 40 );
		// Add to frame.
		add ( signPassword );
		add ( invalidEmail );
		add ( dropboxLabel );
		add ( errorSignIn );
		add ( signButton );
		add ( signEmail );
		add ( signLabel );
		add ( logoLabel );
		add ( nickname );
		add ( lastName );
		add ( logPanel );
		add ( name );
		// Launch JFrame.
		setVisible ( true );
		// ActionListeners.
		signButton.addActionListener ( this );
		logButton.addActionListener ( this );
		
	} // End components.
	
	/* The method use a regular expression to validate the email address, in case that the email
	 * fulfill with the RE requirements, the method will return true, otherwise will return false.
	 */
	
	private  boolean emailValidation ( String email ) {
		
		Pattern p = Pattern.compile ( PATTERN_EMAIL );
		Matcher m = p.matcher ( email );
		return m.matches ( );
		
	} // End method.
	
	/* signValidation check the user information in the sign in section, in case that the user
	 * wants to sign up using the predetermined strings in a single JTextField the method will 
	 * return false and wont sent anything to the server, otherwise will return true;
	 */
	
	private boolean signValidation ( String name, String lastname, String nickname ) {
				
		if ( nickname.equalsIgnoreCase ( "Choose a Nickname" ) ) { return false; }
		if ( lastname.equalsIgnoreCase ( "Last Name" ) ) { return false; }
		if ( name.equalsIgnoreCase ( "First Name" ) ) { return false; } 
 		
		return true;
		
	} // End method.
	
	private void setPredeterminated ( ) {
		
		nickname.setText ( "Choose a Nickname" );
		signPassword.setText ( "Password" );
		signEmail.setText ( "Your Email" );
		lastName.setText ( "Last Name" );
		name.setText ( "First Name" );
		
	} // End method.
	
	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == signButton ) {
			if ( emailValidation ( signEmail.getText ( ) ) ) {
				invalidEmail.setVisible ( false );
				errorSignIn.setVisible ( false );
				if ( signValidation ( name.getText ( ), lastName.getText ( ), nickname.getText ( ) ) ) {
					String signMsg = "<signin>:" + name.getText ( ) + ":" + lastName.getText ( ) + ":" + nickname.getText ( ) + ":" + signEmail.getText ( ) + ":" + String.valueOf ( signPassword.getPassword ( ) );
					ByteBuffer b = ByteBuffer.wrap ( signMsg.getBytes ( ) );
					try {
						SocketClient.cl.write ( b );
					} catch ( Exception e1 ) {
						e1.printStackTrace ( );
					} // End try - catch.
					setPredeterminated ( );
				} else {
					errorSignIn.setVisible ( true );
					setPredeterminated ( );
				} // End nested if - else.
			} else {
				invalidEmail.setVisible ( true );
				setPredeterminated ( );
			} // End if - else.	
		} // End if.
		
		/* When the frame detects a action in the login button, before send information to the server the
		 * drop box class will do some validations. If the user its already registered the server will send
		 * a string with the flag <continue> ( split [ 0 ] ), the nickname of the user ( split [ 1 ] ), 
		 * the personal directory ( split [ 2 ] ) and the shared directories ( split [ 3 ] ) which this user 
		 * its associated, also will include the port number ( split [ 4 ] ) where a TCP socket for sending 
		 * files its running.
		 */
		
		if ( e.getSource ( ) == logButton ) {
			ByteBuffer b = ByteBuffer.wrap ( ( "<login>:" + logEmail.getText ( ) + ":" + String.valueOf ( logPassword.getPassword ( ) ) ).getBytes ( ) );
			try {
				SocketClient.cl.write ( b );
				Thread.sleep ( 1000 );
				b = ByteBuffer.allocate ( 1000 );
				b.clear ( );
				n = SocketClient.cl.read ( b );
				b.flip ( );
				String recv = new String ( b.array ( ), 0, n );
				String [ ] split = recv.split ( "&" );
				if ( split [ 0 ].equalsIgnoreCase ( "<continue>" ) ) {
					Client cl = new Client ( "127.0.0.1", Integer.parseInt ( split [ 4 ] ) );
					cl.connect ( );
					Dropbox d = new Dropbox ( split [ 1 ], split [ 2 ], split [ 3 ], cl );
					d.init ( );
					dispose ( );
				} else {
					errorLogIn.setVisible ( true );
				} // End if - else.
			} catch (IOException ioe ) {
				ioe.printStackTrace ( );
			} catch ( InterruptedException ie ) {
				ie.printStackTrace ( );
			} // End try - catch.
			
			
		} // End if.
		
	} // End actionPerformed.

} // End class.
