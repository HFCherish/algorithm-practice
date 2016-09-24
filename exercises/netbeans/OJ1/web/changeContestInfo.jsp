<%-- 
    Document   : changeContestInfo
    Created on : 2011-11-12, 15:33:13
    Author     : ZXY
--%>

<%@page import="javabean.Contest"%>
<%@page pageEncoding="UTF-8"%>
<%@page contentType="text/html; charset=utf-8"%>

<% request.setCharacterEncoding("utf-8");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>比赛信息</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
        <h1>比赛信息</h1>
        <form action="contestPro" method="post">
            <b>
            <%
                Contest contest = new Contest(); 
                String name = contest.getContestName();
            %>
            比赛名称：
            <input type="text" name="contestName" value="<%=name == null ? "" : name%>" >
            <br><br>
            
            Password:
            <input type="text" name="password" value="<%=contest.getPassword() == null ? "" : contest.getPassword()%>" >Leave blank to make it Public
            
            
            <br><br>
            比赛开始时间: (sample)2011-11-11 00:00:00
            <br>
            <input type="text" name="startTime" value="<%= name == null ? "" : contest.getStartTime()%>" >
            
            <br><br>
            比赛持续时间: (sample)05:00:00
            <br>
            <input type="text" name="length" value="<%= name == null ? "" : contest.getLength()%>" >
            
            <br><br>
            比赛介绍：
            <br>
            <textarea name="introduce" value="<%= name == null ? "" : contest.getIntroduce()%>" 
                      style="width: 500px; height: 200px"><%= name == null ? "" : contest.getIntroduce()%></textarea>
            <br><br>     
            <input type="submit" name="submit" value="提交" >

        </b>
        </form>
                    </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
