<%-- 
    Document   : statement_vary
    Created on : 2011-11-4, 21:47:45
    Author     : Administrator
--%>

<%@page contentType="text/html;charset=UTF-8"%>
<%@page language="java" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>声明变量</title>
    </head>
    <body>
        <%i++;%>
        <p>您是第<%=i%>个访问本站的客户</p>
        <%!int i=0;%>                
    </body>
</html>
