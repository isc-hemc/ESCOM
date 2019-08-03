package com.Davestring.Hibernate;

import com.Davestring.Hibernate.DAO.Implementation.*;
import com.Davestring.Hibernate.Model.*;

public class App {
	
    public static void main ( String [ ] args ) {
    	
    	Teacher teacher = new Teacher ( "David", "Davestring" );
    	TeacherDaoImpl daoTeacher = new TeacherDaoImpl ( );
    	
    	// Create or save a new teacher into the DB.
    	daoTeacher.createTeacher ( teacher );
    	    	
    } // End main.
    
} // End class.
