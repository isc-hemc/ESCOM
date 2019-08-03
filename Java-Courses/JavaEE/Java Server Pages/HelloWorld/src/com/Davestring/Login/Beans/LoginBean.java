package com.Davestring.Login.Beans; 

import java.io.Serializable;

public class LoginBean implements Serializable {

	private static final long serialVersionUID = 1L;
	private String password;
	private String name;
	
	public LoginBean ( ) { }
	
	public String getPassword ( ) {
		return password;
	} // End getter.
	
	public String getName ( ) {
		return name;
	} // End getter.
	 
	public void setPassword ( String password ) {
		this.password = password;
	} // End setter.
	
	public void setName ( String name ) {
		this.name = name;
	} // End setter.
	
	public boolean validation ( ) {
		return ( password.equals ( "HelloWorld" ) ) ? true : false;
	} // End method.
	
} // End method.