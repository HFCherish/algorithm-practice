<%-- 
    Document   : add
    Created on : 2011-11-5, 20:45:51
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
        <%String s=request.getParameter("start");
         String e=request.getParameter("end");
         int S = Integer.parseInt(s);
         int E = Integer.parseInt(e);
         int sum=0;
         for(int i=S;i<=E;i++) sum+=i;
         %>
         <p>
             从<%=S%>到<%=E%>的连续和是：
             <br>
             <%=sum%>
         </p>
    </body>
</html>
