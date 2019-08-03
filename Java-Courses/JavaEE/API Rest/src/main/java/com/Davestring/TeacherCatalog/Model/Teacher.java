package com.Davestring.TeacherCatalog.Model;

import java.io.Serializable;
import javax.persistence.*;
import java.util.Set;

/* The class needs a set of Courses and TeacherSocialMedia because in the DB there is
 * a relation between teacher and course one to many as well for TeacherSocialMedia.
 */

@Entity
@Table ( name = "Teacher" )
public class Teacher implements Serializable {
	
	private static final long serialVersionUID = 1L;
	@Id
	@Column ( name = "idTeacher" )
	@GeneratedValue ( strategy = GenerationType.IDENTITY )
	private long idTeacher;
	@Column ( name = "name" )
	private String name;
	@Column ( name = "avatar" )
	private String avatar;
	@OneToMany ( mappedBy = "teacher", cascade = CascadeType.ALL )
	private Set <Course> course;
	@OneToMany ( mappedBy = "teacher", cascade = CascadeType.ALL )
	private Set <TeacherSocialMedia> tsm;
	
	public Teacher ( String name, String avatar ) {
		this.name = name;
		this.avatar = avatar;
	} // End constructor.

	public Teacher ( ) { }

	public long getIdTeacher ( ) {
		return idTeacher;
	} // End Getter.
	
	public void setIdTeacher ( long idTeacher ) {
		this.idTeacher = idTeacher;
	} // End Setter.
	
	public String getName ( ) {
		return name;
	} // End Getter.
	
	public void setName ( String name ) {
		this.name = name;
	} // End Setter.
	
	public String getAvatar ( ) {
		return avatar;
	} // End Getter.
	
	public void setAvatar ( String avatar ) {
		this.avatar = avatar;
	} // End Setter.
	
	public Set<Course> getCourse ( ) {
		return course;
	} // End Getter.

	public void setCourse ( Set<Course> course ) {
		this.course = course;
	} // End Setter.

	public Set<TeacherSocialMedia> getTeacherSocialMedia ( ) {
		return tsm;
	} // End Getter.

	public void setTeacherSocialMedia ( Set<TeacherSocialMedia> tsm ) {
		this.tsm = tsm;
	} // End Setter.
	
} // End class.
