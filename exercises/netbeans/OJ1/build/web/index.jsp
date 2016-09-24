<%-- 
    Document   : index
    Created on : 2011-11-13, 14:42:24
    Author     : pz
--%>

<%@page import="javabean.Format"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="javabean.Contest"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title></title>
        <link rel="stylesheet" type="text/css" href="Css/indexLayout.css"/>
    </head>
    <body>
        <div id="container">
            <div id="header">
                <img src="image/logo.jpg"/>
            </div>
            <div id="mainContent">
                <div id="sidebar">
                    <a <%if(request.getServletPath().equals("/login.jsp")){%>class="current"<%}%><%else{%>href="login.jsp" <%}%>>比赛入口</a>
                    <a <%if(request.getServletPath().equals("/login.jsp")){%>class="current"<%}%><%else{%>href="login.jsp" <%}%>>管理入口</a>
                </div>
                <div id="content">
                    <% Contest contest = new Contest(); %>
                    <p id="title">最新消息：</p>
                    <hr />
                    <p id="time"><%=Format.YYMMDDHHMMSS(contest.getStartTime())%></p>
                    <p id="introduce"><%=contest.getIntroduce()%></p>
                </div>
            </div>
            <jsp:include page="foot.jsp" flush="true" />
        </div>
    </body>
</html>
