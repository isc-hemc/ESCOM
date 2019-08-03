package tests;

import dao.implementation.UserDaoImpl;
import models.User;

public class TestUserDB {

	public static void main(String[] args) {
		User user = new User("chernandez", "mypass", "Carlos", "Hernandez", "student");
		UserDaoImpl userDaoImpl = new UserDaoImpl();
		userDaoImpl.create(user);
	}

}
