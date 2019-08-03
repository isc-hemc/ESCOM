package com.Davestring.Hibernate;

import org.hibernate.cfg.Configuration;
import org.hibernate.SessionFactory;
import org.hibernate.Session;

public class InitSession {
	
	private Session session;
	
	public InitSession ( ) {
	
		/* SessionFactory and Configuration read the file "hibernate.cfg.xml":
		 * Password, URL, port, user etc. and the object session "initialize" a
		 * session allowing the user to manipulate the data.
		 */
		
		Configuration conf = new Configuration ( );
    	conf.configure ( );
		SessionFactory sessionFactory = conf.buildSessionFactory ( );
    	session = sessionFactory.openSession ( );
    	session.beginTransaction ( );
		
	} // End constructor.

	public Session getSession ( ) {
		return session;
	} // End method
	
} // End class.
