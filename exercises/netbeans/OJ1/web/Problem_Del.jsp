<%-- 
    Document   : Problem_Del
    Created on : 2011-11-20, 1:10:17
    Author     : PL
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8");%>
<%String id = request.getParameter("id");%>
<%String ConstID = request.getParameter("ConstID");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Prbolem<%=ConstID%></title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
        <form action="ProblemDel?id=<%=id%>" method="post">
            <p>
                Are you sure to delete problem <%=ConstID%> ?
            </p>
            <p>
                <input type="submit" name="ProblemDEL" value="Delete">
                <a href="ProblemID.jsp?id=<%=id%>&ConstID=<%=ConstID%>">Back</a>
            </p>
        </form>
    </div>
    <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
