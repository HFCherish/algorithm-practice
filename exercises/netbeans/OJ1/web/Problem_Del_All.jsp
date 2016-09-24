<%-- 
    Document   : Problem_Del_All
    Created on : 2011-11-20, 2:53:18
    Author     : PL
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Delete All Problems</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
        <form action="ProblemDelAll" method="post">
            <p>
                Are you sure to delete ALL problems?
            </p>
            <p>
                <input type="submit" name="ProblemDELALL" value="Delete ALL">
                <a href="Problem_Manage.jsp">Back</a>
            </p>
        </form>
        </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
