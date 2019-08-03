/* Scope of a Variable */
#include <stdio.h>

void useLocal ( void );
void useStaticLocal ( void );
void useGlobal ( void );

int x = 1; /* Global Variable */

int main ()

{
	int x = 5;
	
	printf ( "\n\n\tThe Local x out of the scope of main is: %d", x );

	{ /* Starts a new scope */
		int x = 7; /* Local variable with new scope */
		printf ( "\n\tThe Local x in the internal scope of main is: %d", x );	
	} /* End of the new scope */

	printf ( "\n\tThe Local x  in the external scope of main is: %d", x );

	useLocal (); /* Contains a Local x */
	useStaticLocal (); /* Contains a local static x */
	useGlobal (); /* Use a Global x */
	useLocal (); /* Re-Initializes a local automatic x */
        useStaticLocal (); /* Retains the previous value of x */
     	useGlobal (); /* x Global also retains his previous value */ 

	printf ( "\n\n\tThe x Local in main is: %d", x );
	printf ( "\n\n\n" );
	return 0;
} /* End of the main */

void useLocal ( void )

{
	int x = 25; /* Initializes every time the program calls useLocal */
	
	printf ( "\n\n\tThe Local x in useLocal is %d after access to useLocal", x );
	x++;
	printf ( "\n\tThe Local x in useLocal is %d before exit useLocal", x );
} /* End of useLocal */

void useStaticLocal ( void )

{
	static int x = 50; /* Will initializes only once when the program calls useStaticLocal for the first time */
	
	printf ( "\n\n\tThe Local Static x is %d after access to useLocal", x );
        x++;
     	printf ( "\n\tThe Local Static x is %d before exit useStaticLocal", x );
} /* End of useStaticLocal */

void useGlobal ( void )

{
	printf ( "\n\n\tThe Global x is %d upon access useGlobal", x );
	x *= 10;
	printf ( "\n\tThe Global x is %d upon exit useGlobal", x );
} /* End of useGlobal */ 
