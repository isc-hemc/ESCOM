package dao;

import java.util.ArrayList;
import models.Exam;

public interface ExamDao {
	
	void create(Exam exam);
	
	void update(Exam exam);
	
	void delete(Integer id);
	
	Exam findById(Integer id);
	
	Exam findByName(String name);
	
	Exam findByDate(String date);
	
	ArrayList<Exam> findAll();

}
