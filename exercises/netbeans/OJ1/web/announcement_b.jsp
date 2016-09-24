<%-- 
    Document   : Announcement_b
    Created on : 2011-11-12, 19:16:32
    Author     : ZXY
--%>

<%@page import="show.showAnnounce" %>
<%@page import="javabean.Contest"%>
<%@page pageEncoding="UTF-8"%>
<%@page contentType="text/html; charset=utf-8"%>

<% request.setCharacterEncoding("utf-8");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>公告</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
        <link rel="stylesheet" type="text/css" href="Css/global.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content" style="text-align: center;">
        <h1>公告</h1>
        <%@include file="addAnn.jsp"%>
        <form action="announce" method="post"style="margin-bottom: 20px;">
        <b>
            <div id="list">
            <table border="1" rules="all" style="margin: 0 auto;">
                <%=showAnnounce.showMsg()%>
            </table>
            </div>
        </b>
        </form>
        <div>
            <a href="deletAllAnn" >全部删除</a>
        </div>
            </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
