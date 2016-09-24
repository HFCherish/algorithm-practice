<%-- 
    Document   : newjsptestError
    Created on : 2011-11-4, 22:37:40
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page language="java"%>
<%@page errorPage="error.jsp"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>test Page</title>
    </head>
    <body>
        <%!int[] a = {1,2,3};%>
        <%=a[3]%>
    </body>
</html>
