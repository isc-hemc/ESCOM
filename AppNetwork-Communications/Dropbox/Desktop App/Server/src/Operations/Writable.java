package Operations;

import java.sql.SQLException;
import java.nio.ByteBuffer;
import java.nio.channels.*;
import java.sql.ResultSet;
import Main.*;

public class Writable {
	
	public static boolean sendFilesFlag;
	private static String directorys;
	private static SocketChannel ch;
	public static boolean logInFlag;
	private static String sendStr;
	private static ByteBuffer b;
	public static User u;

	public static void write ( ) {
		
		if ( logInFlag ) {
			directoryUpdate ( );
			logInFlag = false;
		} // End if.
		
		if ( sendFilesFlag ) {
			fileUpdate ( );
			sendFilesFlag = false;
		} // End if.
		
	} // End method.
	
	private static void directoryUpdate ( ) {
		
		directorys = "";
		ch = ( SocketChannel ) Main.k.channel ( );
		ResultSet rs;
		try {
			rs = ( ResultSet ) Main.da.getQuery ( "SELECT d.name FROM Directory d, User u WHERE u.idUser = d.idUser AND u.nickname LIKE '" + u.getNickname ( ) + "%' ;" );
			while ( rs.next ( ) ) {
				directorys += rs.getString ( "d.name" );
			} // End while.
			directorys += "&";
			rs = ( ResultSet ) Main.da.getQuery ( "SELECT sd.name FROM SharedDirectory sd, User u, UserSD x WHERE u.idUser = x.idUser AND x.idSD = sd.idSD AND u.nickname LIKE '" + u.getNickname ( ) + "%' ;" );
			while ( rs.next ( ) ) {
				directorys += rs.getString ( "sd.name" ) + ":" ;
			} // End while.
		} catch (SQLException sqle ) {
			sqle.printStackTrace ( );
		} // End try - catch.
		sendStr = "<continue>&" + u.getNickname ( ) + "&" + directorys + "&" + u.getServer ( ).getPort ( ).toString ( );
		b = ByteBuffer.wrap ( sendStr.getBytes ( ) );
		try {
			ch.write ( b );
			u.getServer ( ).accept ( );
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End method.
	
	private static void fileUpdate ( ) {
		
		ch = ( SocketChannel ) Main.k.channel ( );
		if ( u.getNickname ( ).equalsIgnoreCase ( Readable.directory ) ) { 
			ResultSet rs = ( ResultSet ) Main.da.getQuery ( "SELECT f.name FROM Files f, Directory d, User u WHERE u.idUser = d.idUser AND d.idDirectory = f.idDirectory AND d.name LIKE '" + Readable.directory + "%' AND u.nickname LIKE '" + u.getNickname ( ) + "%';" );
			String files = "";
			try {
				while ( rs.next ( ) ) {
					files += rs.getString ( "f.name" ) + ":";
				} // End while.
				b = ByteBuffer.wrap ( files.getBytes ( ) );
				ch.write ( b );
			} catch ( SQLException sqle ) {
				sqle.printStackTrace ( );
			} catch ( Exception e ) {
				e.printStackTrace ( );
			} // End try - catch.
		} // End if.
		ResultSet rs = ( ResultSet ) Main.da.getQuery ( "SELECT sf.name FROM SharedFiles sf, SharedDirectory sd, User u, UserSD x WHERE u.idUser = x.idUser AND sd.idSD = x.idSD AND sd.idSD = sf.idSD AND sd.name LIKE '" + Readable.directory + "' AND u.nickname LIKE '" + u.getNickname ( ) + "';" );
		String files = "";
		try {
			while ( rs.next ( ) ) {
				files += rs.getString ( "sf.name" ) + ":";
			} // End while.
			b = ByteBuffer.wrap ( files.getBytes ( ) );
			ch.write ( b );
		} catch ( SQLException sqle ) {
			sqle.printStackTrace ( );
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End method.
	
} // End class.
