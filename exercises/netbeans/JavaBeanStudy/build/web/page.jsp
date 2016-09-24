<%-- 
    Document   : testSQL
    Created on : 2011-11-20, 15:24:25
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.lang.*"%>

<%
    Connection sqlCon;
    Statement sqlStmt;
    ResultSet sqlRst;
    String strCon;
    String strSQL;
    int intPageSize;        //一页显示的记录数
    int intPageCount;       //总页数
    int intPage;            //待显示页码
    String outtext;
    String strPage;
    int i;
    intPageSize = 2;
    strPage = request.getParameter("page");
    if(strPage == null)     //未查到page参数，此时显示第一页数据
               {
        intPage = 1;
    }
    else
               {
        intPage = Integer.parseInt(strPage);
        if(intPage < 1)  intPage = 1;
    }
    //装载JDBC驱动程序
    Class.forName("org.gjt.mm.mysql.Driver").newInstance();
    //连接数据库
    sqlCon = java.sql.DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","123");
    //创建语句对象
    sqlStmt = sqlCon.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE,java.sql.ResultSet.CONCUR_READ_ONLY);
    sqlRst = sqlStmt.executeQuery("select customerid,phone from customer");
    //获取记录总数
    sqlRst.last();
    int RowCount = sqlRst.getRow();
    //获取总页数
    intPageCount = (RowCount + intPageSize -1) / intPageSize;
    //调整待显示页码
    if(intPage > intPageCount)  intPage = intPageSize;   
%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>show page</title>
    </head>
    <body>
        <table>
            <tr>
                <td>页次：<%=intPage%>/<%=intPageCount%>页</td>
                <td><%=intPageSize%>条/页</td>
            </tr>
            <tr>
                <th>ID</th>
                <th>电话</th>
            </tr>
            <%
                if(intPageCount > 0)
                                       {
                sqlRst.absolute((intPage-1)*intPageSize + 1);
                i = 1;
                while((i <= intPageSize) && !sqlRst.isAfterLast())
                                       {
                    String id = sqlRst.getString(1);
                    String phone = sqlRst.getString(2);
            %>
            <tr>
                <td><%=id%></td>
                <td><%=phone%></td>
            </tr>
            <%
                sqlRst.next();
                i++;
                               }
                               }
            %>            
        </table>
            <%
                if(intPage > 1)
            %>
            <a href="page.jsp?page=<%=intPage-1%>">上一页</a>
            <%
                if(intPage < intPageCount)
            %>
            <a href="page.jsp?page=<%=intPage+1%>">下一页</a>
    </body>
</html>
<%
            if(sqlRst != null)            
            try
                                       {
                sqlRst.close();
            }catch(SQLException e1){}
            finally{
                try{
                    if(sqlStmt != null) sqlStmt.close();
                }catch(SQLException e2){}
                finally
                                               {
                    try{
                        if(sqlCon != null) sqlCon.close();
                    }catch(SQLException e3){}
                }
            }
%>
