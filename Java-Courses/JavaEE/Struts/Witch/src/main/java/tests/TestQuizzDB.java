package tests;

import dao.implementation.QuizzDaoImpl;
import dao.implementation.ExamDaoImpl;
import models.Quizz;
import models.Exam;

public class TestQuizzDB {

	public static void main(String[] args) {
		ExamDaoImpl examDaoImpl = new ExamDaoImpl();
		Exam exam = examDaoImpl.findById(10);
		Quizz quizz1 = new Quizz("{ \"name\": \"quizz 1\", \"quizz\": \"description 1\", \"type\": \"TrueFalse\" }", exam);
		Quizz quizz2 = new Quizz("{ \"name\": \"quizz 2\", \"quizz\": \"description 2\", \"type\": \"Multichoice\" }", exam);
		QuizzDaoImpl quizzDaoImpl = new QuizzDaoImpl();
		quizzDaoImpl.create(quizz1);
		quizzDaoImpl = new QuizzDaoImpl();
		quizzDaoImpl.create(quizz2);
	}

}
