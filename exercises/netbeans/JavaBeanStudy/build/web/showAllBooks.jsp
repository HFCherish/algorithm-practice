<%-- 
    Document   : showAllBooks
    Created on : 2011-11-15, 16:32:11
    Author     : Administrator
--%>

<%@page import="xz.domain.Book"%>
<%@page import="java.util.List"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <table>
            <tr>
                <th>图书名称</th>
                <th>图书价格</th>
                <th>图书作者</th>
                <th>出版社</th>
                <th>存放数量</th>
            </tr>
            <%List list = (List)request.getAttribute("booklist");
            Book book = new Book();
            for(int i=0; i<list.size(); i++)
            {                   
                book = (Book)list.get(i);%>
            <tr>
                <td><%=book.getName()%></td>
                <td><%=book.getPrice()%></td>
                <td><%=book.getAuthor()%></td>
                <td><%=book.getBookConcern()%></td>
                <td<%=book.getCounts()%></td>
            </tr>
            <%}%>
            <tr>
                <td><a href="saveBook.jsp">添加图书信息</a></td>
            </tr>
        </table>
    </body>
</html>
