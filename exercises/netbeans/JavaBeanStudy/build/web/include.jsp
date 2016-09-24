<%-- 
    Document   : include
    Created on : 2011-11-20, 15:55:46
    Author     : Administrator
--%>

<%@page contentType="text/html;charset=utf-8" pageEncoding="UTF-8"%>
        <%
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        response.setCharacterEncoding("utf-8");
        %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>include 示例</h1>
        <%@include file = "newhtml.html"%>
        <jsp:include page="login.jsp"></jsp:include>
    </body>
</html>
