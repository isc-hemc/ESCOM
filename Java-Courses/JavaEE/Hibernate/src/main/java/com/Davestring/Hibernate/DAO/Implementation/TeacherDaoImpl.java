package com.Davestring.Hibernate.DAO.Implementation;

import com.Davestring.Hibernate.DAO.TeacherDao;
import com.Davestring.Hibernate.Model.Teacher;
import com.Davestring.Hibernate.InitSession;
import java.util.List;

public class TeacherDaoImpl extends InitSession implements TeacherDao {

	private InitSession initSession;
	
	public TeacherDaoImpl ( ) {
		initSession = new InitSession ( );
	} // End constructor.
	
	public void createTeacher ( Teacher teacher ) {
		initSession.getSession ( ).persist ( teacher );
		initSession.getSession ( ).getTransaction ( ).commit ( );
	} // End method.
	
	public void updateTeacher ( Teacher teacher ) {
		initSession.getSession ( ).update ( teacher );
		initSession.getSession ( ).getTransaction ( ).commit ( );
	} // End method.

	public void deleteTeacher ( long idTeacher ) {
		initSession.getSession ( ).delete ( initSession.getSession ( ).get ( Teacher.class, idTeacher ) );
		initSession.getSession ( ).getTransaction ( ).commit ( );
	} // End method.

	public Teacher findTeacherById ( long idTeacher ) {
		return initSession.getSession ( ).load ( Teacher.class, idTeacher );
	} // End method.

	public Teacher findTeacherByName ( String name ) {
		return ( Teacher ) initSession.getSession ( ).createQuery ( "FROM Teacher WHERE name LIKE '" + name + "'" ).getSingleResult ( );
	} // End method.

	public List<Teacher> findAllTeachers ( ) {
		return initSession.getSession ( ).createQuery ( "FROM Teacher" ).getResultList ( );
	} // End method.

} // End class.
