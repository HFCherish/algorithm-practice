<%-- 
    Document   : Attribute_recieve
    Created on : 2011-11-6, 22:10:45
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Attribute接受参数示例</title>
    </head>
    <body>
        <%String name = (String)request.getAttribute("name");
        ArrayList content = new ArrayList();
        content = (ArrayList)request.getAttribute("value");
        int m = 0;
        String promt = "";
        if(content != null)
                       {
            m = Integer.parseInt((String)content.get(1));
            promt = (String)content.get(0);
        }%>
        <%for(int i=0; i<m; i++)
                       {
            out.println(promt + " " + name);
        }%>
    </body>
</html>
