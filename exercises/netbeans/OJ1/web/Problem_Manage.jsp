<%@page import="javabean.DB"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<%@page  import="java.sql.*" %>
<%@page  import="java.lang.String" %>
<% request.setCharacterEncoding("utf-8");%>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link href="Css/global.css" rel="stylesheet" media="screen" type="text/css" />
<link rel="stylesheet" type="text/css" href="Css/layout.css" />
<title>Problems</title>
</head>

<%
DB db = new DB();
ResultSet rs = db.query("select * from problems;");
%>
<body >
    <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
    <div id="content">
    <div id="contest_pro">
    <table> 
        <thead>
          <tr>
            <td style="width: 100px">ID</td>
            <td style="width: 300px">Title</td>
          </tr>
        </thead>
<%
 char ConstID='A';
 while(rs.next()){
     int ProblemID = rs.getInt("id");
     String ProblemTitle = rs.getString("title");
     %>
        <tr>
            <td><%out.println(ConstID);%></td>
            <td><a href=<%out.println("\"ProblemID.jsp?id=" + ProblemID + "&ConstID=" + ConstID + "\""); %> ><%out.println(ProblemTitle);%></a></td>
        </tr>
      
    <%
     ConstID++;
 }
%>

</table>
 <a href="Problem_Add.jsp">
            <th width="439" scope="col">Add Problem</th></a>
&nbsp;&nbsp;
<a href="Problem_Del_All.jsp">
            <th width="439" scope="col">Delete All Problems</th></a>   
</div>
    </div>
<jsp:include page="foot.jsp" flush="true" />
</body>
</html>
