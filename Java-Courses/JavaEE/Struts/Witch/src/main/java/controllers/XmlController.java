package controllers;

import org.apache.struts2.rest.DefaultHttpHeaders;
import org.apache.struts2.rest.HttpHeaders;
import com.opensymphony.xwork2.ModelDriven;
import org.apache.commons.io.FileUtils;
import dao.implementation.QuizzDaoImpl;
import dao.implementation.ExamDaoImpl;
import java.io.IOException;
import java.util.ArrayList;
import utils.ExamXmlHelper;
import utils.XmlGenerator;
import models.Quizz;
import models.Exam;
import java.io.File;

public class XmlController implements ModelDriven<Object> {

	private Object model;
	private String id;
	
	public Object getModel() {
		return model;
	}

	/* End-point for GET all request */
	public HttpHeaders index() {
		model = "URL WHERE ALL XMLs ARE STORED";
		return new DefaultHttpHeaders("index").disableCaching();
	}
	
	/* End-point for GET request */
	@SuppressWarnings("deprecation")
	public String show() {
		QuizzDaoImpl qdi = new QuizzDaoImpl();
		ExamDaoImpl edi = new ExamDaoImpl();
		Exam exam = edi.findById(Integer.parseInt(id));
		ArrayList<Quizz> quizzes = qdi.findByExamId(Integer.parseInt(id));
		ExamXmlHelper xmlHelper = new ExamXmlHelper(exam, quizzes);
		XmlGenerator xml = new XmlGenerator();
		String path = xml.generate(xmlHelper);
		System.out.println(path);
		File file = new File(path);
		String content = "";
		try {
			content = FileUtils.readFileToString(file);
			model = content;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "GET";
	}
	
	/* Getter and Setter for URL user identifier */
	/* Example: http://localhost:8080/witch/xml/xml_id/ */
	public String getId() {
		return this.id;
	}
	
	public void setId(String id) {
		this.id = id;
	}

}
