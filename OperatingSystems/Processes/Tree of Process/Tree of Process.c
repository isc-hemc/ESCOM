#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void TreeProcess ( );
void FirstChild ( int nLevels );
void SecondChild ( int nLevels );

int main ( ) { TreeProcess ( ); } /* End of main. */

void TreeProcess ( ) { /* Contruct the main two process childs. */

  int idProcess; /* Stores the return variable of the fork. */
  int status = 0; /* Status of the process. */
  int nLevels; /* Establish the number of levels of the tree process. */
  int chooseLevels = 0; /* Variable that will help the user to choose only ones the number of levels at the standar input. */
  int counter = 0;

  if ( chooseLevels == 0 ) {
    printf ( "\n\n\t\tOPERATING SYSTEMS: TREE OF PROCESS." );
    printf ( "\n\n\tAdd the number of levels for this process: " );
    scanf ( "%d", &nLevels );
    chooseLevels++;
  } /* End of the if. */

  for ( counter = 0 ; counter < 2 ; counter++ ) { /* We only need two childs of the main process. */
    idProcess = fork ( ); /* Creates a copy of the main process. */
    switch ( idProcess ) {
      case 0:
        if ( counter == 0 ) { /* For the first child of the main process. */
          printf ( "\n\tFirst child of the main process: %d.", getpid ( ) );
          printf ( "\tThe parent id is: %d.\n", getppid ( ) );
          FirstChild ( nLevels );
        } /* End of the if. */
        if ( counter == 1 ) { /* For the second child of the main process. */
          printf ( "\n\n\tSecond child of the main process: %d.", getpid ( ) );
          printf ( "\tThe parent id is: %d.\n", getppid ( ) );
          SecondChild ( nLevels );
        } /* End of the if. */
        exit ( 0 );
      case -1:
        printf ( "\n\tError creating new process." );
        exit ( 0 );
      default:
        if ( counter == 0 ) { /* For the id of the main parent process. */
          printf ( "\n\tMain parent process: %d.\n", getpid ( ) ); /* getpid, for the main parent, because the parent of the main process it's the shell. */
        } /* End of the if. */
        wait ( &status ); /* wait for the end of childs process. */
    } /* End of switch. */
  } /* End of the For. */

  printf ( "\n\n" );

} /* End of TreeProcess Function. */

void FirstChild ( int nLevels ) { /* COntruct the levels of the main first child. */

  int processCounter = 0;
  //int x = 0;
  int status = 0;
  int idProcess; /* Stores the return variable of the fork. */

  for ( processCounter = 0 ; processCounter < 3 ; processCounter++ ) { /* Controls the number of childs per level. */
    idProcess = fork ( );
    switch ( idProcess ) {
      case 0:
        printf ( "\n\tChild process id: %d.", getpid ( ) );
        printf ( "\tParent id: %d.", getppid ( ) );
        if ( nLevels > 1 ) {
          FirstChild ( nLevels - 1 ); /* Recursive function that controls the tree levels. */
        } /* End of the if. */
        exit ( 0 );
      case -1:
        printf ( "\n\n\tError creating new process." );
        exit ( 0 );
      default:
        wait ( &status );
    } /* End of the switch. */
  } /* End of the For. */

} /* End of FirstChild Function. */

void SecondChild ( int nLevels ) { /* Construct the levels of the main second child. */

  int processCounter = 0;
  int status = 0;
  int idProcess; /* Stores the return variable of the fork. */

  for ( processCounter = 0 ; processCounter < 4 ; processCounter++ ) { /* Controls the number of childs per level. */
    idProcess = fork ( );
    switch ( idProcess ) {
      case 0:
        printf ( "\n\tChild process id: %d.", getpid ( ) );
        printf ( "\tParent id: %d.", getppid ( ) );
        if ( nLevels > 1 ) {
          SecondChild ( nLevels - 1 ); /* Recursive function that controls the tree levels. */
        } /* End of the if. */
        exit ( 0 );
      case -1:
        printf ( "\n\n\tError creating new process." );
        exit ( 0 );
      default:
        wait ( &status );
        break;
    } /* End of the switch. */
  } /* End of the For. */

} /* End of the SecondChild Function. */
