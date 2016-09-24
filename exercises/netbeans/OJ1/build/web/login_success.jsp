<%-- 
    Document   : login_success
    Created on : 2011-11-15, 10:29:40
    Author     : zhangjiyang
--%>

<%@page import="javabean.jmp"%>
<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8" import="java.sql.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>登录成功</title>
    </head>
    <body>

        <%!String username = new String();%>
        <%username = request.getParameter("username");%>

        <%
            String sql = null;
            ResultSet rs = null;
            try {
                sql = "select * from users where name='" + username + "'";
                DB db = new DB();
                rs = db.query(sql);
        %>

        <% while (rs.next()) {%>
        Your username:<%=rs.getString("name")%> <br/>
        Your password:<%=rs.getString("password")%> <br/>
        Your nickname:<%=rs.getString("nickname")%> <br/>
        Your safeproblem:<%=rs.getString("safe_problem")%> <br/>
        Your safeAnswer:<%=rs.getString("safe_answer")%> <br/>
        Your email:<%=rs.getString("email")%> <br/>
        <%}%>
        <%db.close();} catch (Exception e) {
                out.println(e.toString());
            }
        %>
        下面是使用session获取的用户名：
        <br/>
        <%  out.println(session.getAttribute("username"));
            jmp.to("FFrame.jsp", 0);
        %>
        <%--登出--%> 
        <a href="logout.jsp">登出 </a>

    </body>
</html>
