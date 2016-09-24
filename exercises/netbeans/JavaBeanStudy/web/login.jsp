<%-- 
    Document   : login
    Created on : 2011-11-15, 14:55:02
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action ="LoginServlet" method ="post">
            用户名称：<input type="text" name="name"><br/>
            用户密码：<input type="password" name="password"><br/>
            <input type="submit" value="登陆">
            <input type="reset" value="重写">
        </form>
    </body>
</html>
