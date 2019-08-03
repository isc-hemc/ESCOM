package Operations;

import java.sql.SQLException;
import java.sql.ResultSet;
import java.util.Random;
import java.io.File;
import Sockets.*;
import Main.*;

public class Queries {
	
	private static File f;

	public static boolean logIn ( String logEmail, String logPassword ) throws Exception {
		
		ResultSet rs = ( ResultSet ) Main.da.getQuery ( "SELECT * FROM User" );
		boolean connectionFlag = false;
		while ( rs.next ( ) ) {
			String nickname = rs.getString ( "nickname" );
			String email = rs.getString ( "email" );
			String password = rs.getString ( "pass" );
			if ( email.equalsIgnoreCase ( logEmail ) && password.equals ( logPassword ) ) {
				System.out.println ( "\n\t\tUser login: Welcome back " + Main.hm.get ( nickname ).getNickname ( ) + "." );
				while ( !( connectionFlag ) ) {
					Server s = new Server ( ( int ) ( new Random ( System.currentTimeMillis ( ) ).nextDouble ( ) * 65535 + 1024 ) );
					if ( s.initSocket ( ) ) {
						Main.hm.get ( nickname ).setSocket ( s );
						connectionFlag = true;
					} // End if.
				} // End while.
				Writable.u = Main.hm.get ( nickname );
				return true;
			} // End if.
		} // End while.
		
		return false;
		
	} // End method.
	
	public static void signIn ( User u ) {
		
		String nickname = u.getNickname ( );
		if ( Main.da.setQuery ( "INSERT INTO User ( name, lastname, nickname, email, pass ) VALUES ( '" + u.getName ( ) + "', '" + u.getLastName ( ) + "', '" + u.getNickname ( ) + "', '" + u.getEmail ( ) + "', '" + u.getPassword ( ) + "' );" ) ) {
			Main.hm.put ( u.getNickname ( ), u );
			try {
				newUser.sharedDirectory ( nickname );
				newUser.directory ( nickname );
				newUser.userSD ( nickname );
			} catch (SQLException e) {
				e.printStackTrace ( );
			} // End try - catch.
		} // End if.
		
	} // End method.
	
	public static void clientObjects ( ) {
		
		ResultSet rs = ( ResultSet ) Main.da.getQuery ( "SELECT * FROM User" );
		try {
			while ( rs.next ( ) ) {
				String name = rs.getString ( "name" );
				String lastname = rs.getString ( "lastname" );
				String nickname = rs.getString ( "nickname" );
				String email = rs.getString ( "email" );
				String password = rs.getString ( "pass" );
				User u = new User ( name, lastname, nickname, email, password );
				Main.hm.put ( nickname, u );
			} // End while.
		} catch ( SQLException sqle ) {
			sqle.printStackTrace ( );
		} // End try - catch.
		 
	} // End method.
	
	public static void shareDocuments ( String nickname, String friendNickname, String directory ) {
		
		Main.da.setQuery ( "INSERT INTO UserSD VALUES ( ( SELECT idUser FROM User WHERE nickname LIKE '" + friendNickname + "' ), ( SELECT idSD FROM SharedDirectory WHERE name LIKE '" + directory + "' ) )" );
		
	} // End method.
	
	public static void deleteDocuments ( String nickname, String filename, String directoryName ) {
		
		f = new File ( "../../Dropbox/" + directoryName + "/" + filename );
		f.delete ( );
		if ( directoryName.substring ( 0, 6 ).equalsIgnoreCase ( "Shared" ) ) {
			Main.da.setQuery ( "DELETE FROM SharedFiles WHERE name LIKE '" + filename + "';" ); 
		} else {
			Main.da.setQuery ( "DELETE FROM Files WHERE name LIKE '" + filename + "%';" );
		} // End if.
	} // End method
	
	/*
	 DELETE FROM f.
	 */
} // End class.
