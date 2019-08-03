import java.util.Scanner; /* Import the class Scanner */

public class PrimeNumbers {

	public static void main ( String [ ] args ) {

		Scanner Number = new Scanner ( System. in );

		int Integer;
		int Counter;

		System.out.println ( "\n\t\t\tPRIME NUMBERS" );
		System.out.print ( "\n\tEnter an Integer to see if it's a Prime Number: " );

		Integer = Number.nextInt ( );

		if ( Integer == 1 ) {
                	System.out.println ( "\n\tThe Integer isn't a Prime Number." );
                } /* End of the if. */

		for ( Counter = 1 ; Counter < Integer ; Counter++ ) {
			if ( Integer == 2 ) {
				System.out.println ( "\n\tThe Integer is a Prime Number." );
			} /* End of the if. */
			if ( Counter != 1 && Integer % Counter == 0 ) { 
				System.out.println ( "\n\tThe Integer isn't a Prime Number." );
				break;
			} /* End of the if. */ 
			if ( Integer % Counter != 0 && Counter == Integer - 1 ) { 
				System.out.println ( "\n\tThe Integer is a Prime Number." );
			} /* End of the if. */
		} /* End of the For. */		
	
		System.out.print ( "\n" );

	} /* End of the main method. */
} /* End of the public Class. */
