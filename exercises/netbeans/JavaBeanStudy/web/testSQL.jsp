<%-- 
    Document   : testSQL
    Created on : 2011-11-20, 15:24:25
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    java.sql.Connection conn = null;
    java.lang.String strConn;
    try{
        Class.forName("org.gjt.mm.mysql.Driver").newInstance();
        conn = java.sql.DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","123");
%>
    连接数据库成功！
            <%
                           }catch(java.sql.SQLException e){}
    finally{
        if(conn != null) conn.close();
    }
            %>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Hello World!</h1>
    </body>
</html>
