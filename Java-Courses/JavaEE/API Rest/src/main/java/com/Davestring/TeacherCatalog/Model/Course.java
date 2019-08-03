package com.Davestring.TeacherCatalog.Model;

import java.io.Serializable;
import javax.persistence.*;

/* The class needs a object Teacher because in the DB there
 * is a relation between teacher and course many to one.
 */

@Entity
@Table ( name = "Course" )
public class Course implements Serializable {
	
	private static final long serialVersionUID = 1L;
	@Id
	@Column ( name = "idCourse" )
	@GeneratedValue ( strategy = GenerationType.IDENTITY )
	private long idCourse;
	@Column ( name = "name" )
	private String name;
	@Column ( name = "themes" )
	private String themes;
	@Column ( name = "project" )
	private String project;
	@ManyToOne ( optional = true, fetch = FetchType.EAGER )
	@JoinColumn ( name = "idTeacher" )
	private Teacher teacher;
	
	public Course ( String name, String themes, String project ) {
		this.name = name;
		this.themes = themes;
		this.project = project;
	} // End constructor.
	
	public Course ( ) { }
	
	public long getIdCourse ( ) {
		return idCourse;
	} // End Getter.
	
	public void setIdCourse ( long idCourse ) {
		this.idCourse = idCourse;
	} // End Setter.
	
	public String getName ( ) {
		return name;
	} // End Getter.
	
	public void setName ( String name ) {
		this.name = name;
	}// End Setter.
	
	public String getThemes ( ) {
		return themes;
	} // End Getter.
	
	public void setThemes ( String themes ) {
		this.themes = themes;
	} // End Setter.
	
	public String getProject ( ) {
		return project;
	} // End Getter.
	
	public void setProject ( String project ) {
		this.project = project;
	} // End Setter.
	
	public Teacher getTeacher ( ) {
		return teacher;
	} // End Getter.
	
	public void setTeacher ( Teacher teacher ) {
		this.teacher = teacher;
	} // End Setter.
	
} // End class.
