<%-- 
    Document   : Problem_Add
    Created on : 2011-11-16, 0:46:56
    Author     : PL
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Problem_Add</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
        <form action="ProblemAdd" method="post">
            <p>title:<input type="text" name="title"></p>
            <p>timeLimit:<input type="text" name="timeLimit"></p>
            <p>memoryLimit:<input type="text" name="memoryLimit"></p>
            <p>description:</p> <textarea rows="10" cols="30" name="description" ></textarea>
            <p>input:</p> <textarea rows="10" cols="30" name="input" ></textarea>
            <p>output:</p> <textarea rows="10" cols="30" name="output" ></textarea>
            <p>sampleInput:</p> <textarea rows="10" cols="30" name="sampleInput" ></textarea>
            <p>sampleOut:</p> <textarea rows="10" cols="30" name="sampleOutput" ></textarea>
            <p>source:</p> <textarea rows="10" cols="30" name="source" ></textarea>
            <p>hint:</p> <textarea rows="10" cols="30" name="hint" ></textarea>
            <p>inputData:</p> <textarea rows="10" cols="30" name="inputData" ></textarea>
            <p>outputData:</p> <textarea rows="10" cols="30" name="outputData" ></textarea>
            <p><input type="reset" name="Reset" value="reset">
                <input type="submit" name="ProblemADD" value="Add Problem">
            </p>
        </form>
        </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
