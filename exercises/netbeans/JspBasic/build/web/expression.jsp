<%-- 
    Document   : expression
    Created on : 2011-11-4, 17:54:47
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP表达式</title>
    </head>
    <body>
        <!-可以看到->
        <%--不可以看到--%>
        <%for(int i=1; i<=5; i++){%>
        <h<%=i%>>你好！</h>
        <%}%>
    </body>
</html>
