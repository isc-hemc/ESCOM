<%@taglib  uri="/struts-tags" prefix="s" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <s:form action="login" method="post">
            <s:textfield name="username" label="Username" />
            <s:password name="password" label="Password" />
            <s:submit value="Login" />
        </s:form>
    </body>
</html>
