import dao.implementation.UserDaoImpl;
import java.util.ArrayList;
import model.User;

public class TestUsersHibernate {
    
    public static UserDaoImpl userDaoImpl = new UserDaoImpl();
    
    public static void main(String[] args) {
        Long id = new Long(5);
        findUserById(id);
    }
    
    public static void createUser(User user) {
        userDaoImpl.create(user);
    }
    
    public static void updateUser(User user, String password) {
        user.setPassword(password);
        userDaoImpl.update(user);
    }
    
    public static void deleteUser(Long id) {
        userDaoImpl.delete(id);
    }
    
    public static void findUserById(Long id) {
        User user = userDaoImpl.findById(id);
        System.out.println("Find by id: " + user.toString());
    }
    
    public static void findUserByUsername(String username) {
        User user = userDaoImpl.findByUsername(username);
        System.out.println("Find by username: " + user.toString());
    }
    
    public static void findUserByUsernameAndPassword(String username, String password) {
        User user = userDaoImpl.findByUsernameAndPassword(username, password);
        System.out.println("Find by username and password: " + user.toString());
    }
    
    public static void findAllUsers() {
        ArrayList<User> users = userDaoImpl.findAll();
        System.out.println("Find all users:");
        for(User user : users) {
            System.out.println("\t- " + user.toString());
        }
    }

}