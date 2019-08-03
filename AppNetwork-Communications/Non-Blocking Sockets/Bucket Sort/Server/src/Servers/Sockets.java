package Servers;

import Bucket.Bucket;
import java.net.*;
import java.io.*;

/* The class Sockets initialize a 'n' number of blocking server sockets, one per
 * bucket to receive, this buckets will be objects and each server will sort the
 * content of the bucket and will send back the object to the client.
 */

public class Sockets {
	
	public static ObjectOutputStream oos;
	public static ObjectInputStream ois;
	public static int [ ] numList;
	public static ServerSocket s;
	public static Socket cl;
	public static Bucket b;
	public static int aux;
	
	public static boolean init ( Integer port ) {
		
		try {
			s = new ServerSocket ( port );
			s.setReuseAddress ( true );
			System.out.println ( "\n\t\t\tSub-service initialized: " + s.getInetAddress ( ).getHostAddress ( ) + " : " + s.getLocalPort ( ) + ".\n\t\t\tWaiting for bucket." );
			return true;
		} catch ( Exception e ) {
			return false;
		} // End try - catch.
		
	} // End method.
	
	public static Bucket recv ( ) throws Exception {
		
		cl = s.accept ( );
		ois = new ObjectInputStream ( cl.getInputStream ( ) );
		Bucket b = ( Bucket ) ois.readObject ( );
		System.out.println ( "\n\n\t\t\t\tClient connected from: " + cl.getInetAddress ( ) + " : " + cl.getPort ( ) + "." );
		
		return b;
		
	} // End method.
	
	public static void send ( Bucket b ) throws Exception {
		
		Bucket sort = BubbleSort ( b );
		oos = new ObjectOutputStream ( cl.getOutputStream ( ) );
		sort.getBucket ( );
		oos.writeObject ( sort );
		oos.flush ( );
		
	} // End method.
	
	public static Bucket BubbleSort ( Bucket b ) {
		
		numList = b.getList ( );
		
		for ( int counter = 1 ; counter < numList.length ; counter++ ) {
			for ( int scounter = 0 ; scounter < numList.length - 1 ; scounter++ ) {
				if ( numList [ scounter ] > numList [ scounter + 1 ] ) {
					aux = numList [ scounter ];
					numList [ scounter ] = numList [ scounter + 1 ];
					numList [ scounter + 1 ] = aux;
				} // End if.
			} // End nested for.
		} // End for.

		Bucket b1 = new Bucket ( numList, b.getID ( ) );
				
		return b1;
		
	} // End method.

} // End class.
