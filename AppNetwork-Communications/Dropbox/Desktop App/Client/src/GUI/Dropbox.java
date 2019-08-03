package GUI;

import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.DataFlavor;
import java.awt.dnd.DropTargetDragEvent;
import java.awt.dnd.DropTargetDropEvent;
import java.awt.dnd.DropTargetListener;
import java.awt.event.ActionListener;
import java.awt.dnd.DropTargetEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.ActionEvent;
import java.awt.dnd.DnDConstants;
import java.awt.event.MouseEvent;
import java.awt.dnd.DropTarget;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.nio.ByteBuffer;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.awt.Image;
import java.util.List;
import java.awt.Color;
import java.awt.Font;
import javax.swing.*;
import java.io.*;

import Sockets.*;

public class Dropbox extends JFrame implements ActionListener, DropTargetListener {

	private static final long serialVersionUID = 1L;
	private DefaultListModel <String> directoriesDlm;
	private JScrollPane directoriesScroller;
	private JList <String> directoriesList;
	private DefaultListModel <String> dlm;
	private JList <String> storedFiles;
	private JLabel directoryImageLabel;
	private JScrollPane filesScroller;
	private String sharedDirectories;
	private ImageIcon directoryIcon;
	private JButton downloadButton;
	private ImageIcon downloadIcon;
	private JPanel directoryPanel;
	private JButton profileButton;
	private ImageIcon profileIcon;
	private JButton uploadButton;
	private ImageIcon uploadIcon;
	private String directoryName;
	private JButton deleteButton;
	private ImageIcon deleteIcon;
	private JLabel nicknameLabel;
	private Image directoryImage;
	private Image downloadImage;
	private JButton shareButton;
	private ImageIcon shareIcon;
	private JPanel accountPanel;
	private Image profileImage;
	private String directories;
	private Image uploadImage;
	private Image deleteImage;
	private Image shareImage;
	private JPanel tabPanel1;
	private String filename;
	private JPanel tabPanel;
	private String nickname;
	private JFileChooser fc;
	private DropTarget dt;
	private Client cl;
	private int n;

	public Dropbox ( String nickname, String directories, String sharedDirectories, Client cl ) { 
		
		this.sharedDirectories = sharedDirectories;
		this.directories = directories;
		this.nickname = nickname;
		this.cl = cl;
		
	} // End constructor.
	
	public void init ( ) {
		
		initializeComponents ( );
		this.getContentPane ( ).setBackground ( Color.WHITE );
		setDefaultCloseOperation ( JFrame.EXIT_ON_CLOSE );
		setLocationRelativeTo ( null );
		setResizable ( false );
		setTitle ( "Dropbox" );
		setSize ( 800, 600 );
		setLayout ( null );
		setDirectoriesList ( );
		components ( );
		
	} // End method.
	
