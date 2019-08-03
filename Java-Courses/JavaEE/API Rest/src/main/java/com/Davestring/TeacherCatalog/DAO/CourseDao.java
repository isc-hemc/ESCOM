package com.Davestring.TeacherCatalog.DAO;

import com.Davestring.TeacherCatalog.Model.Teacher;
import com.Davestring.TeacherCatalog.Model.Course;
import java.util.List;

public interface CourseDao {
	
	void createCourse ( Course course );
	
	void updateCourse ( Course course );
	
	void deleteCourse ( Long idCourse );
	
	Course findById ( Long idCourse );
	
	Course findByName ( String name );
	
	List <Course> findAllCourses ( );
	
	List <Course> findByTeacherId ( Long idTeacher );
	
} // End interface.
