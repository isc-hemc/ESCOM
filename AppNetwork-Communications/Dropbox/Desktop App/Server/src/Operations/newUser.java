package Operations;

import java.sql.SQLException;
import java.nio.file.Path;
import java.io.*;
import Main.*;

/* Creates a user folder for personal and shared files. Here the program will store all
 * the documents from a user. In case of a download request, the program will search 
 * for the document in this directory, and will send back the data.
 */

public class newUser {

	private static String query;
	private static File f;
	private static Path p;
	
	public static void directory ( String nickname ) throws SQLException {
		
		f = new File ( "../../Dropbox/" + nickname );
		f.mkdir ( );
		p = f.toPath ( );
		query = "INSERT INTO Directory ( name, path, idUser ) VALUES ( '" + nickname + "', '" + p + "', " + "( SELECT iduser FROM User WHERE nickname LIKE '" + nickname + "%' ) );";
		Main.da.setQuery ( query );
		
	} // End method.
	
	public static void sharedDirectory ( String nickname ) throws SQLException {
		
		f = new File ( "../../Dropbox/Shared " + nickname );
		f.mkdir ( );
		p = f.toPath ( );
		query = "INSERT INTO SharedDirectory ( name, path ) VALUES ( '" + f.getName ( ) + "', '" + p + "' )";
		Main.da.setQuery ( query );
		
	} // End method.
	
	public static void userSD ( String nickname ) throws SQLException {

		query = "INSERT INTO UserSD VALUES ( ( SELECT idUser FROM User WHERE nickname like '" + nickname + "%' ), ( SELECT idSD FROM SharedDirectory WHERE name LIKE 'Shared " + nickname + "%' ) );"; 
		Main.da.setQuery ( query );
		
	} // End method.

} // End class.
