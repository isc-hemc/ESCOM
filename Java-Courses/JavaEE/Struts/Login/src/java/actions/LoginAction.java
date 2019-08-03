package actions;

import com.opensymphony.xwork2.ActionSupport;
import com.opensymphony.xwork2.Action;
import dao.implementation.UserDaoImpl;
import model.User;

public class LoginAction extends ActionSupport {
    
    UserDaoImpl userDaoImpl = new UserDaoImpl();
    String username;
    String password;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
    
    public String execute() {
        User user = userDaoImpl.findByUsernameAndPassword(username, password);
        if(user != null) {
            return Action.SUCCESS;
        }
        return Action.INPUT;
    }
}
