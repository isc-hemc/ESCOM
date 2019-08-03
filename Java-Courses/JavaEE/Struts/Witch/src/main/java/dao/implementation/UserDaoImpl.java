package dao.implementation;

import database.ConnectorManager;
import java.util.ArrayList;
import dao.UserDao;
import models.User;

public class UserDaoImpl implements UserDao {
	
	private ConnectorManager conn = new ConnectorManager();

	public void create(User user) {
		conn.getSession().persist(user);
		conn.getSession().getTransaction().commit();
	}

	public void update(User user) {
		conn.getSession().update(user);
		conn.getSession().getTransaction().commit();
	}

	public void delete(Integer id) {
		conn.getSession().delete(conn.getSession().get(User.class, id));
		conn.getSession().getTransaction().commit();
	}

	public User findById(Integer id) {
		try {
			String query = "FROM User WHERE id = '" + id.toString() + "'";
			return (User) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}

	public User findByUsername(String username) {
		try {
			String query = "FROM User WHERE username = '" + username + "'";
			return (User) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}

	public User findByUsernameAndPassword(String username, String password) {
		try {
			String query = "FROM User WHERE username = '" + username + "' AND password = '" + password + "'";
			return (User) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}

	@SuppressWarnings("unchecked")
	public ArrayList<User> findAll() {
		return (ArrayList<User>) conn.getSession().createQuery("FROM User").list();
	}

}
