package com.Davestring.TeacherCatalog.DAO.Implementation;

import com.Davestring.TeacherCatalog.DAO.AbstractSession;
import com.Davestring.TeacherCatalog.DAO.CourseDao;
import com.Davestring.TeacherCatalog.Model.Course;
import java.util.List;

public class CourseDaoImpl extends AbstractSession implements CourseDao {

	@Override
	public void createCourse ( Course course ) {
		getSession ( ).persist ( course );
	} // End method.

	@Override
	public void updateCourse ( Course course ) {
		getSession ( ).update ( course );
	} // End method.

	@Override
	public void deleteCourse ( Long idCourse ) {
		Course course = findById ( idCourse );
		if ( course != null ) {
			getSession ( ).delete ( course );
		} // End if.
	} // End method

	@Override
	public Course findById ( Long idCourse ) {
		return ( Course ) getSession ( ).get ( Course.class, idCourse );
	} // End method.
	
	@Override
	public Course findByName(String name) {
		return ( Course ) getSession ( ).createQuery ( 
				"FROM Course WHERE name = :name" )
				.setParameter ( "name", name ).uniqueResult ( );
	} // End method.
	
	@Override
	public List <Course> findAllCourses ( ) {
		return getSession ( ).createQuery ( "FROM Courses" ).list ( );
	} // End method.

	@Override
	public List <Course> findByTeacherId ( Long idTeacher ) {
		return getSession ( ).createQuery (
				"FROM Course c JOIN c.teacher t WHERE t.idTeacher = :idTeacher" )
				.setParameter ( "idTeacher", idTeacher ).list ( );
	} // End method.

} // End class.
