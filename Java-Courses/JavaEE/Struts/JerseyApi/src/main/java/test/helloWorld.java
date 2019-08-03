package test;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.PathParam;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.HttpHeaders;

@Path("/helloWorld")
public class helloWorld {
	
	@GET
	@Path("{name}")
	@Produces(MediaType.TEXT_PLAIN)
	public String hello(@Context HttpHeaders httpHeaders, @PathParam("name") String name) {
		return "Hello, " + name;
	}
}
