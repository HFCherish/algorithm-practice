<%-- 
    Document   : Status
    Created on : 2011-11-19, 11:09:35
    Autdor     : ZXY
--%>

<%@page import="javabean.Status"%>
<%@page import="java.util.List"%>
<%@page import="javabean.Check"%>
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
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />
        <title>Status</title>
    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="BLeft.jsp" flush="true" />
        <div id="content">
        <%
            String user = String.valueOf(session.getAttribute("username"));
            if( Check.check_user(user) == false && Check.check_admin(user) == false )
                out.println("请登录！");
            boolean admin = Check.check_admin(user);
        %>
        <h1>Status</h1>
        <div id="list">
        <table>
            <thead>
                <tr>
                    <!--<td>Run ID          </td>-->
                    <td style="width:120px">User            </td>
                    <td style="width:60px">Problem         </td>
                    <td style="width:190px">Result          </td>
                    <td style="width:50px">Language        </td>
                    <td style="width:60px">Time        </td>
                    <td style="width:60px">Memory      </td>
                    <td style="width:60px">Code.len     </td>
                    <td style="width:150px">Submit Time     </td>
                </tr>
            </thead>
            <tbody>
                <%
                    String sql = "";
                    if( !admin ) {
                        //user 上面已经有了
                        sql = "select * from code ";
                        int user_id = -1;
                        DB db = new DB();
                        String sql1 = "select id from users where name = \"" + user + "\"";
                        ResultSet rst = db.query(sql1);
                        while( rst.next() )
                            user_id = rst.getInt("id");
                        sql += " where user_id = " + user_id;
                        sql += " order by submit_time DESC";
                        db.close();
                    } else {
                        sql = "select * from code order by submit_time DESC";
                    }
                    DB db = new DB();
                    Page curpage = new Page();
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
                    
                    List array = showStatus.showStatu(curpage, sql, admin);
                    for(int i=0; i<array.size(); i++) {
                        Status st = (Status)array.get(i);
                %>
                <tr>
                    <!--<td><%=st.getRun_id()%>                           </td>-->
                    <td><%=st.getUser()%>                             </td>
                    <td><%=st.getProblem_id()%>                       </td>
                    <td <%=st.getResult_color()%>> <%=st.getResult()%></td>
                    <td><%=st.getLanguage()%>                         </td>
                    <td><%=st.getTime()%>                             </td>
                    <td><%=st.getMemory()%>                           </td>
                    <td><%=st.getCode_len()%>                         </td>
                    <td><%=st.getSubmit_time()%>                      </td>
                </tr>
                <%}%>
            </tbody>
        </table>
        </div>
            <%--页码--%>
            <div id ="footpage">
                <%=showPage.show("Status.jsp?", curpage)%>
            </div>
            </div>
        <jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
