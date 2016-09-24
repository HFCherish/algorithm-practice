<%-- 
    Document   : BStatus
    Created on : 2011-11-17, 22:57:06
    Author     : pz
--%>

<%@page import="domain.Status"%>
<%@page import="java.util.List"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
            <table>
                <thead>
                    <tr>
                        <th>Run ID</th>
                        <th>TeamName</th>
                        <th>ProblemID</th>
                        <th>Result</th>
                        <th>Language</th>
                        <th>Run Time</th>
                        <th>Memory</th>
                        <th>Code Length</th>
                        <th>Submit Time</th>
                    </tr>
                </thead>
                <tbody>    
                    <tr><td>bstatus</td></tr>
                    <%
                        List list = (List)request.getAttribute("allStatusList");
                        Status status = new Status();
                        for(int i=0; i<list.size(); i++)
                                                   {
                        %>
                        <tr>
                            <td><a href=""><%=status.getId()%>BSTATUS</a></td> 
                            <td><%=status.getUser_name()%></td>
                            <td><a href=""><%=status.getProblem_id()%></a></td>
                            <td><%=status.getResult()%></td>
                            <td><%=status.getLanguage()%></td>
                            <td><%=status.getRun_time()%>MS</td>
                            <td><%=status.getRun_memory()%>KB</td>
                            <td><%=status.getCode_length()%>Byte</td>
                            <td><%=status.getSubmit_time()%></td>
                        </tr>
                        <%}%>
                </tbody>
            </table>
        </div>
                <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
