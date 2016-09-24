<%-- 
    Document   : getParam
    Created on : 2011-11-6, 20:35:39
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%--<p>
            你好，
            <%String name = request.getParameter("username");
            out.println(name);%>
        </p>
        <p>
            你喜欢吃的水果有：
            <%String[] paramValues = request.getParameterValues("checkbox1");
            for(int i=0; i<paramValues.length; i++)
                out.println(paramValues[i]+" ");%>
        </p>--%>
        你好，
        <%!String name;%>
        <%name = request.getParameter("username");
        String stars = new String("你喜欢吃的水果有：");
        String[] paramValues = request.getParameterValues("checkbox1");
            for(int i=0; i<paramValues.length; i++)  stars += paramValues[i] + " ";%>
        <%=name%>
        <br>
        <%=stars%>
    </body>
</html>
