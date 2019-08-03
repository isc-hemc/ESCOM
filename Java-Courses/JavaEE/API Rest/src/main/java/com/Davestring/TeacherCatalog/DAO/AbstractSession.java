package com.Davestring.TeacherCatalog.DAO;

import org.springframework.beans.factory.annotation.Autowired;
import org.hibernate.SessionFactory;
import org.hibernate.Session;

public abstract class AbstractSession {
	
	@Autowired
	private SessionFactory sessionFactory;
	
	protected Session getSession ( ) {
		return sessionFactory.getCurrentSession ( );
	} // End method.
	
} // End abstract class.
