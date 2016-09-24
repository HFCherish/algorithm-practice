<%-- 
    Document   : saveBook
    Created on : 2011-11-15, 16:31:48
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action ="BookController" method="post">
            图书名称：<input type="text">
            图书价格：<input type="text">
            图书作者：<input type="text"/>
            出版社：<input type="text"/>
            存放数量：<input type="text"/>
            <input type="submit" value="提交"/>
        </form>
    </body>
</html>
