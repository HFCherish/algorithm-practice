<%-- 
    Document   : param1
    Created on : 2011-11-5, 20:42:43
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>参数</title>
    </head>
    <body>
        加载文件效果：
        <jsp:include page="add.jsp">
            <jsp:param name="start" value="0"></jsp:param>
            <jsp:param name="end" value="100"/>
        </jsp:include>
    </body>
</html>
