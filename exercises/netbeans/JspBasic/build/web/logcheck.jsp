<%-- 
    Document   : logcheck
    Created on : 2011-11-9, 16:33:48
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%String promt = new String();
        String Name = request.getParameter("name");
        boolean hasLog = false;
        ArrayList names = (ArrayList)session.getAttribute("lognames");
        if(names == null)
                       {
            names = new ArrayList();
            names.add(Name);
            session.setAttribute("lognames", names);
            promt = "你的session已经写入";
        }
        else
                       {
            for(int i=0; i<names.size(); i++)
                               {
                String temp = (String)names.get(i);
                if(temp.equals(Name))
                                       {
                    promt = "你已经登陆";
                    hasLog = true;
                    break;
                }
        }
           if(!hasLog)
           {
               names.add(Name);
               session.setAttribute("lognames", names);
               promt = "hello!欢迎登陆";
           }                 
                       }%>
        <br>
        <%=promt%>
    </body>
</html>
