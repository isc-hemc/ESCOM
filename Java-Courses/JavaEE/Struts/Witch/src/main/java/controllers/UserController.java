package controllers;

import org.apache.struts2.rest.DefaultHttpHeaders;
import org.apache.struts2.rest.HttpHeaders;
import com.opensymphony.xwork2.ModelDriven;
import dao.implementation.UserDaoImpl;

public class UserController implements ModelDriven<Object> {

	private UserDaoImpl udi;
	private Object model;
	private String id;
	
	public Object getModel() {
		return model;
	}
	
	/* End-point for GET all request */
	public HttpHeaders index() {
		udi = new UserDaoImpl();
		model = udi.findAll();
		return new DefaultHttpHeaders("index").disableCaching();
	}
	
	/* End-point for GET request */
	public String show() {
		udi = new UserDaoImpl();
		model = udi.findById(Integer.parseInt(this.id));
		return "GET";
	}
	
	/* End-point for POST request */
	public String create() {
		// TODO: implement create.
        return "POST";
    }
	
	/* End-point for PUT request */
	public String update() {
		// TODO: implement update.
        return "PUT";
    }
	
	/* End-point for DELETE request */
	public String destroy() {
		udi = new UserDaoImpl();
		udi.delete(Integer.parseInt(this.id));
		return "DELETE";
	}
	
	/* Getter and Setter for URL user identifier */
	/* Example: http://localhost:8080/witch/user/user_id/ */
	public String getId() {
		return this.id;
	}
	
	public void setId(String id) {
		this.id = id;
	}

}
