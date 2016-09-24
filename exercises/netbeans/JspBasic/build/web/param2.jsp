<%-- 
    Document   : param2
    Created on : 2011-11-5, 21:44:58
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>forward参数传递 Page</title>
    </head>
    <body>
        <p>
            向jsp：forward传递参数示例：
            <jsp:forward page="welcome.jsp">
                <jsp:param name="name" value="john"/>
            </jsp:forward>
        </p>
    </body>
</html>
