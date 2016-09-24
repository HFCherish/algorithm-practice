<%-- 
    Document   : ProblemsID
    Created on : 2011-11-16, 0:04:19
    Author     : PL
--%>

<%@page import="javabean.DB"%>
<%@page import="java.sql.ResultSet"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%String id = request.getParameter("id");%>
<%String ConstID = request.getParameter("ConstID");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Prbolem<%=ConstID%></title>
    </head>
    <body>
<%
    String title = "",timeLimit= "", memoryLimit="", description="",input="",output="",sampleInput="",sampleOut="",source="",hint="",inputData="",outputData="";
    DB db = new DB(); 
    ResultSet rs = db.query("select * from problems where id = '" + id + "';");
    while(rs.next()){
        title = rs.getString("title");
        timeLimit = rs.getString("timeLimit");
        memoryLimit = rs.getString("memoryLimit");
        description = rs.getString("description");
        input = rs.getString("input");
        output = rs.getString("output");
        sampleInput = rs.getString("sampleInput");
        sampleOut = rs.getString("sampleOutput");
        source = rs.getString("source");
        hint = rs.getString ("hint");
        inputData = rs.getString("inputData");
        outputData = rs.getString("outputData");
    }
%>
<h3><center><%=title%></center></h3>
<hr>
    <center>
        <font color="green">Time Limit: </font> <%=timeLimit%> MS
        &nbsp;&nbsp;&nbsp;&nbsp;
        <font color="green">Memory Limit: </font> <%=memoryLimit%> KB
    </center>
<hr>

<BR><%=description%>
<H2 STYLE="color: #1A5CC8">Input</H2><%=input%>
<H2 STYLE="color: #1A5CC8">Output</H2><%=output%>
<H2 STYLE="color: #1A5CC8">Sample Input</H2><%=sampleInput%>
<H2 STYLE="color: #1A5CC8">Sample Output</H2><%=sampleOut%>
<% if(hint.length()!=0) out.println("<H2 STYLE=\"color: #1A5CC8\">HINT</H2>" + hint);%>
<br />
<br />
<a href="Problem_Modify.jsp?id=<%=id%>&ConstID=<%=ConstID%>">Modify</a>
<a href="Problem_Del.jsp?id=<%=id%>&ConstID=<%=ConstID%>">Delete</a>
    </body>
</html>
