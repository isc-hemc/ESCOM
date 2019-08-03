package Database;

import java.sql.*;

public class DataAccess {
	
	private final String password = "David";
	private final String db = "Dropbox";
	private final String user = "root";
	private final String url = "jdbc:mysql://localhost/" + db;
	private Connection con = null;
	
	public DataAccess ( ) throws ClassNotFoundException, SQLException {
		
		Class.forName ( "com.mysql.jdbc.Connection" );
		con = ( Connection ) DriverManager.getConnection ( url, user, password );
		if ( con != null ) {
			System.out.println ( "\n\tConnection to " + url + " database... OK.");
		} // End if.
		
	} // End constructor.
	
	public void reconnect ( ) throws SQLException {
		
		con = ( Connection ) DriverManager.getConnection ( url, user, password );
		if ( con != null ) {
			System.out.println ( "\n\tConnection to " + url + " database... OK.");
		} // End if.
		
	} // End method.
	
	public ResultSet getQuery ( String query ) {
		
		try {
			Statement s = ( Statement ) con.createStatement ( );
			ResultSet rs = s.executeQuery ( query );
			return rs;
		} catch ( SQLException sqle ) {
			sqle.printStackTrace ( );
			return null;
		} // End try - catch.
				
	} // End getQuery.
	
	public boolean setQuery ( String query ) {
		
		try {
			PreparedStatement ps = con.prepareStatement ( query );
			ps.executeUpdate ( query );
			return true;
		} catch ( Exception e ) {
			e.printStackTrace ( );
			return false;
		} // End try - catch.
		
	} // End setQuery.
	
} // End class.
