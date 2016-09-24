
<%@page import="javabean.Format"%>
<%@page import="javabean.TypeMap"%>
<%@page import="javabean.Contest"%>
<%@page pageEncoding="utf-8"%>
<%@page contentType="text/html; charset=utf-8"%>
<%@page import="show.showContest" %>
<% request.setCharacterEncoding("utf-8");%>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <link href="Css/global.css" rel="stylesheet" media="screen" type="text/css">
        <title>Home</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
         <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content" style="text-align: center;"> 
            <h2>后台管理系统</h2>
        <div>
            <div>
                <% out.print(showContest.showNow("1","changeContestInfo.jsp")); %>
            </div>
            <div>
                <%Contest contest = new Contest();
                  if( contest.getContestName() != null ) {%>
                <table style="margin: 0 auto;">
                    <tr>
                        <td>比赛名称：</td>
                        <td><%=contest.getContestName()%></td>
                    </tr>
                    <tr>
                        <td>比赛权限：</td>
                        <td><%=TypeMap.Right(contest.isRight())%>
                        <%
                            if( contest.isRight() == false ) {
                        %></td>
                    </tr>
                    <tr>
                        <td>密码:</td>
                        <td><%=contest.getPassword()%></td><%}%>
                    </tr>
                    <tr>
                        <td>比赛开始时间：</td>
                        <td><%=Format.YYMMDDHHMMSS(contest.getStartTime())%></td>
                    </tr>
                    <tr>
                        <td>比赛持续时间：</td>
                        <td><%=contest.getLength().toString()%></td>
                    </tr>
                    <tr>
                        <td>比赛介绍：</td>
                        <td><%=contest.getIntroduce()%></td>
                    </tr>
                    <tr>
                        <td><a href="deletContest">删除本场比赛</a></td>
                        <td><a href="changeContestInfo.jsp">修改比赛信息</a></td>
                    </tr>

                </table>
                    <%}%>
            </div>
        </div>
        </div>
            <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>

