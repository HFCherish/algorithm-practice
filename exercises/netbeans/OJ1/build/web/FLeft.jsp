<%-- 
    Document   : FLeft
    Created on : 2011-11-24, 22:03:45
    Author     : pz
--%>
<%@page contentType="text/html;charset=utf-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css"/>
    </head>
    <body>
        <div id="mainContent">
                <div id="sidebar">
                    <a <%if(request.getServletPath().equals("/FAQs.jsp")){%>class="current"<%}%><%else{%>href="FAQs.jsp" <%}%>>FAQs</a>
                    <a <%if(request.getServletPath().equals("/Problem.jsp")){%>class="current"<%}%><%else{%>href="Problem.jsp" <%}%>>Problems</a>
                    <a <%if(request.getServletPath().equals("/Status.jsp")){%>class="current"<%}%><%else{%>href="Status.jsp" <%}%>>Status</a>
                    <a <%if(request.getServletPath().equals("/Statistics.jsp")){%>class="current"<%}%><%else{%>href="Statistics.jsp" <%}%>>Statistics</a>
                    <a <%if(request.getServletPath().equals("/Ranklist.jsp")){%>class="current"<%}%><%else{%>href="Ranklist.jsp" <%}%>>Ranklist</a>
                    <a <%if(request.getServletPath().equals("/Forum.jsp")){%>class="current"<%}%><%else{%>href="Forum.jsp" <%}%>>Forum</a>
                </div>
                <div id="announcement">
                    <jsp:include page="Announcement.jsp" flush="true" />
                </div>
            </div>
    </body>
</html>