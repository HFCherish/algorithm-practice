<%-- 
    Document   : counter
    Created on : 2011-11-9, 19:51:18
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>计数</title>
    </head>
    <body>
        <%if(application.getAttribute("counter") == null)
                       {
            application.setAttribute("counter","1");
        }
        else
                       {
            String count = (String)application.getAttribute("counter").toString();
            int i = Integer.parseInt(count);
            i++;
            count = Integer.toString(i);
            application.setAttribute("counter",count);
        }%>
        您是第<%=application.getAttribute("counter")%>个访问者
    </body>
</html>
