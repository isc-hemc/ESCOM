package database;

import org.hibernate.cfg.Configuration;
import org.hibernate.SessionFactory;
import org.hibernate.Session;

public class ConnectorManager {
    
    private Session session;
    
    public ConnectorManager() {
        Configuration config = new Configuration();
        config.configure();
        SessionFactory sessionFactory = config.buildSessionFactory();
        session = sessionFactory.openSession();
        session.beginTransaction();
    }
    
    public Session getSession() {
        return session;
    }
}