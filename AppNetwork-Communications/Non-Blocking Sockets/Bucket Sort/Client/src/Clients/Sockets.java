package Clients;

import java.util.ArrayList;
import Bucket.Bucket;
import java.net.*;
import java.io.*;
import Main.Main;

/* The class Sockets initialize a 'n' number of blocking server sockets, one per
 * bucket to receive, this buckets will be objects and each server will sort the
 * content of the bucket and will send back the object to the client.
 */

public class Sockets {
	
	public static ArrayList <Integer> aList;
	public static ObjectOutputStream oos;
	public static ObjectInputStream ois;
	public static int [ ] numList;
	public static Integer aux;
	public static Socket cl;
	public static Bucket b;
	
	public static boolean init ( Integer port, Integer aux ) {
		
		Sockets.aux = aux;
		
		try {
			cl = new Socket ( "127.0.0.1", port );
			return true;
		} catch ( Exception e ) {
			return false;
		} // End try - catch.
		
	} // End method.
	
	public static Bucket recv ( ) throws Exception {
		
		ois = new ObjectInputStream ( cl.getInputStream ( ) );
		Bucket b1 = ( Bucket ) ois.readObject ( );
		ois.close ( );
		
		return b1;
		
	} // End method.
	
	public static void send ( int id ) throws Exception {
		
		oos = new ObjectOutputStream ( cl.getOutputStream ( ) );
		Bucket b = createBucket ( id );
		oos.writeObject ( b );
		oos.flush ( );

	} // End method.
	
	public static Bucket createBucket ( int id ) {
		
		aList = new ArrayList <Integer> ( );
		
		for ( int i = 0 ; i < Main.numList.length ; i++ ) {
			if ( Main.numList [ i ] >= aux && Main.numList [ i ] <= Operations.Readable.subrange + aux ) {
				aList.add ( Main.numList [ i ] );
			} // End if.
		} // End for.
		
		numList = new int [ aList.size ( ) ];

		for ( int i = 0 ; i < aList.size ( ) ; i++ ) {
			numList [ i ] = aList.get ( i );
		} // End for.
		
		Bucket b = new Bucket ( numList, id );
		
		return b;
		
	} // End method.

} // End class.
