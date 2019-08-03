package com.Davestring.TeacherCatalog.Model;

/* The class needs a set of TeacherSocialMedia because in the DB there is
 * a relation between SocialMedia and TeacherSocialMedia one to many.
 */

import java.io.Serializable;
import javax.persistence.*;
import java.util.Set;

@Entity
@Table ( name = "Social_Media" )
public class SocialMedia implements Serializable {
	
	private static final long serialVersionUID = 1L;
	@Id
	@Column ( name = "idSocialMedia" )
	@GeneratedValue ( strategy = GenerationType.IDENTITY )
	private long idSocialMedia;
	@Column ( name = "name" )
	private String name;
	@Column ( name = "icon" )
	private String icon;
	@OneToMany ( mappedBy = "socialMedia", cascade = CascadeType.ALL )
	private Set<TeacherSocialMedia> tsm;
	
	public SocialMedia ( String name, String icon ) {
		this.name = name;
		this.icon = icon;
	} // End constructor.
	
	public SocialMedia ( ) { } 

	public long getIdSocialMedia ( ) {
		return idSocialMedia;
	} // End Getter.
	
	public void setIdSocialMedia ( long idSocialMedia ) {
		this.idSocialMedia = idSocialMedia;
	} // End Setter.
	
	public String getName ( ) {
		return name;
	} // End Getter.
	
	public void setName ( String name ) {
		this.name = name;
	} // End Setter.
	
	public String getIcon ( ) {
		return icon;
	} // End Getter.
	
	public void setIcon ( String icon ) {
		this.icon = icon;
	} // End Setter.
	
	public Set <TeacherSocialMedia> getTsm ( ) {
		return tsm;
	} // End Getter.

	public void setTeacherSocialMedia ( Set<TeacherSocialMedia> tsm ) {
		this.tsm = tsm;
	} // End Setter.
	
} // End class.
