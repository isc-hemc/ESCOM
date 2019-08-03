package dao;

import java.util.ArrayList;
import models.User;

public interface UserDao {

	void create(User user);
	
	void update(User user);
	
	void delete(Integer id);
	
	User findById(Integer id);
	
	User findByUsername(String username);
	
	User findByUsernameAndPassword(String username, String password);
	
	ArrayList<User> findAll();
	
}
