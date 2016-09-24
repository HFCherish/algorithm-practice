<%-- 
    Document   : Code
    Created on : 2011-11-20, 20:50:25
    Author     : ZXY
--%>

<%@page import="javabean.Format"%>
<%@page import="javabean.Check"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>View Code</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
         <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
        <%
            if( !Check.check_admin(String.valueOf(session.getAttribute("username"))) )
                out.println("您无权查看代码");
            String run_id = request.getParameter("run_id");
            String sql = "select code from code where id = " + run_id;
            DB db = new DB();
            ResultSet rst = db.query(sql);
            String code = "";
            while( rst.next() )
                code = Format.html(rst.getString("code"));
            db.close();
        %>
        <div style="font-family: monospace ">
            <%=code%>
        </div>
        </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
