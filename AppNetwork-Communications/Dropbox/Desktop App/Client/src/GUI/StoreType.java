package GUI;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Image;
import java.awt.Color;
import java.awt.Font;
import Sockets.*;

public class StoreType extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;
	private JLabel privateFileLabel;
	private JLabel sharedFileLabel;
	private ImageIcon privateIcon;
	private ImageIcon sharedIcon;
	private JButton privateFile;
	private JButton sharedFile;
	private Image privateImage;
	private Image sharedImage;
	private String nickname;
	private String fileName;
	private JLabel message1;
	private JLabel message;
	private String path;
	private Client cl;
	
	public StoreType ( String fileName, String path, String nickname, Client cl ) { 
		
		this.nickname = nickname;
		this.fileName = fileName;
		this.path = path;
		this.cl = cl;
		
	} // End constructor.
	
	public void init ( ) {
		
		initializeComponents ( );
		this.getContentPane ( ).setBackground ( Color.WHITE );
		setDefaultCloseOperation ( JFrame.DISPOSE_ON_CLOSE );
		setTitle ( "Upload File: " + fileName );
		setLocationRelativeTo ( null );
		setAlwaysOnTop ( true );
		setResizable ( true );
		setSize ( 480, 230 );
		setLayout ( null );
		components ( );
		
	} // End method.
	
	private void initializeComponents ( ) {
		
		message1 = new JLabel ( "<html><body>Upload your documents from your system and store<br>them in your personal repository. No one will be able<br>to see your files.</body></html>" );
		message = new JLabel ( "<html><body>Upload your documents from your system and share<br>them to allow everyone see the most recent changes.</body></html>" );
		privateIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/FileType/Private.png" ) );
		sharedIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/FileType/Shared.png" ) );
		privateFileLabel = new JLabel ( "Store in your personal Dropbox folder." );
		sharedFileLabel = new JLabel ( "Share this file with friends." );
		privateImage = privateIcon.getImage ( );
		sharedImage = sharedIcon.getImage ( );
		privateFile = new JButton ( "Private" );
		sharedFile = new JButton ( "Share" );
		
	} // End method.
	
	private void components ( ) {
		
		// ImageIcons.
		privateIcon = new ImageIcon ( privateImage.getScaledInstance ( 90, 80, Image.SCALE_SMOOTH ) );
		sharedIcon = new ImageIcon ( sharedImage.getScaledInstance ( 100, 80, Image.SCALE_SMOOTH ) );
		// Labels.
		privateFileLabel.setFont ( new Font ( "Time New Roman", Font.CENTER_BASELINE, 16 ) );
		privateFileLabel.setBounds ( 120, 110, 400, 20 );
		sharedFileLabel.setFont ( new Font ( "Time New Roman", Font.CENTER_BASELINE, 16 ) );
		sharedFileLabel.setBounds ( 120, 20, 400, 20 );
		message.setFont ( new Font ( "Times New Roman", Font.ITALIC, 14 ) );
		message.setForeground ( Color.decode ( "0x778899" ) );
		message.setBounds ( 120, 40, 400, 50 );
		message1.setFont ( new Font ( "Times New Roman", Font.ITALIC, 14 ) );
		message1.setForeground ( Color.decode ( "0x778899" ) );
		message1.setBounds ( 120, 135, 400, 50 );
		// Buttons.
		privateFile.setContentAreaFilled ( false );
		privateFile.setBounds ( 20, 110, 80, 80 );
		privateFile.setRolloverEnabled ( true );
		privateFile.setBorderPainted ( false );
		privateFile.setIcon ( privateIcon );
		sharedFile.setContentAreaFilled ( false );
		sharedFile.setBounds ( 20, 15, 90, 80 );
		sharedFile.setRolloverEnabled ( true );
		sharedFile.setBorderPainted ( false );
		sharedFile.setIcon ( sharedIcon );
		// Add to frame.
		add ( privateFileLabel );
		add ( sharedFileLabel );
		add ( privateFile );
		add ( sharedFile );
		add ( message1 );
		add ( message );
		setVisible ( true );
		
		privateFile.addActionListener ( this );
		sharedFile.addActionListener ( this );
		
	} // End method.
	
	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == privateFile ) {
			String dir = "../../Dropbox/" + this.nickname;
			Sockets.sendFile.store ( this.fileName, this.path, dir, this.nickname, cl );
			dispose ( );
		} // End if.
		if ( e.getSource ( ) == sharedFile ) {
			String dir = "../../Dropbox/Shared " + this.nickname;
			Sockets.sendFile.store ( this.fileName, this.path, dir, this.nickname, cl );
			dispose ( );
		} // End if.
		
	} // End actionPerformed.

} // End class.
