import java.net.*;
import java.io.*;

public class Server {

  /* Reset will work as a reset button to play again. */
  public static BufferedReader br;
  public static PrintWriter pw;
  public static boolean reset;
  public static Socket cl;

  public static void main ( String [ ] args ) {

    try {
      int port = 9709;
      ServerSocket s = new ServerSocket ( port );
      System.out.println ( "\n\n\tHANGMAN GAME... Waiting connections." );
      for ( ; ; ) {
        cl = s.accept ( );
        System.out.println ( "\n\n\tPlayer connected from: " + cl.getInetAddress ( ) + ": " + cl.getPort ( ) );
        reset = true;
        br = new BufferedReader ( new InputStreamReader ( cl.getInputStream ( ) ) );
        char [ ] diff = new char [ 250 ];
        int n = br.read ( diff, 0, 250 );
        String str = new String ( diff, 0, n );
        if ( ( str.compareToIgnoreCase ( "Easy" ) ) == 0 ) {
          Easy ( br );
        } if ( ( str.compareToIgnoreCase ( "Moderate" ) ) == 0 ) {
          Moderate ( br );
        } if ( ( str.compareToIgnoreCase ( "Hard" ) ) == 0 ) {
          Hard ( br );
        } // End if.
      } // End for - ever.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try catch.

  } // End method.

  public static void Easy ( BufferedReader br ) {

    char [ ] recv = new char [ 50 ];
    String str = "Dog";
    String str1 = "";
    int n;
    int i;

    i = 0;

    try {
      BufferedWriter bw = new BufferedWriter ( new OutputStreamWriter ( cl.getOutputStream ( ) ) );
      bw.write ( str.replace ( "o", "_" ).toCharArray ( ), 0, str.length ( ) );
      bw.flush ( );
      while ( i < 5 && ( str1.equals ( "Congratulations" ) ) == false ) {
        n = br.read ( recv, 0, 50 );
        str1 = new String ( recv, 0, n );
        if ( str1.compareToIgnoreCase ( "o" ) == 0 ) {
          str1 = "Congratulations";
          bw.write ( str1.toCharArray ( ), 0, str1.length ( ) );
          bw.flush ( );
          bw.write ( str.toCharArray ( ), 0, str.length ( ) );
          bw.flush ( );
        } else {
          str1 = "Try Again";
          bw.write ( str1.toCharArray ( ), 0, str1.length ( ) );
          bw.flush ( );
          i++;
        } // End if - else.
      } // End while.
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

  } // End method.

  public static void Moderate ( BufferedReader br ) {

    char [ ] recv = new char [ 50 ];
    String str = "Because";
    String str1 = "";
    String aux;
    int n;
    int i;

    i = 0;

    try {
      BufferedWriter bw = new BufferedWriter ( new OutputStreamWriter ( cl.getOutputStream ( ) ) );
      bw.write ( str.replace ( "a", "_" ).replace ( "e", "*" ).replace ( "u", "@" ).toCharArray ( ), 0, str.length ( ) );
      bw.flush ( );
      aux = str.replace ( "a", "_" ).replace ( "e", "*" ).replace ( "u", "@" );
      while ( i < 3 && ( str1.equals ( "Congratulations" ) ) == false ) {
        n = br.read ( recv, 0, 50 );
        str1 = new String ( recv, 0, n );
        if ( str1.compareToIgnoreCase ( "a" ) == 0 ) {
          aux = aux.replace ( "_", "a" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else if ( str1.compareToIgnoreCase ( "e" ) == 0 ) {
          aux = aux.replace ( "*", "e" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else if ( str1.compareToIgnoreCase ( "u" ) == 0 ) {
          aux = aux.replace ( "@", "u" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else {
          str1 = "Try Again.";
          bw.write ( str1.toCharArray ( ), 0, str1.length ( ) );
          bw.flush ( );
          i++;
        } // End if - else.

        if ( aux.equals ( str ) ) {
          str1 = "Congratulations";
          bw.write ( str1.toCharArray ( ), 0, str1.length ( ) );
          bw.flush ( );
          bw.write ( str.toCharArray ( ), 0, str.length ( ) );
          bw.flush ( );
        } // End if.

      } // End while.*/
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.

  } // End method.

  public static void Hard ( BufferedReader br ) {

    char [ ] recv = new char [ 50 ];
    String str = "Network Communication";
    String str1 = "";
    String aux;
    int n;
    int i;

    i = 0;

    try {
      BufferedWriter bw = new BufferedWriter ( new OutputStreamWriter ( cl.getOutputStream ( ) ) );
      bw.write ( str.replace ( "e", "_" ).replace ( "i", "*" ).replace ( "o", "%" ).replace ( "u", "@" ).toCharArray ( ), 0, str.length ( ) );
      bw.flush ( );
      aux = str.replace ( "e", "_" ).replace ( "i", "*" ).replace ( "o", "%" ).replace ( "u", "@" );
      while ( i < 2 && ( str1.equals ( "Congratulations" ) ) == false ) {
        n = br.read ( recv, 0, 50 );
        str1 = new String ( recv, 0, n );
        if ( str1.compareToIgnoreCase ( "e" ) == 0 ) {
          aux = aux.replace ( "_", "e" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else if ( str1.compareToIgnoreCase ( "i" ) == 0 ) {
          aux = aux.replace ( "*", "i" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else if ( str1.compareToIgnoreCase ( "o" ) == 0 ) {
          aux = aux.replace ( "%", "o" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else if ( str1.compareToIgnoreCase ( "u" ) == 0 ) {
          aux = aux.replace ( "@", "u" );
          if ( !( aux.equals ( str ) ) ) {
            bw.write ( aux.toCharArray ( ), 0, aux.length ( ) );
            bw.flush ( );
          } // End if.
        } else {
          str1 = "Try Again.";
          bw.write ( str1.toCharArray ( ), 0, str1.length ( ) );
          bw.flush ( );
          i++;
        } // End if - else.

        if ( aux.equals ( str ) ) {
          str1 = "Congratulations";
          bw.write ( str1.toCharArray ( ), 0, str1.length ( ) );
          bw.flush ( );
          bw.write ( str.toCharArray ( ), 0, str.length ( ) );
          bw.flush ( );
        } // End if.

      } // End while.*/
    } catch ( Exception e ) {
      e.printStackTrace ( );
    } // End try - catch.
  } // End method.

} // End class.
