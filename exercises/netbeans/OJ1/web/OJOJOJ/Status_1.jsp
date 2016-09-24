<%-- 
    Document   : Status
    Created on : 2011-11-19, 11:09:35
    Autdor     : ZXY
--%>

<%@page import="java.sql.ResultSet"%>
<%@page import="java.util.Set"%>
<%@page import="java.util.HashMap"%>
<%@page import="show.showPage"%>
<%@page import="javabean.DB"%>
<%@page import="javabean.Page"%>
<%@page import="show.showStatus"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link href="Css/global.css" rel="stylesheet" media="screen" type="text/css">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Status</h1>
        <%@include file="Search_bar.jsp" %>
        <div id="list">
        <table>
            <thead>
                <tr>
                    <td>Run ID          </td>
                    <td class="user">User            </td>
                    <td>Problem         </td>
                    <td class="result" >Result          </td>
                    <td>Language        </td>
                    <td>Run Time        </td>
                    <td>Run Memory      </td>
                    <td>Code Length     </td>
                    <td class="subtime" >Submit Time     </td>
                </tr>
            </thead>
            <tbody>
                <%
                    Page curpage = new Page();
                    String problem_id = request.getParameter("problem_id");
                    //user 上面已经有了
                    String result = request.getParameter("result");
                    String language = request.getParameter("language");
                    
                    String sql = "select * from code where id > 0 ";
                   
                    if( problem_id != null && !problem_id.equals("") )
                        sql += " and problem_id = " + problem_id;
                    if( user != null && !user.equals("") ){
                        int user_id = -1;
                        DB db = new DB();
                        String sql1 = "select id from user where name = \"" + user + "\"";
                        ResultSet rst = db.query(sql1);
                        while( rst.next() )
                            user_id = rst.getInt("id");
                        sql += " and user_id = " + user_id;
                        db.close();
                    }
                    if( result != null && !result.equals("") )
                        sql += " and result = " + result;
                    if( language != null && !language.equals("") )
                        sql += " and language = " + language;
                   
                    sql += " order by submit_time DESC";
                    
                    DB db = new DB();
                    ResultSet rst = db.query(sql);
                    rst.last();
                    int sum = rst.getRow();
                    int ROW = 10;      // 显示一页显示多少行,sum的话说明全都在一页上
                    if( request.getParameter("page") == null ) {
                        curpage.init(1, sum, ROW);
                    } else {
                        int now = Integer.parseInt(request.getParameter("page"));
                        curpage.init(now, sum, ROW);
                    }
                    
                    db.close();
                    
                %>
                <%=showStatus.showStatu(curpage, sql)%>
            </tbody>
        </table>
        </div>
            <%--页码--%>
            <div id ="footpage">
                <%
                    String html = "Status.jsp?";
                    if( problem_id != null )
                        html += "problem_id=" + problem_id;
                    if( user != null && !user.equals("") )
                        html += "&user=" + user;
                    if( result != null )
                        html += "&result=" + result;
                    if( language != null )
                        html += "&language=" + language + "&";
                %>
                <%=showPage.show(html, curpage)%>
            </div>
    </body>
</html>
