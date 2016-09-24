<%-- 
    Document   : Problem_Modify
    Created on : 2011-11-19, 13:58:14
    Author     : PL
--%>

<%@page import="javabean.DB"%>
<%@page import="java.sql.ResultSet"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
    String id = request.getParameter("id");
    String ConstID = request.getParameter("ConstID");
    String title = "",timeLimit= "", memoryLimit="",  description="",input="",output="",sampleInput="",sampleOut="",source="",hint="",inputData="",outputData="";
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
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
        <title>Problem<%=ConstID%> Modify</title>
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
        <form action="ProblemMod?id=<%=id%>" method="post">
            <p>title:<input type="text" name="title" value=<%=title%>></p>
            <p>timeLimit:<input type="text" name="timeLimit" value=<%=timeLimit%>></p>
            <p>memoryLimit:<input type="text" name="memoryLimit" value=<%=memoryLimit%>></p>
            <p>description:</p> <textarea rows="10" cols="30" name="description"><%=description%></textarea>
            <p>input:</p> <textarea rows="10" cols="30" name="input"><%=input%></textarea>
            <p>output:</p> <textarea rows="10" cols="30" name="output"><%=output%></textarea>
            <p>sampleInput:</p> <textarea rows="10" cols="30" name="sampleInput" ><%=sampleInput%></textarea>
            <p>sampleOutput:</p> <textarea rows="10" cols="30" name="sampleOutput" ><%=sampleOut%></textarea>
            <p>source:</p> <textarea rows="10" cols="30" name="source" ><%=source%></textarea>
            <p>hint:</p> <textarea rows="10" cols="30" name="hint" ><%=hint%></textarea>
            <p>inputData:</p> <textarea rows="10" cols="30" name="inputData"  ><%=inputData%></textarea>
            <p>outputData:</p> <textarea rows="10" cols="30" name="outputData" ><%=outputData%></textarea>
            <p>
                <input type="submit" name="ProblemMod" value="Modify Problem">
                <a href="ProblemID.jsp?id=<%=id%>&ConstID=<%=ConstID%>">Back</a>
            </p>
        </form>
            </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
