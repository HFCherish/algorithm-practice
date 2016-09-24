<%--
    Document   : takeposts
    Created on : 2011-11-15, 16:30:01
    Author     : fookwood
--%>

<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="com.servlet.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    <% request.setCharacterEncoding("UTF-8"); %>

    <%
        DB db = new DB();

        String sql1 = "INSERT INTO posts (topicid,problem,content,userid) VALUES ";
        String sql2 =  "("+request.getParameter("topicid")+",";
        sql2 += request.getParameter("problem")+",'";
        sql2 += request.getParameter("content")+"','";
        sql2 += "1')";
        //out.print(sql1+sql2);
        
        db.insert(sql1+sql2);
        //}catch(Exception e){}
        db.close();

       response.sendRedirect("Forum.jsp");
    %>


    </body>
</html>
