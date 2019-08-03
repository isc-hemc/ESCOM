package Hangman;

public class Answer {
	
	private static String answer;
	private static boolean flag;
	private static String s;

	public static boolean Compare ( String str, Integer port ) {
		
		answer = str;
		s = Main.hm.get ( port );
		
		if ( Main.difficult.get ( port ).equalsIgnoreCase ( "easy" ) ) {
			Easy ( port );
		} else {
			Hard ( port );
		} // End if - else.
		
		return flag;
		
	} // End Compare.
	
	public static void Easy ( Integer port ) {
		
		if ( answer.equalsIgnoreCase ( "e" ) ) {
			s = s.replace ( "*", "e" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "l" ) ) {
			s = s.replace ( "_", "l" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "r" ) ) {
			s = s.replace ( "$", "r" );
			flag = true;
		} else {
			flag = false;
		} // End if - else.
		
		Main.hm.replace ( port, s );
		
	} // End Easy.
	
	public static void Hard ( Integer port ) {
		
		if ( answer.equalsIgnoreCase ( "a" ) ) {
			s = s.replace ( "_", "a" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "p" ) ) {
			s = s.replace ( "*", "p" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "i" ) ) {
			s = s.replace ( ".", "i" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "o" ) ) {
			s = s.replace ( "#", "o" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "e" ) ) {
			s = s.replace ( "?", "e" );
			flag = true;
		} else if ( answer.equalsIgnoreCase ( "m" ) ) {
			s = s.replace ( "¿", "m" );
			flag = true;
		} else {
			flag = false;
		} // End if - else.
		
		Main.hm.replace ( port, s );
		
	} // End Hard.
	
} // End class.
