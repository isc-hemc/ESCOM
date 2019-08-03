package utils;

import java.util.ArrayList;
import java.util.List;
import models.Quizz;
import models.Exam;

public class ExamXmlHelper {
	
	private Integer id;
	private String name;
	private String date;
	private String feedback;
	private List<Quizz> quizzes;
	
	public ExamXmlHelper(Integer id, String name, String date, String feedback, List<Quizz> quizzes) {
		super();
		this.id = id;
		this.name = name;
		this.date = date;
		this.feedback = feedback;
		this.quizzes = quizzes;
	}

	public ExamXmlHelper(Integer id, String name, String date, String feedback) {
		super();
		this.id = id;
		this.name = name;
		this.date = date;
		this.feedback = feedback;
	}
	
	public ExamXmlHelper(Exam exam, ArrayList<Quizz> quizzes) {
		this.id = exam.getId();
		this.name = exam.getName();
		this.date = exam.getDate();
		this.feedback = exam.getFeedback();
		this.quizzes = (List<Quizz>) quizzes;
	}

	public ExamXmlHelper() {
		super();
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public String getFeedback() {
		return feedback;
	}

	public void setFeedback(String feedback) {
		this.feedback = feedback;
	}

	public List<Quizz> getQuizzes() {
		return quizzes;
	}

	public void setQuizzes(List<Quizz> quizzes) {
		this.quizzes = quizzes;
	}
	
}