	private void initializeComponents ( ) {
		
		// ImageIcons.
		directoryIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/Directory.png" ) );
		downloadIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/Download.png" ) );
		uploadIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/Upload.png" ) );  
		deleteIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/Delete.png" ) );
		shareIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/Share.png" ) );
		// DefaultListModels.
		directoriesDlm = new DefaultListModel <String> ( );
		dlm = new DefaultListModel <String> ( );
		// JLists.
		directoriesList = new JList <String> ( directoriesDlm );
		storedFiles = new JList <String> ( dlm );
		// JScrollPanes.
		directoriesScroller = new JScrollPane ( directoriesList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED );
		filesScroller = new JScrollPane ( storedFiles, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED );
		// DropTarget.
		dt = new DropTarget ( filesScroller, this );
		// Panels.
		accountPanel = new JPanel ( new GridLayout ( 1, 1 ) );
		directoryPanel = new JPanel ( new GridLayout ( 2, 1 ) );
		tabPanel = new JPanel ( new GridLayout ( ) );
		tabPanel1 = new JPanel ( new BorderLayout ( ) );
		// Images.
		directoryImage = directoryIcon.getImage ( );
		downloadImage = downloadIcon.getImage ( );
		deleteImage = deleteIcon.getImage ( );
		uploadImage = uploadIcon.getImage( );
		shareImage = shareIcon.getImage ( );
		// Buttons.
		downloadButton = new JButton ( );
		deleteButton = new JButton ( );
		uploadButton = new JButton ( );
		shareButton = new JButton ( );
		profileButton = new JButton ( );
		// Labels.
		nicknameLabel = new JLabel ( this.nickname );
		directoryImageLabel = new JLabel ( );
		// File chooser.
		fc = new JFileChooser ( );
		/* Mouse event listeners. */
		storedFiles.addMouseListener ( new MouseAdapter ( ) {
			public void mouseClicked ( MouseEvent event ) {
				JList <String> list = ( JList <String> ) event.getSource ( );
				if ( event.getClickCount ( ) == 1 ) {
					int index = list.locationToIndex( event.getPoint ( ) );
					filename = ( String ) list.getModel ( ).getElementAt ( index );
				} // End if.
			} // End method.
		} );
		directoriesList.addMouseListener ( new MouseAdapter ( ) {
			public void mouseClicked ( MouseEvent event ) {
				JList <String> list = ( JList <String> ) event.getSource ( );
				if ( event.getClickCount ( ) == 1 ) {
					int index = list.locationToIndex ( event.getPoint ( ) );
					directoryName = ( String ) list.getModel ( ).getElementAt ( index );
					if ( directoryName.equalsIgnoreCase ( "Shared " + nickname ) ) {
						shareButton.setEnabled ( true );
						deleteButton.setEnabled ( true );
					} else {
						shareButton.setEnabled ( false );
						if ( directoryName.equalsIgnoreCase ( nickname ) ) {
							deleteButton.setEnabled ( true );
						} else {
							deleteButton.setEnabled ( false );
						} // End if - else.
					} // End file.
					try {
						ByteBuffer b = ByteBuffer.wrap ( ( "<filelist>:" + nickname + ":" + directoryName ).getBytes ( ) );
						Main.SocketClient.cl.write ( b );
						filesUpdate ( );
					} catch ( IOException e ) {
						e.printStackTrace ( );
					} // End try - catch.
				} // End if.
			} // End method.
		} );

	} // End method.
	
