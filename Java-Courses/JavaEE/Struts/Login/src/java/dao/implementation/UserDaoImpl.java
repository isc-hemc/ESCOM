package dao.implementation;

import database.ConnectorManager;
import java.util.ArrayList;
import dao.UserDao;
import model.User;

public class UserDaoImpl implements UserDao {

    private ConnectorManager connectorManager;
    
    public UserDaoImpl() {
        connectorManager = new ConnectorManager();
    }
    
    @Override
    public void create(User user) {
        connectorManager.getSession().persist(user);
        connectorManager.getSession().getTransaction().commit();
    }

    @Override
    public void update(User user) {
        connectorManager.getSession().update(user);
        connectorManager.getSession().getTransaction().commit();
    }

    @Override
    public void delete(Long id) {
        connectorManager.getSession().delete(connectorManager.getSession().get(User.class, id));
        connectorManager.getSession().getTransaction().commit();
    }

    @Override
    public User findById(Long id) {
        try {
            String query = "FROM User WHERE id = '" + id.toString() + "'";
            return (User) connectorManager.getSession().createQuery(query).uniqueResult();
        } catch(Exception e) {
            return null;
        }
    }

    @Override
    public User findByUsername(String username) {
        try {
            String query = "FROM User WHERE username LIKE '" + username + "'";
            return (User) connectorManager.getSession().createQuery(query).uniqueResult();
        } catch(Exception e) {
            return null;
        }
    }

    @Override
    public User findByUsernameAndPassword(String username, String password) {
        try {
            String query = "FROM User WHERE username LIKE '" + username + "' AND password LIKE '" + password + "'";
            return (User) connectorManager.getSession().createQuery(query).uniqueResult();
        } catch(Exception e) {
            return null;
        }
    }

    @Override
    public ArrayList<User> findAll() {
        return (ArrayList<User>) connectorManager.getSession().createQuery("FROM User").list();
    }

} // class.
