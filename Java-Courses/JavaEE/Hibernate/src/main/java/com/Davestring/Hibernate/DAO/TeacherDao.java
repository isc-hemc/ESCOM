package com.Davestring.Hibernate.DAO;

// DAO: Data Access Object.

import com.Davestring.Hibernate.Model.Teacher;
import java.util.List;

public interface TeacherDao {
	
	void createTeacher ( Teacher teacher );
	
	void updateTeacher ( Teacher teacher );
	
	void deleteTeacher ( long idTeacher );
	
	Teacher findTeacherById ( long idTeacher );
	
	Teacher findTeacherByName ( String name );
	
	List<Teacher> findAllTeachers ( );
	
} // End interface.
