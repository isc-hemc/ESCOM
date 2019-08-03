package Sockets;

import java.sql.SQLException;
import java.net.*;
import java.io.*;
import Main.*;

public class recvFile {
	
	private static BufferedOutputStream bos;
	private static BufferedInputStream bis;
	private static DataInputStream dis;
	private static String directory;
	private static String name;
	private static Socket cl;
	private static long recv;
	private static long size;
	private static int n;

	public static void recv ( Server s, String nickname ) throws SQLException {
		
		try {
			cl = s.getClient ( );
			dis = new DataInputStream ( cl.getInputStream ( ) );
			directory = dis.readUTF ( );
			name = dis.readUTF ( );
			size = dis.readLong ( );
			System.out.println ( "\n\t\t\tReceiving file from: " + cl.getLocalPort() + ":" + cl.getPort ( ) + ". Name: " + name );
			bos = new BufferedOutputStream ( new FileOutputStream ( new File ( directory + "/" + name ) ) );
			bis = new BufferedInputStream ( cl.getInputStream ( ) );
			recv = 0;
			while ( recv < size ) {
				byte [ ] b = new byte [ 2000 ];
				n = bis.read ( b );
				recv = recv + n;
				bos.write ( b, 0, n );
			} // End while.
			bos.close ( );
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		/* Store the new file on the database. */
		mysqlQuery ( directory, nickname );
		
	} // End method.
	
	private static void mysqlQuery ( String directory, String nickname ) {
		
		String [ ] split = directory.split ( "/" );
		String aux = split [ 3 ];
		split = aux.split ( " " );
		if ( split.length == 2 ) {
			Main.da.setQuery ( "INSERT INTO SharedFiles ( name, path, idSD ) VALUES ( '" + name + "', '" + directory + "/" + name + "', ( SELECT d.idSD FROM UserSD d, SharedDirectory x, User u WHERE d.idUser = u.idUser AND x.idSD = d.idSD AND x.name LIKE 'Shared " + nickname + "' AND u.nickname LIKE '" + nickname + "%' ) );" );
		} else {
			Main.da.setQuery ( "INSERT INTO Files ( name, path, idDirectory ) VALUES ( '" + name + "', '" + directory + "/" + name + "', ( SELECT d.idDirectory FROM Directory d, User u WHERE d.idUser = u.idUser AND u.nickname LIKE '" + nickname + "%' ) );" );
		} // End if - else.
		
	} // End method.
	
} // End class.