	private void components ( ) {
		
		// Panels.
		directoryPanel.setBackground ( Color.decode ( "0x696969" ) );
		directoryPanel.setBounds ( 0, 130, 200, 450 );
		directoryPanel.add ( directoriesScroller );
		accountPanel.setBackground ( Color.decode ( "0x696969" ) );
		accountPanel.setBounds ( 0, 55, 200, 85 );
		tabPanel.setBackground ( Color.decode ( "0xDCDCDC" ) );
		tabPanel.setBounds ( 600, 55, 200, 55 );
		tabPanel.add ( shareButton );
		tabPanel.add ( downloadButton );
		tabPanel.add ( deleteButton );
		tabPanel1.setBackground ( Color.decode ( "0xDCDCDC" ) );
		tabPanel1.setBounds ( 200, 55, 400, 55 );
		tabPanel1.add( uploadButton, BorderLayout.WEST );
		// JLists.
		directoriesList.setBounds ( 10, 120, 190, 460 );
		directoriesList.setBackground ( Color.decode ( "0x696969" ) );
		storedFiles.setBounds ( 210, 110, 590, 460 );
		storedFiles.setBackground ( Color.WHITE );
		// JScrollPanes.
		directoriesScroller.setBounds ( 10, 110, 190, 460 );
		directoriesScroller.setBorder ( null );
		filesScroller.setBounds ( 200, 110, 600, 470 );
		// ImageIcons.
		directoryIcon = new ImageIcon ( directoryImage.getScaledInstance ( 150, 150, Image.SCALE_SMOOTH ) );
		downloadIcon = new ImageIcon ( downloadImage.getScaledInstance ( 40, 40, Image.SCALE_SMOOTH ) );
		deleteIcon = new ImageIcon ( deleteImage.getScaledInstance ( 40, 40, Image.SCALE_SMOOTH ) );
		uploadIcon = new ImageIcon ( uploadImage.getScaledInstance ( 40, 40, Image.SCALE_SMOOTH ) );
		shareIcon = new ImageIcon ( shareImage.getScaledInstance ( 40, 40, Image.SCALE_SMOOTH ) );
		// Labels.
		directoryImageLabel.setBounds ( 25, 400, 150, 150 );
		directoryImageLabel.setIcon ( directoryIcon );
		nicknameLabel.setFont ( new Font ( "Time New Roman", Font.BOLD, 18 ) );
		nicknameLabel.setBounds ( 600, 15, 200, 30 );
		// Buttons.
		shareButton.setRolloverEnabled ( true );
		shareButton.setBorderPainted ( false );
		shareButton.setContentAreaFilled ( false );
		shareButton.setIcon ( shareIcon );
		deleteButton.setRolloverEnabled ( true );
		deleteButton.setBorderPainted ( false );
		deleteButton.setContentAreaFilled ( false );
		deleteButton.setIcon ( deleteIcon );
		downloadButton.setRolloverEnabled ( true );
		downloadButton.setBorderPainted ( false );
		downloadButton.setContentAreaFilled ( false );
		downloadButton.setIcon ( downloadIcon );
		uploadButton.setRolloverEnabled ( true );
		uploadButton.setBorderPainted ( false );
		uploadButton.setContentAreaFilled ( false );
		uploadButton.setIcon ( uploadIcon );
		// Profile picture.
		File f = new File ( "bin/GUI/Icons/Dropbox/ProfilePictures/" + this.nickname + ".jpg" );
		if ( f.exists ( ) ) {
			profileIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/ProfilePictures/" + nickname + ".jpg" ) );
			profileImage = profileIcon.getImage ( );
			profileIcon = new ImageIcon ( profileImage.getScaledInstance ( 90, 90, Image.SCALE_SMOOTH ) );
			profileButton.setBounds ( 55, 10, 90, 90 );
			profileButton.setRolloverEnabled ( true );
			profileButton.setBorderPainted ( false );
			profileButton.setContentAreaFilled ( false );
			profileButton.setIcon ( profileIcon );
		} else {
			profileIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/ProfilePictures/Profile.png" ) );
			profileImage = profileIcon.getImage ( );
			profileIcon = new ImageIcon ( profileImage.getScaledInstance ( 90, 90, Image.SCALE_SMOOTH ) );
			profileButton.setBounds ( 55, 10, 90, 90 );
			profileButton.setRolloverEnabled ( true );
			profileButton.setBorderPainted ( false );
			profileButton.setContentAreaFilled ( false );
			profileButton.setIcon ( profileIcon );
		} // End if - else.
		// Add to frame.
		add ( directoryImageLabel );
		add ( directoryPanel );
		add ( profileButton );
		add ( nicknameLabel );
		add ( filesScroller );
		add ( accountPanel );
		add ( tabPanel1 );
		add ( tabPanel );
		// Launch JFrame.
		setVisible ( true );
		
		shareButton.addActionListener ( this );
		downloadButton.addActionListener ( this );
		deleteButton.addActionListener ( this );
		uploadButton.addActionListener ( this );
		profileButton.addActionListener ( this );
		
	} // End method.
	
	private void setDirectoriesList ( ) {
		
		String [ ] split = this.sharedDirectories.split ( ":" );
		directoriesDlm.addElement ( this.directories );
		for ( String str : split ) {
			directoriesDlm.addElement ( str );
		} // End for.
		
	} // End method.
	
	@Override
	public void dragEnter ( DropTargetDragEvent dtde ) { }

	@Override
	public void dragOver ( DropTargetDragEvent dtde ) { }

	@Override
	public void dropActionChanged ( DropTargetDragEvent dtde ) { }

	@Override
	public void dragExit ( DropTargetEvent dte ) {	}

	@Override
	public void drop ( DropTargetDropEvent dtde ) {
		dtde.acceptDrop ( DnDConstants.ACTION_COPY );
		Transferable t = dtde.getTransferable ( );
		DataFlavor [ ] df = dtde.getCurrentDataFlavors ( );
		for ( DataFlavor f : df ) {
			try {
				if ( f.isFlavorJavaFileListType ( ) ) {
					List <File> l = ( List <File> ) t.getTransferData ( f );
					for ( File f1 : l ) {
						add ( f1.getPath ( ), f1 );
					} // End for.
				} // End if.
			} catch ( Exception e ) {
				e.printStackTrace ( );
			} // End try - catch.
		} // End for.
	} // End drop.
	
