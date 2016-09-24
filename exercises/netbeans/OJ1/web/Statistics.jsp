<%-- 
    Document   : Statistics
    Created on : 2011-11-18, 13:59:46
    Autdor     : ZXY
--%>
<%@page import="show.showStatistics"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link href="Css/global.css" rel="stylesheet" media="screen" type="text/css">
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
        <title>Statistics</title>
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
        <h1>Statistics</h1>
        <div id="list">
        <table>
            <thead>
                <tr>
                    <td style="width: 70px" >Pro.ID</td>
                    <td style="width: 70px" >AC</td>
                    <td style="width: 70px" >WA</td>
                    <td style="width: 70px" >TLE</td>
                    <td style="width: 70px" >MLE</td>
                    <td style="width: 70px" >RE</td>
                    <td style="width: 70px" >CE</td>
                    <td style="width: 70px" >OLE</td>
                    <td style="width: 70px" >ILE</td>
                    <td style="width: 70px" >PE</td>
                    <td style="width: 70px" >Total</td>
                </tr>
            </thead>
            <tbody>
                <%=showStatistics.showStatic()%>

            </tbody>
        </table>
        </div>
                </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
