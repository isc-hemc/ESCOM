package controllers;

import org.apache.struts2.rest.DefaultHttpHeaders;
import org.apache.struts2.rest.HttpHeaders;
import com.opensymphony.xwork2.ModelDriven;
import dao.implementation.ExamDaoImpl;

public class ExamController implements ModelDriven<Object> {

	private ExamDaoImpl edi;
	private Object model;
	private String id;
	
	public Object getModel() {
		return model;
	}
	
	/* End-point for GET all request */
	public HttpHeaders index() {
		edi = new ExamDaoImpl();
		model = edi.findAll();
		return new DefaultHttpHeaders("index").disableCaching();
	}
	
	/* End-point for GET request */
	public String show() {
		edi = new ExamDaoImpl();
		model = edi.findById(Integer.parseInt(this.id));
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
		edi = new ExamDaoImpl();
		edi.delete(Integer.parseInt(this.id));
		return "DELETE";
	}
	
	/* Getter and Setter for URL exam identifier */
	/* Example: http://localhost:8080/witch/exam/exam_id/ */
	public String getId() {
		return this.id;
	}
	
	public void setId(String id) {
		this.id = id;
	}
	
}
