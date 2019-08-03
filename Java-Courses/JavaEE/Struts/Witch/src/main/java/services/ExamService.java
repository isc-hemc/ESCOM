package services;

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
import models.Exam;
import utils.DateGenerator;

@Path("/exam")
public class ExamService {
	
	@POST
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public Response post(@Context HttpHeaders httpHeaders, Exam exam) {
		ExamDaoImpl edi = new ExamDaoImpl();
		DateGenerator dg = new DateGenerator();
		exam.setDate(dg.getCurrentDate());
		edi.create(exam);
		exam = edi.findByDate(exam.getDate());
		return Response.ok(exam).build();
	}
	
	@PUT
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public Response put(@Context HttpHeaders httpHeaders, Exam exam) {
		ExamDaoImpl edi = new ExamDaoImpl();
		edi.update(exam);
		return Response.ok(exam).build();
	}

}
