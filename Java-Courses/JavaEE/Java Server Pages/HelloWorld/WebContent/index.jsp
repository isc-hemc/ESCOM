<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title> First JSP File! </title>
</head>
<body>
	<h1> Hello World! </h1>
	<form action = "LoginServlet" method = "post">
		Name: <input type = "text" name = "Name">
		<br>
		<br>
		Password: <input type = "password" name = "Password">
		<br>
		<br>
		<input type = "submit" value = "Login">
	</form>
</body>
</html>