<%-- 
    Document   : head
    Created on : 2011-11-20, 22:32:18
    Author     : pz
--%>

<%@page contentType="text/html;charset=utf-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
            <div id="header">
                <img src="image/logo.jpg"/>
            </div>
            <div id="menu">
                <span id="left">Welcome to ZZOJ.</span>
                <% String name = (String)session.getAttribute("username"); %>
                <span id="user"><%=name == null?"":name%></span>   <a href="logout.jsp">logout</a>
            </div>
            
    </body>
</html>
