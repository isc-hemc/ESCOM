package services;

import dao.implementation.UserDaoImpl;
import javax.ws.rs.core.HttpHeaders;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Context;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import models.User;

@Path("/login")
public class LoginService {

	@POST
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public Response post(@Context HttpHeaders httpHeaders, User user) {
		UserDaoImpl udi = new UserDaoImpl();
		user = udi.findByUsernameAndPassword(user.getUsername(), user.getPassword());
		if(user != null) {
			return Response.ok(user).build();
		}
		return Response.status(400).build();
	}

}
