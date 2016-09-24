<%-- 
    Document   : Problem
    Created on : 2011-11-20, 21:44:16
    Author     : ZXY
--%>

<%@page import="java.util.Date"%>
<%@page import="java.text.SimpleDateFormat"%>
<%@page import="javabean.Format"%>
<%@page import="javabean.Contest"%>
<%@page import="javabean.Check"%>
<%@page import="show.showProblemSet"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link href="Css/global.css" rel="stylesheet" media="screen" type="text/css">
        <title>Problem Set</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
         <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
        <%
            if( session.getAttribute("username") == null || 
                Check.check_user( String.valueOf(session.getAttribute("username")) ) == false )
                out.println("请登陆");
            else
                out.println("Welcome ! " + String.valueOf(session.getAttribute("username")));
        %>
        
        <div id="contest">
            <%
                Contest contest = new Contest();
            %>
            <h1><%=contest.getContestName()%></h1>
            <div class="time">
                Start Time : <%=Format.YYMMDDHHMMSS(contest.getStartTime())%>
                &nbsp;&nbsp;&nbsp;&nbsp;
                End Time : <%=Format.YYMMDDHHMMSS(contest.getEndTime())%>
                <br>
                Current System Time : <%=Format.YYMMDDHHMMSS(new Date())%>
                <br>
                Contest Status : <span style="color:red"> <%=contest.Status()%> </span>
            </div>
        </div>
        <br>
        <div id ="list">
        <table>
            <thead>
                <tr>
                    <td style="width: 50px" >&nbsp;Solved&nbsp;</td>
                    <td style="width: 50px" >&nbsp;&nbsp;Pro.ID&nbsp;&nbsp;</td>
                    <td style="width: 400px" >Problem Title</td>
                    <td style="width: 100px" >&nbsp;Ratio(AC/All)&nbsp;</td>
                </tr>
            </thead>
            <tbody>
                <%=showProblemSet.showContestProblem(session)%>
            </tbody>
        </table>
        </div>
    </div>
       <jsp:include page="foot.jsp" flush="true" />     
    </body>
</html>
