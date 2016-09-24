<%-- 
    Document   : Announcement
    Created on : 2011-11-21, 21:45:39
    Author     : ZXY
--%>

<%@page import="java.sql.ResultSet"%>
<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
     <marquee style="color: red; font-weight: bold" scrollamount=2 scrolldelay=30 onMouseOver="javascript:this.stop();" onMouseOut="javascript:this.start();">
        <%
            DB db = new DB();
            String sql = "select * from announcement";
            ResultSet rst = db.query(sql);
            while( rst.next() ) {
                String ann = rst.getString("content");
                out.println(ann + "<br>");
            }
            db.close();
        %>
    </marquee>
   </body>
</html>
