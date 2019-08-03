package Bucket;

import java.io.Serializable;

public class Bucket implements Serializable {
	
	private static final long serialVersionUID = 1L;
	private int [ ] numList;
	private int id;
	
	public Bucket ( int [ ] numList, int id ) {
		
		this.numList = numList;
		this.id = id;
		
	} // End constructor.
	
	public void getBucket ( ) {
		
		System.out.println ( "\n\tBucket ID: " + id + ". Bucket size: " + numList.length  );
		for ( int i = 0 ; i < numList.length ; i++ ) {
			if ( i % 20 != 0 ) {
				System.out.print ( "\t" + numList [ i ] );
			} else {
				System.out.print ( "\n\t" + numList [ i ] );
			} // End if - else.
		} // End for.
		
	} // End getter.
	
	public int [ ] getList ( ) { return this.numList; } 
	
	public int getID ( ) { return this.id; }

} // End class.
