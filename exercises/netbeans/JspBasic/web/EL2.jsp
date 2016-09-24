<%-- 
    Document   : EL2
    Created on : 2011-11-9, 20:02:36
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*"%>
<%HashMap values = new HashMap();
values.put("财经","沪指今日大涨200点！");
values.put("热点", "嫦娥一号发回第一副图片");
values.put("奥运", "奥运会准备一切就绪");
String newcolor = "blue";
request.setAttribute("news",values);
request.setAttribute("color",newcolor);%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>EL</title>
    </head>
    <body>
        <h1>Hello ${param.name}</h1>
        <font color="${requestScope.color}">
        <h3>
            财经：${requestScope.news.财经}
            <br>
            热点：${requestScope.news.热点}
            <br>
            奥运：${requestScope.news["奥运"]}
            <br>
            其他：${requestScope.news.other}
        </h3>
        </font>
    </body>
</html>
