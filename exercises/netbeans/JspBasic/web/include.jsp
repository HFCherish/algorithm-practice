<%-- 
    Document   : include
    Created on : 2011-11-4, 22:49:23
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
        <h1>include示例</h1>
        <%--<h3>
            <%@include file="copyright.html" %>
        </h3>--%>
        <h3>
            <jsp:include page="copyright.html" flush="true"></jsp:include>
        </h3>
    </body>
</html>
