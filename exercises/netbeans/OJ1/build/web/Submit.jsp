<%-- 
    Document   : Submit
    Created on : 2011-11-22, 13:45:56
    Author     : PL
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%String id = request.getParameter("id");%>
<%String ConstID = request.getParameter("ConstID");%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Submit</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content" style="margin-left: 300px !important;">
        <form action="Process.jsp" method="post">
            <p>Problem ID:<%=ConstID%></p>
            <input type="hidden" name="ProblemID" value="<%=id%>">
            <p>Language:
                <select name="Language">
                    <option value="0" selected="selected">C</option>
                    <option value="1">C++</option>
                    <option value="2">Java</option>
                </select>
            </p>
            <p>
                Code:
            </p>
            <textarea rows="20" cols="55" name="Code" ></textarea>
            <p>
                <input type="submit" name="Submit" value="Submit">
                <input type="reset" name="Reset" value="Reset">
            </p>
        </form>
            </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
