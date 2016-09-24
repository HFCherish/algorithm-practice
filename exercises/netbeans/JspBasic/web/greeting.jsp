<%-- 
    Document   : greeting
    Created on : 2011-11-9, 16:21:47
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page language="java"%>
<%@page import="java.util.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>问好</title>
    </head>
    <body>
        <%Date today = new Date();
        int h = today.getHours();
        if(h<12) response.sendRedirect("morning.jsp");
               else response.sendRedirect("afternoon.jsp");%>
    </body>
</html>
