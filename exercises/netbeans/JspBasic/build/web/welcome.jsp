<%-- 
    Document   : welcome
    Created on : 2011-11-5, 21:52:09
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>forward到的页面</title>
    </head>
    <body>
        <p>
            欢迎您！<%=request.getParameter("name")%>
        </p>
    </body>
</html>
