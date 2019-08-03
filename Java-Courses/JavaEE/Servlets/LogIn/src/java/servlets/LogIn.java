package servlets;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpServletRequest;
import daos.implementation.UserDaoImpl;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpSession;
import javax.servlet.ServletException;
import javax.servlet.ServletContext;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import model.User;

public class LogIn extends HttpServlet {
    
    private final UserDaoImpl userDaoImpl = new UserDaoImpl();
    private Integer attempts = 3;
    private Boolean flag = false;
    private User user;
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        // Set MIME type and get PrintWriter object.
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        // Get current session and set the 'attempts' and 'failed' attributes.
        HttpSession session = request.getSession(true);
        if(session.getAttribute("attempts") == null) {
            session.setAttribute("attempts", attempts);
            session.setAttribute("failed", false);
        } // if.
        // Get username and password from the login.
        String username = request.getParameter("username");
        String password = request.getParameter("password");   
        // Validate if the user exists.
        user = userDaoImpl.findByUsernameAndPassword(username, password);
        // If the user exists, redirect to the Welcome Page.
        if(user.getId() != null) {
            session.setAttribute("username", user.getUsername());
            response.sendRedirect("welcome.html");
        } else {
            // If the user failed to log-in more than 3 times, the IP and Port will be registered in the log file.
            if(attempts > 1) {
                attempts = (Integer) session.getAttribute("attempts") - 1;
                session.setAttribute("attempts", attempts);
                RequestDispatcher rd = request.getRequestDispatcher("index.html");
                String message = "<h3 style='color: red;'>Invalid username or password, you have " + attempts + " attempts.</h3>";
                out.println(message);
                rd.include(request, response);
            } else {
                if(!((Boolean)session.getAttribute("failed"))) {
                    response.sendRedirect("fail.html");
                    session.setAttribute("failed", true);
                    ServletContext context = request.getServletContext();
                    context.log("User failed to log-in: " + request.getRemoteAddr() + ":" + request.getRemotePort());
                } else {
                    Long lastAccessedTime = session.getLastAccessedTime();
                    Long currentTime = new Date().getTime();
                    Long difference = currentTime - lastAccessedTime;
                    if(difference >= 18000) {
                        attempts = 3;
                        session.setAttribute("attempts", attempts);
                        response.sendRedirect("index.html");
                        session.setAttribute("failed", false);
                    } else {
                        response.sendRedirect("fail.html");
                    }
                } // else.
            } // else.
        } // else.
    } // method.

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    } // method.

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    } // method.

} // class.
