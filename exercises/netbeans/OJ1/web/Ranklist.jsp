<%-- 
    Document   : Ranklist
    Created on : 2011-11-17, 15:21:46
    Autdor     : ZXY
--%>
<%@page import="show.showPage"%>
<%@page import="javabean.Page"%>
<%@page import="show.showRanklist"%>
<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link href="Css/global.css" rel="stylesheet" media="screen" type="text/css">
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
        <title>Ranklist</title>
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
        <h1>Ranklist</h1>
        <div id="list">
        <table>
            <thead>
                <tr>
                    <td style="width:50px">Rank</td>
                    <td style="width:110px" >User</td>
                    <td style="width:50px">Solved</td>
                    <td style="width:70px">Penalty</td>
                    <%
                        DB db = new DB();
                        int num = db.query_max_id("problems", "id");
                        int wid = 360/num;
                        for(int i=0; i<num; i++)
                            out.print("<td style=\"width:" + wid + "px\">" + (char)('A'+i) + "</td>");
                    %>
                </tr>
            </thead>
            <tbody>
                <%
                    Page curpage = new Page();
                    int sum = db.query_num("users");
                    int ROW = sum;// 显示一页显示多少行,sum的话说明全都在一页上
                    if( request.getParameter("page") == null ) {
                        curpage.init(1, sum, ROW);
                    } else {
                        int now = Integer.parseInt(request.getParameter("page"));
                        curpage.init(now, sum, ROW);
                    }
                    db.close();
                    out.println(showRanklist.showRank( curpage ));
                %>
            </tbody>
        </table>
        </div>
            
            <%--页码--%>
            <div id ="footpage">
                <%=showPage.show("Ranklist.jsp?", curpage)%>
            </div>
             </div>
        <jsp:include page="foot.jsp" flush="true" />   
</body> 
</html>
