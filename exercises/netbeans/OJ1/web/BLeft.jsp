<%-- 
    Document   : BLeft
    Created on : 2011-11-26, 14:44:53
    Author     : pz
--%>

<%@page contentType="text/html;charset=utf-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8");%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <div id="mainContent">
                <div id="sidebar">
                    <a <%if(request.getServletPath().equals("/Manage.jsp")){%>class="current"<%}%><%else{%>href="Manage.jsp" <%}%>>Home</a>
                    <a <%if(request.getServletPath().equals("/announcement_b.jsp")){%>class="current"<%}%><%else{%>href="announcement_b.jsp" <%}%>>Announcement</a>
                    <a <%if(request.getServletPath().equals("/Problem_Manage.jsp")){%>class="current"<%}%><%else{%>href="Problem_Manage.jsp" <%}%>>Problems</a>
                    <a <%if(request.getServletPath().equals("/Status_b.jsp")){%>class="current"<%}%><%else{%>href="Status_b.jsp" <%}%>>Status</a>
                    <a <%if(request.getServletPath().equals("/Forum.jsp")){%>class="current"<%}%><%else{%>href="Forum.jsp" <%}%>>Forum</a>
                </div>
                <div id="announcement">
                    <jsp:include page="Announcement.jsp" flush="true" />
                </div>
        </div>
    </body>
</html>
