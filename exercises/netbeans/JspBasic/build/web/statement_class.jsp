<%-- 
    Document   : statement_class
    Created on : 2011-11-4, 22:21:53
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>声明类</title>
    </head>
    <body>
        <%!public class sayHello{
            boolean county;
            sayHello(boolean county)
                                       {
                this.county = county;
            }
            String Hello()
                                       {
                if(county)  return "Hello";
                               else return "你好";
            }
        }%>
        <%sayHello a = new sayHello(true);%>
        <%=a.Hello()%>
    </body>
</html>
