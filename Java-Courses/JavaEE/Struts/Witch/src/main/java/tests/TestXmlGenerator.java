package tests;

import dao.implementation.QuizzDaoImpl;
import dao.implementation.ExamDaoImpl;
import java.util.ArrayList;
import utils.ExamXmlHelper;
import utils.XmlGenerator;
import models.Quizz;
import models.Exam;

public class TestXmlGenerator {

	public static void main(String[] args) {
		QuizzDaoImpl qdi = new QuizzDaoImpl();
		ExamDaoImpl edi = new ExamDaoImpl();
		Exam exam = edi.findById(15);
		ArrayList<Quizz> quizzes = qdi.findByExamId(15);
		ExamXmlHelper xmlHelper = new ExamXmlHelper(exam, quizzes);
		XmlGenerator xml = new XmlGenerator();
		String path = xml.generate(xmlHelper);
		System.out.println(path);
	}

}
