package models;

import javax.xml.bind.annotation.XmlRootElement;
import javax.persistence.*;

@Entity
@XmlRootElement
@Table(name="quizz")
public class Quizz {

	@Id
	@Column(name="id")
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private Integer id;
	@Column(name="quizz")
	private String quizz;
	@ManyToOne(optional=true, fetch=FetchType.EAGER)
	@JoinColumn(name="idExam")
	private Exam exam;
	
	public Quizz(Integer id, String quizz, Exam exam) {
		super();
		this.id = id;
		this.quizz = quizz;
		this.exam = exam;
	}

	public Quizz(Integer id, String quizz) {
		super();
		this.id = id;
		this.quizz = quizz;
	}

	public Quizz(String quizz, Exam exam) {
		super();
		this.quizz = quizz;
		this.exam = exam;
	}

	public Quizz(String quizz) {
		super();
		this.quizz = quizz;
	}

	public Quizz() {
		super();
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getQuizz() {
		return quizz;
	}

	public void setQuizz(String quizz) {
		this.quizz = quizz;
	}

	public Exam getExam() {
		return exam;
	}

	public void setExam(Exam exam) {
		this.exam = exam;
	}
	
}
