package tests;

import dao.implementation.ExamDaoImpl;
import java.util.ArrayList;
import models.Exam;

public class TestExamDB {
	
	public static void main(String[] args) {
		Exam exam = new Exam("React Basics", "2019-06-12", "");
		ExamDaoImpl examDaoImpl = new ExamDaoImpl();
		examDaoImpl.create(exam);
		ArrayList<Exam> exams = examDaoImpl.findAll();
		for(Exam e : exams) {
			System.out.println(e);
		}
	}

}
