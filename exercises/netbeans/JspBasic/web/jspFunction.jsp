<%-- 
    Document   : jspFunction
    Created on : 2011-11-6, 19:33:40
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>request用法</title>
    </head>
    <body>
        <font size="5">
        客户使用的协议是：
        <%String protocol = request.getProtocol();
        out.println(protocol);%>
        <br>获取接受客户提交信息 的页面：
        <%String path = request.getServletPath();
        out.println(path);%>
        <br>接受客户提交信息的长度：
        <%int length = request.getContentLength();
        out.println(length);%>
        <br>客户提交信息的方式：
        <%String method = request.getMethod();
        out.println(method);%>
        <br>获取HTTP头文件中User-Agent的值：
        <%String header1 = request.getHeader("User-Agent");
        out.println(header1);%>
        <br>获取HTTP头文件中accept的值：
        <%String header2 = request.getHeader("accept");
        out.println(header2);%>
        <br>获取客户的IP地址：
        <%String IP=request.getRemoteAddr();
        out.println(IP);%>
        <br>获取客户机的名称：
        <%String clientName = request.getRemoteHost();
        out.println(clientName);%>
        <br>获取服务器的名称：
        <%String serverName = request.getServerName();
        out.println(serverName);%>
        <br>获取服务器的端口号：
        <%int serverPort = request.getServerPort();
        out.println(serverPort);%>
        <br>获取客户提交的所有参数的名字：
        <%Enumeration enume = request.getParameterNames();
        while(enume.hasMoreElements())
                       {
            String s = (String)enume.nextElement();
            out.println(s);
        }%>
        <br>获取头名字的一个枚举：
        <%Enumeration enums = request.getHeaderNames();
        while(enums.hasMoreElements())
                       {
            String s =(String)enums.nextElement();
            out.println(s);
        }%>
        <br>获取头文件中指定头名字的全部值的一个枚举：
        <%Enumeration enuma = request.getHeaders("cookie");
        while(enuma.hasMoreElements())
                       {
            String s =(String)enuma.nextElement();
            out.println(s);
        }%>
        </font>
    </body>
</html>
