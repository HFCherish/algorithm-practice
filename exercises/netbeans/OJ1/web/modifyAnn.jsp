<%-- 
    Document   : modifyAnn
    Created on : 2011-11-16, 20:55:52
    Author     : ZXY
--%>

<%@page import="javabean.Announce"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
        <%
            int ind = Integer.parseInt(request.getParameter("id"));
            Announce ann = new Announce();
            String val = ann.getMsg(ind);
        %>
        <form action="modifyAnn?id=<%=ind%>" method="post">
            <input type="text" name="msg" value="<%=val%>" >
            <input type="submit" value="确定" >
        </form>
            </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
