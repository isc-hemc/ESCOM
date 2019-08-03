package models;

import javax.xml.bind.annotation.XmlRootElement;
import javax.persistence.*;

@Entity
@XmlRootElement
@Table(name="exam")
public class Exam {
	
	@Id
	@Column(name="id")
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private Integer id;
	@Column(name="name")
	private String name;
	@Column(name="date")
	private String date;
	@Column(name="feedback")
	private String feedback;

	public Exam(Integer id, String name, String date, String feedback) {
		super();
		this.id = id;
		this.name = name;
		this.date = date;
		this.feedback = feedback;
	}

	public Exam(String name, String date, String feedback) {
		super();
		this.name = name;
		this.date = date;
		this.feedback = feedback;
	}

	public Exam(String name, String feedback) {
		super();
		this.name = name;
		this.feedback = feedback;
	}

	public Exam() {
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
	
}
