package Sockets;

import java.io.*;

public class recvFile {

	private static BufferedOutputStream bos;
	private static BufferedInputStream bis;
	private static DataInputStream dis;
	private static String name;
	private static long size;
	private static long recv;
	private static int n;
	
	public static void download ( Client cl ) {
	
		try {
			dis = new DataInputStream ( cl.getSocket ( ).getInputStream ( ) );
			name = dis.readUTF ( );
			size = dis.readLong ( );
			recv = 0;
			bos = new BufferedOutputStream ( new FileOutputStream ( new File ( "../.././" + name ) ) );
			bis = new BufferedInputStream ( cl.getSocket ( ).getInputStream ( ) );
			while ( recv < size ) {
				byte [ ] b = new byte [ 2000 ];
				n = bis.read ( b );
				recv = recv + n;
				bos.write ( b, 0, n );
			} // End while.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try - catch.
		
	} // End method.
	
} // End class.
