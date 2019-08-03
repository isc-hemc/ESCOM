package models;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class Book {
	
	Integer id;
	String name;
	
	public Book(Integer id, String name) {
		super();
		this.id = id;
		this.name = name;
	}

	public Book() {
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

}
