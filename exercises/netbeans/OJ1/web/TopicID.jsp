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
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
    <% request.setCharacterEncoding("UTF-8"); %>

    <%
        DB db = new DB();
        String spaces = "&nbsp;&nbsp;&nbsp;&nbsp;";
        String sql = "SELECT * FROM posts WHERE id = "+request.getParameter("topicid");
        java.sql.ResultSet rs = db.query(sql);

        while( rs.next() ){

            out.print( rs.getString( "content" ) );

            out.print( "---"+CHA.getUsername( rs.getString("userid") ));
            out.print("<br/>");

            DB haha = new DB();
            sql = "SELECT * FROM posts WHERE topicid = " + rs.getString("id");
            java.sql.ResultSet rst = haha.query(sql);
            while( rst.next() ){
                out.print(spaces);
                out.print( rst.getString( "content" ) );
                out.print( "---"+CHA.getUsername( rst.getString("userid") ));
                %><br/><%
            }
        }



    %>
        <form method="post" action="takeposts.jsp">
            <table border="1">
                <input name="topicid" value="<%=request.getParameter("topicid")%>" type="hidden"/>
                <tr>
                    <td>题目号</td>
                    <td>
                    <input type="hidden" value="1" name="problem" />
                    </td>
                </tr>
                <br/>
                <tr>
                    <td> 内容 </td>
                    <td>
                        <input type="text" name="content" />
                    </td>
                </tr>
            </table>
            <input type="submit" value="提问" />
        </form>
</div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
