package Sockets;

import java.sql.SQLException;
import java.sql.ResultSet;
import java.net.*;
import java.io.*;
import Main.*;

public class sendFile {
	
	private static DataOutputStream dos;
	private static DataInputStream dis;
	private static String path;
	private static Socket cl;
	private static long sent;
	private static long size;
	private static File f;
	
	public static void download ( Server s, String name ) {
		
		try {
			cl = s.getClient ( );
			try {
				ResultSet rs = ( ResultSet ) Main.da.getQuery ( "SELECT path FROM Files WHERE name LIKE '" + name + "%';" );
				ResultSet rs1 = ( ResultSet ) Main.da.getQuery ( "SELECT path FROM SharedFiles WHERE name LIKE '" + name + "%';" );
				while ( rs.next ( ) ) {
					path = rs.getString ( "path" );
				} // End while.
				while ( rs1.next ( ) ) {
					path = rs1.getString ( "path" );
				} // End if.
			} catch ( SQLException e ) {
				e.printStackTrace ( );
			} // End try - catch.
			f = new File ( path );
			size = f.length ( );
			dos = new DataOutputStream ( cl.getOutputStream ( ) );
			dos.writeUTF ( name );
			dos.flush ( );
			dos.writeLong ( size );
			dos.flush ( );
			dis = new DataInputStream ( new FileInputStream ( path ) );
			sent = 0;
			while ( sent < size ) {
				byte [ ] b = new byte [ 2000 ];
				int n = dis.read ( b );
				sent = sent + n;
				dos.write ( b, 0, n );
				dos.flush ( );
			} // End while.
			System.out.println ( "\n\t\tFile: " + name + " sended." );
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End method.
	
} // End download.
