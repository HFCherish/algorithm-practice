<%-- 
    Document   : Problems
    Created on : 2011-11-21, 20:58:09
    Author     : PL
--%>
<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page  import="java.sql.*" %>
<%@page  import="java.lang.String" %>
<% request.setCharacterEncoding("utf-8");%>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Problems</title>
<link rel="stylesheet" type="text/css" href="Css/layout.css" />
</head>
<%
DB db = new DB();
ResultSet rs = db.query("select * from problems;");
%>
<body >
    <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
<table width="600" border="1" align="center"> 
  <tr bgcolor="#0000CC">
    <font color="#FFFFFF">
    <th width="34" scope="col">ID</th>
    <th width="439" scope="col">Title</th>
    <th width="48" scope="col">AC</th>
    </font>
  </tr>
</table>
<%
 char ConstID='A';
 while(rs.next()){
     int ProblemID = rs.getInt("id");
     String ProblemTitle = rs.getString("title");
     %>
     <table width="600" border="1" align="center"> 
        <tr bgcolor="#00FFFF">
        <font color = "black">
            <th width="34" scope="col"><%out.println(ConstID);%></th>
            <th width="439" scope="col"><a href="ProblemDetail.jsp?id=<%=ProblemID%>&ConstID=<%=ConstID%>"><%out.println(ProblemTitle);%></a></th>
            <th width="48" scope="col"><%out.println(" ");%></th>
        </font>
        </tr>
      </table>
    <%
     ConstID++;
 }
%>
</div>
        <jsp:include page="foot.jsp" flush="true" />
</body>
</html>
