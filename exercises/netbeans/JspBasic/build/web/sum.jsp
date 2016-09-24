<%-- 
    Document   : sum
    Created on : 2011-11-6, 21:02:50
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title></title>
    </head>
    <body>
        <p>
            您的求和结果是
            <%String method = request.getParameter("method");
            String n = request.getParameter("n");
            int sum = 0;
            if(method == null)  method = "";
            if(n ==  null) n = "0";
            int N = Integer.parseInt(n);
            if(method.equals("1"))
                               {
                for(int i=1; i<=N; i++) sum+=i;
            }
                       else if(method.equals("2"))
                                                     {
                           for(int i=1; i<=N; i++)  sum += i*i;
                       }
                       else if(method.equals("3"))
                                                     {
                           for(int i=1; i<=N; i++)  sum +=i*i*i;
                       }%>
            <%=sum%>
        </p>
    </body>
</html>
