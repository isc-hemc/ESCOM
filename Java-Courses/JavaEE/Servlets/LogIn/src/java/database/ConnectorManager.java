package database;

import com.mysql.jdbc.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectorManager {
    
    private String db = "login";
    private String user = "root";
    private String password = "password";
    private String url = "jdbc:mysql://localhost/" + db + "?allowPublicKeyRetrieval=true&useSSL=false";
    private Connection conn;
    
    public ConnectorManager() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            this.conn = (Connection) DriverManager.getConnection(url, user, password);
            if(this.conn != null) {
                System.out.println ( "\n\tConnection to " + url + " database... OK.");
            } // if.
        } catch(ClassNotFoundException cnfe) {
            System.out.println("Class not found in Connector: " + cnfe);
        } catch(SQLException sqle) {
            System.out.println("SQL Exception in Connector: " + sqle);
        }
    } // constructor.
    
    public Connection getConnector() {
        return this.conn;
    } // getter.
    
} // class.
