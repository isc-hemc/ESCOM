package Sockets;

import java.nio.ByteBuffer;
import java.io.*;

public class sendFile {

	private static DataOutputStream dos;
	private static DataInputStream dis;
	public static String dir;
	private static long size;
	private static int n;
	
	public static void store ( String name, String path, String dir, String nickname, Client cl ) {
		
		try {
			ByteBuffer buffer = ByteBuffer.wrap ( ( "<store>:" + nickname ).getBytes ( ) );
			Main.SocketClient.cl.write ( buffer );
			size = new File ( path ).length ( );
			dos = new DataOutputStream ( cl.getSocket ( ).getOutputStream ( ) );
			dos.writeUTF ( dir );
			dos.flush ( );
			dos.writeUTF ( name.replace ( " ", "" ) );
			dos.flush ( );
			dos.writeLong ( size );
			dis = new DataInputStream ( new FileInputStream ( path ) );
			long sent = 0;
			while ( sent < size ) {
				byte [ ] b = new byte [ 2000 ];
				n = dis.read ( b );
				sent = sent + n;
				dos.write ( b );
				dos.flush ( );
			} // End while.
		} catch ( Exception e ) {
			e.printStackTrace ( );
		} // End try catch.
		
	} // End method.
	
} // End class.
