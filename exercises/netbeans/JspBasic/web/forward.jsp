<%-- 
    Document   : forward
    Created on : 2011-11-4, 22:58:02
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>forward Page</title>
    </head>
    <body>
        <p>
            <% double i = Math.random();
            if(i>0.5){%>
            <jsp:forward page="catalog1.html"></jsp:forward>
            <%} 
                       else{%>
                       <jsp:forward page="catalog2.html"></jsp:forward>
                       <%}%>
        </p>
    </body>
</html>
