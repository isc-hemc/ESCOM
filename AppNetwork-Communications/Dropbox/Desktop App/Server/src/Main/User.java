package Main;

import Sockets.*;

public class User {

	public String lastName;
	public String nickname;
	public String password;
	public String email;
	public String name;
	public Server s;

	public User ( String name, String lastName, String nickname, String email, String password ) {
		
		this.lastName = lastName;
		this.nickname = nickname;
		this.password = password;
		this.email = email;
		this.name = name;

	} // End constructor.
	
	public void setSocket ( Server s ) {
		this.s = s;
	} // End setter.
	
	public Server getServer ( ) {
		return this.s;
	} // End getter.
	
	public String getName ( ) {
		return this.name;
	} // End getter.
	
	public String getLastName ( ) {
		return this.lastName;
	} // End getter.
	
	public String getNickname ( ) {
		return this.nickname;
	} // End getter.
	
	public String getEmail ( ) {
		return this.email;
	} // End getter.
	
	public String getPassword ( ) {
		return this.password;
	} // End getter.
	
} // End class.
