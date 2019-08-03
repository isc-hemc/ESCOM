package com.Davestring.Hibernate.Model;

import java.io.Serializable;
import javax.persistence.*;

/* The class needs a object Teacher and SocialMedia because in the DB there is
 * a relation between teacher and course many to one as well for SocialMedia.
 */

@Entity
@Table ( name = "Teacher_Social_Media" )
public class TeacherSocialMedia implements Serializable {
	
	private static final long serialVersionUID = 1L;
	@Id
	@Column ( name = "idTeacherSocialMedia" )
	@GeneratedValue ( strategy = GenerationType.IDENTITY )
	private long idTeacherSocialMedia;
	@ManyToOne ( fetch = FetchType.EAGER )
	@JoinColumn ( name = "idSocialMedia" )
	private SocialMedia socialMedia;
	@ManyToOne ( fetch = FetchType.EAGER )
	@JoinColumn ( name = "idTeacher" )
	private Teacher teacher;
	@Column ( name = "nickname" )
	private String nickname;
	
	public TeacherSocialMedia ( SocialMedia socialMedia, Teacher teacher, String nickname ) {
		this.socialMedia = socialMedia;
		this.teacher = teacher;
		this.nickname = nickname;
	} // End constructor.
	
	public TeacherSocialMedia ( ) { }

	public long getIdTeacherSocialMedia ( ) {
		return idTeacherSocialMedia;
	} // End Getter.
	
	public void setIdTeacherSocialMedia ( long idTeacherSocialMedia ) {
		this.idTeacherSocialMedia = idTeacherSocialMedia;
	} // End Setter.
	
	public SocialMedia getSocialMedia ( ) {
		return socialMedia;
	} // End Getter.
	
	public void setSocialMedia ( SocialMedia socialMedia ) {
		this.socialMedia = socialMedia;
	} // End Setter.
	
	public Teacher getTeacher ( ) {
		return teacher;
	} // End Getter.
	
	public void setTeacher ( Teacher teacher ) {
		this.teacher = teacher;
	} // End Setter.
	
	public String getNickname ( ) {
		return nickname;
	} // End Getter.
	
	public void setNickname ( String nickname ) {
		this.nickname = nickname;
	} // End Setter.
	
} // End class.
