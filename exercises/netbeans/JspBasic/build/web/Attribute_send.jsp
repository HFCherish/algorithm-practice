<%-- 
    Document   : Attribute_send
    Created on : 2011-11-6, 22:01:59
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.ArrayList"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>参数传递</title>
    </head>
    <body>
        <%ArrayList ar = new ArrayList();
        String he = "hello";
        int m = 3;
        ar.add(he);
        ar.add(Integer.toString(m));
        request.setAttribute("name","peter");
        request.setAttribute("value", ar);%>
        <h3>Attribute传递参数示例</h3>
        <jsp:forward page="Attribute_recieve.jsp"></jsp:forward>
    </body>
</html>
