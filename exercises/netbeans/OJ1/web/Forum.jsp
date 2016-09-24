<%--
    Document   : index
    Created on : 2011-11-15, 12:55:14
    Author     : fookwood
--%>

<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="com.servlet.*" %>
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
        <h1> 这个是论坛</h1>
        
        <%
            DB db = new DB();
            String spaces = "&nbsp;&nbsp;&nbsp;&nbsp;";
            String sql = "SELECT * FROM posts WHERE topicid = 0";
            java.sql.ResultSet rs = db.query(sql);

            while( rs.next() ){
                %><font color="red"><%out.print(rs.getString("problem")+spaces);%></font><%
                %><a href="TopicID.jsp?topicid= <%=rs.getString("id")%> ">
                <%out.print( rs.getString( "content" ) );%>
                </a>

                <%
                out.print( "---"+CHA.getUsername( rs.getString("userid") ));
                out.print("<br/>");

                
            }
            db.close();
        %>

        
        <form method="post" action="takeposts.jsp">
            <table border="1">
                <input name="topicid" value="0" type="hidden"/>
                <tr>
                    <td>题目号</td>
                    <td>
                    <input type="text" name="problem" />
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
