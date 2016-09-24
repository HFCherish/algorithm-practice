<%-- 
    Document   : param
    Created on : 2011-11-9, 20:33:29
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>show</title>
    </head>
    <body>
        <jsp:useBean id="student2" scope="page" class="com.jsp.Student"/>
        <jsp:setProperty name="student2" property="name" param="name"/>
        <jsp:setProperty name="student2" property="age" param="age"/>
        <jsp:setProperty name="student2" property="major" param="major"/>
        姓名 <jsp:getProperty name="student2" property="name"/><br/>
        年龄 <jsp:getProperty name="student2" property="age"/><br/>
        专业 <jsp:getProperty name="student2" property="major"/>
    </body>
</html>
