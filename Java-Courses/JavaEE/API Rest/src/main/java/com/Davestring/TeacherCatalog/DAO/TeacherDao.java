package com.Davestring.TeacherCatalog.DAO;

import com.Davestring.TeacherCatalog.Model.Teacher;
import java.util.List;

public interface TeacherDao {
	
	void createTeacher ( Teacher teacher );
	
	void updateTeacher ( Teacher teacher );
	
	void deleteTeacher ( Long idTeacher );
	
	Teacher findById ( Long idTeacher );
	
	Teacher findByName ( String name );
	
	List <Teacher> findAllTeachers ( );
	
} // End interface.
