<%-- 
    Document   : Counter
    Created on : 2011-11-9, 21:07:25
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page language="java"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>计数</title>
    </head>
    <body>
        <jsp:useBean id="count" scope="application" class="com.jsp.counter"/>
        当前访问次数：<jsp:getProperty name="count" property="count"/>
    </body>
</html>
