package utils;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class HandleQuizzRequest {
	
	private Integer idExam;
	private String quizz;
	
	public HandleQuizzRequest(Integer idExam, String quizz) {
		super();
		this.idExam = idExam;
		this.quizz = quizz;
	}

	public HandleQuizzRequest() {
		super();
	}

	public Integer getIdExam() {
		return idExam;
	}

	public void setIdExam(Integer idExam) {
		this.idExam = idExam;
	}

	public String getQuizz() {
		return quizz;
	}

	public void setQuizz(String quizz) {
		this.quizz = quizz;
	}
	
}
