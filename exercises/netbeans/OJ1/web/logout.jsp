<%-- 
    Document   : logout
    Created on : 2011-11-20, 20:26:05
    Author     : zhangjiyang
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="refresh" content="3;url=index.jsp;charset=UTF-8">
        <title>登出</title>
    </head>
    <body>
        亲，已经成功登出，3秒后转到登录界面<br/>
        <% session.invalidate();%>
        下面是使用session再次获取username，如果是空，则登出成功。<br/>
        <%
            try {
                out.print(session.getAttribute("username"));
            } catch (Exception e) {
                out.print("登出成功！！");
               // out.print(e.toString());
            }
        %>

    </body>
</html>
