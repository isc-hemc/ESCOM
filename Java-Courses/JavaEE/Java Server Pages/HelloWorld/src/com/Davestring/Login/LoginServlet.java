package com.Davestring.Login;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpServletRequest;
import com.Davestring.Login.Beans.LoginBean;
import javax.servlet.annotation.WebServlet;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import java.io.IOException;

@WebServlet ( "/LoginServlet" )
public class LoginServlet extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
       
    public LoginServlet ( ) {
        super ( );
    } // End constructor.

	protected void doGet ( HttpServletRequest request, HttpServletResponse response ) throws ServletException, IOException {
		response.getWriter ( ).append ( "Served at: " ).append ( request.getContextPath ( ) );
	} // End doGet.

	protected void doPost ( HttpServletRequest request, HttpServletResponse response ) throws ServletException, IOException {
		
		String name = request.getParameter ( "Name" );
		String password = request.getParameter ( "Password" );
		LoginBean login = new LoginBean ( );
		
		login.setName ( name );
		login.setPassword ( password );
		
		// RequestDispatcher generate the response that we want to send.
		RequestDispatcher dis = null;

		if ( login.validation ( ) ) {
			dis = request.getRequestDispatcher ( "welcome.jsp" );
		} else {
			dis = request.getRequestDispatcher ( "error.jsp" );
		} // End if - else.
		
		// Send the response.
		dis.forward ( request, response );
	
	} // End doPost.

} // End class.
