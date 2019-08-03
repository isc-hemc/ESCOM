package com.Davestring.TeacherCatalog.DAO.Implementation;

import com.Davestring.TeacherCatalog.Model.TeacherSocialMedia;
import com.Davestring.TeacherCatalog.DAO.AbstractSession;
import com.Davestring.TeacherCatalog.DAO.TeacherDao;
import com.Davestring.TeacherCatalog.Model.Teacher;
import java.util.Iterator;
import java.util.List;

public class TeacherDaoImpl extends AbstractSession implements TeacherDao {
	
	public void createTeacher ( Teacher teacher ) {
		getSession ( ).persist ( teacher );
	} // End method.
	
	public void updateTeacher ( Teacher teacher ) {
		getSession ( ).update ( teacher );
	} // End method.

	public void deleteTeacher ( Long idTeacher ) {
		Teacher teacher = findById ( idTeacher );
		if ( teacher != null ) {	
			Iterator <TeacherSocialMedia> i = teacher.getTeacherSocialMedia ( ).iterator ( );
			while ( i.hasNext ( ) ) {
				TeacherSocialMedia tsm = i.next ( );
				i.remove ( );
				getSession ( ).delete ( tsm );
			} // End while.
			teacher.getTeacherSocialMedia ( ).clear ( );
			getSession ( ).delete ( teacher );
		} // End if.
	} // End method.

	public Teacher findById ( Long idTeacher ) {
		return ( Teacher ) getSession ( ).get ( Teacher.class, idTeacher );
	} // End method.

	public Teacher findByName ( String name ) {
		return ( Teacher ) getSession ( ).createQuery ( 
					"FROM Teacher WHERE name = :name" )
					.setParameter ( "name", name ).uniqueResult ( );
	} // End method.

	public List<Teacher> findAllTeachers ( ) {
		return getSession ( ).createQuery ( "FROM Teacher" ).list ( );
	} // End method.

} // End class.
