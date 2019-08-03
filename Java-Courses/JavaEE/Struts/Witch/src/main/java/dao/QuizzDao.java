package dao;

import java.util.ArrayList;
import models.Quizz;

public interface QuizzDao {

	void create(Quizz quizz);
	
	void update(Quizz quizz);
	
	void delete(Integer id);
	
	Quizz findById(Integer id);
	
	ArrayList<Quizz> findByExamId(Integer id);
	
	ArrayList<Quizz> findAll();

}
