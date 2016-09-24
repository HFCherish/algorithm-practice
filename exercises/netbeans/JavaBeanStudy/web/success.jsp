<%-- 
    Document   : success
    Created on : 2011-11-15, 14:49:02
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
        <%String userName = (String) session.getAttribute("name");
        if(userName != null){%>
        <center>
             欢迎登陆：<%=userName%>
        </center>
        <%}%>
    </body>
</html>