	private void add ( String path, File f ) {
		
		storedFiles.setModel ( dlm );
		StoreType t = new StoreType ( new File ( path ).getName ( ), new File ( path ).toString ( ), nickname, this.cl );
		t.init ( );

	} // End method.

	@Override
	public void actionPerformed ( ActionEvent e ) {
		
		if ( e.getSource ( ) == shareButton ) {
			Share sh = new Share ( nickname );
			sh.init ( );
		} // End if.
		
		if ( e.getSource ( ) == downloadButton ) {
			if ( filename == null ); else {
				ByteBuffer b = ByteBuffer.wrap ( ( "<download>:" + nickname + ":" + filename ).getBytes ( ) );
				try {
					Main.SocketClient.cl.write ( b );
				} catch ( IOException ioe ) {
					ioe.printStackTrace();
				} // End try - catch.
				recvFile.download ( cl );
			} // End nested if - else.
		} // End if.
		
		if ( e.getSource ( ) == profileButton ) {
			int r = fc.showOpenDialog ( null );
			if ( r == JFileChooser.APPROVE_OPTION ) {
				File f = fc.getSelectedFile ( );
				try {
					InputStream is = new FileInputStream ( f.getAbsolutePath ( ) );
					OutputStream os = new FileOutputStream ( "bin/GUI/Icons/Dropbox/ProfilePictures/" + nickname + ".jpg" );
					byte [ ] b = new byte [ 1024 ];
					int len;
					while ( ( len = is.read ( b ) ) > 0 ) {
						os.write ( b, 0, len );
					} // End while.
					is.close ( );
				} catch ( IOException ioe ) {
					ioe.printStackTrace ( );
				} // End try - catch.
			} // End if.
			profileIcon = new ImageIcon ( getClass ( ).getResource ( "/GUI/Icons/Dropbox/ProfilePictures/" + nickname + ".jpg" ) );
			profileImage = profileIcon.getImage ( );
			profileIcon = new ImageIcon ( profileImage.getScaledInstance ( 90, 90, Image.SCALE_SMOOTH ) );
			profileButton.setBounds ( 55, 10, 90, 90 );
			profileButton.setRolloverEnabled ( true );
			profileButton.setBorderPainted ( false );
			profileButton.setContentAreaFilled ( false );
			profileButton.setIcon ( profileIcon );
		} // End if.
		
		if ( e.getSource ( ) == uploadButton ) {
			fc.setMultiSelectionEnabled (true );
			int r = fc.showOpenDialog ( null );
			if ( r == JFileChooser.APPROVE_OPTION ) {
				File [ ] f = fc.getSelectedFiles ( );
				for ( int i = 0 ; i < f.length ; i++ ) {
					System.out.println ( f [ i ].getName ( ) );
					StoreType t = new StoreType ( f [ i ].getName ( ), f [ i ].toString ( ), nickname, this.cl );
					t.init ( );			
				} // End for.
			} // End nested if.
		} // End if.
		
		if ( e.getSource ( ) == deleteButton ) {
			if ( filename == null ); else {
				ByteBuffer b = ByteBuffer.wrap ( ( "<delete>:" + nickname + ":" + filename + ":" + directoryName ).getBytes ( ) );
				try {
					Main.SocketClient.cl.write ( b );
				} catch ( IOException ioe ) {
					ioe.printStackTrace();
				} // End try - catch.
			} // End nested if - else.
		} // End if.
		
	} // End actionPerformed.
	
	/* Receive from the server a string with all the files stores in the selected directory and display all the
	 * data in the storedFiles JList. 
	 */
	
	private void filesUpdate ( ) {
		
		try {
			ByteBuffer b = ByteBuffer.allocate ( 1000 );
			b.clear ( );
			n = Main.SocketClient.cl.read ( b );
			b.flip ( );
			String recv = new String ( b.array ( ), 0, n );
			String [ ] split = recv.split ( ":" );
			dlm.clear ( );
			for ( String str : split ) {
				dlm.addElement ( str ); 
			} // End for.
		} catch ( IOException e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End method.

} // End class.
