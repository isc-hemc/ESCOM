package dao;

import java.util.ArrayList;
import model.User;

public interface UserDao {
    
    void create(User user);
   
    void update(User user);
    
    void delete(Long id);
    
    User findById(Long id);
    
    User findByUsername(String username);
    
    User findByUsernameAndPassword(String username, String password);
    
    ArrayList<User> findAll();
    
} // Interface.