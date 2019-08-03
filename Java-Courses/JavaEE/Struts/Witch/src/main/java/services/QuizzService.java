package services;

import dao.implementation.QuizzDaoImpl;
import dao.implementation.ExamDaoImpl;
import javax.ws.rs.core.HttpHeaders;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Context;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import models.Quizz;
import models.Exam;
import utils.HandleQuizzRequest;


@Path("/quizz")
public class QuizzService {
	
	@POST
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public Response post(@Context HttpHeaders httpHeaders, HandleQuizzRequest quizzRequest) {
		QuizzDaoImpl qdi = new QuizzDaoImpl();
		ExamDaoImpl edi = new ExamDaoImpl();
		Exam exam = edi.findById(quizzRequest.getIdExam());
		System.out.println(exam.getName());
		Quizz quizz = new Quizz(quizzRequest.getQuizz());
		quizz.setExam(exam);
		qdi.create(quizz);
		return Response.ok(quizz).build();
	}
	
	@PUT
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public Response put(@Context HttpHeaders httpHeaders, Quizz quizz) {
		QuizzDaoImpl qdi = new QuizzDaoImpl();
		Quizz quizzToUpdate = qdi.findById(quizz.getId());
		quizzToUpdate.setQuizz(quizz.getQuizz());
		qdi.update(quizzToUpdate);
		return Response.ok(quizz).build();
	}

}
