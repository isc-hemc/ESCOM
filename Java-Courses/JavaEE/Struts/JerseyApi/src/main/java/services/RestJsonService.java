package services;

import models.Book;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.HttpHeaders;

@Path("/book")
public class RestJsonService {
	
	@GET
	@Produces(MediaType.APPLICATION_JSON)
	public Response get(@Context HttpHeaders httpHeaders) {
		Book myBook = new Book(1, "Brave New World");
		return Response.ok(myBook).build();
	}

	@POST
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public Response post(@Context HttpHeaders httpHeaders, Book book) {
		System.out.println("ID: " + book.getId() + " Name: " + book.getName());
		return Response.ok(book).build();
	}
	
}
