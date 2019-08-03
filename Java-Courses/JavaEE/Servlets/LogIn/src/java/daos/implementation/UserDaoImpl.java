package daos.implementation;

import database.ConnectorManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.util.ArrayList;
import daos.UserDao;
import model.User;

public class UserDaoImpl implements UserDao {
    
    ConnectorManager cm;
    Connection conn;
    
    public UserDaoImpl() {
        cm = new ConnectorManager();
        conn = cm.getConnector();
    } // constructor.
    
    @Override
    public void create(User user) {
        try {
            String query = "INSERT INTO user (username, password) VALUE (?, ?)";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setString(1, user.getUsername());
            statement.setString(2, user.getPassword());
            Integer rowsInserted = statement.executeUpdate();
            if(rowsInserted > 0) {
                System.out.println("New User inserted succesfully.");
            } // if.
        } catch (SQLException ex) {
            System.out.println("Cannot insert user: " + ex);;
        } // catch.
    } // method.

    @Override
    public void update(User user) {
        try {
            String query = "UPDATE user SET username=?, password=? WHERE id=?";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setString(1, user.getUsername());
            statement.setString(2, user.getPassword());
            statement.setInt(3, user.getId());
            Integer rowsUpdated = statement.executeUpdate();
            if(rowsUpdated > 0) {
                System.out.println("User updated succesfully.");
            } // if.
        } catch (SQLException ex) {
            System.out.println("Cannot update user: " + ex);;
        } // catch.
    } // method.

    @Override
    public void delete(Integer id) {
        try {
            String query = "DELETE user WHERE id=?";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setInt(1, id);
            Integer rowsDeleted = statement.executeUpdate();
            if(rowsDeleted > 0) {
                System.out.println("User deleted succesfully.");
            } // if.
        } catch (SQLException ex) {
            System.out.println("Cannot delete user: " + ex);;
        } // catch.
    } // method.

    @Override
    public User findById(Integer id) {
        User user = new User(null, null, null);
        try {
            String query = "SELECT * FROM user WHERE id=?";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setInt(1, id);
            ResultSet rs = statement.executeQuery();
            if(rs.next()) {
                user.setId(rs.getInt(1));
                user.setUsername(rs.getString(2));
                user.setPassword(rs.getString(3));
            } // if.
        } catch (SQLException ex) {
            System.out.println("Cannot find user: " + ex);;
        } // catch.
        String consoleOutput = "User: (%d, %s, %s)";
        System.out.println(String.format(consoleOutput, user.getId(), user.getUsername(), user.getPassword()));
        return user;
    } // method.

    @Override
    public User findByUsername(String username) {
        User user = new User(null, null, null);
        try {
            String query = "SELECT * FROM user WHERE username=?";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setString(1, username);
            ResultSet rs = statement.executeQuery();
            if(rs.next()) {
                user.setId(rs.getInt(1));
                user.setUsername(rs.getString(2));
                user.setPassword(rs.getString(3));
            } // if.
        } catch (SQLException ex) {
            System.out.println("Cannot find user: " + ex);;
        } // catch.
        String consoleOutput = "User: (%d, %s, %s)";
        System.out.println(String.format(consoleOutput, user.getId(), user.getUsername(), user.getPassword()));
        return user;
    } // method.
    
    @Override
    public User findByUsernameAndPassword(String username, String password) {
        User user = new User(null, null, null);
        try {
            String query = "SELECT * FROM user WHERE username=? and password=?";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setString(1, username);
            statement.setString(2, password);
            ResultSet rs = statement.executeQuery();
            if(rs.next()) {
                user.setId(rs.getInt(1));
                user.setUsername(rs.getString(2));
                user.setPassword(rs.getString(3));
            } // if.
        } catch (SQLException ex) {
            System.out.println("Cannot find user: " + ex);;
        } // catch.
        String consoleOutput = "User: (%d, %s, %s)";
        System.out.println(String.format(consoleOutput, user.getId(), user.getUsername(), user.getPassword()));
        return user;
    } // method.

    @Override
    public ArrayList<User> findAll() {
        ArrayList<User> users = new ArrayList<User>() {};
        try {
            String query = "SELECT * FROM user";
            PreparedStatement statement = conn.prepareStatement(query);
            ResultSet rs = statement.executeQuery();
            while(rs.next()) {
                User user = new User();
                user.setId(rs.getInt(1));
                user.setUsername(rs.getString(2));
                user.setPassword(rs.getString(3));
                users.add(user);
                String consoleOutput = "User: (%d, %s, %s)";
                System.out.println(String.format(consoleOutput, user.getId(), user.getUsername(), user.getPassword()));
            } // while.
        } catch (SQLException ex) {
            System.out.println("Cannot find all users: " + ex);;
        } // catch.
        return users;
    } // method.
    
} // class.
