<%-- 
    Document   : Search_bar
    Created on : 2011-11-19, 19:54:01
    Author     : ZXY
--%>
<%@page import="java.sql.ResultSet"%>
<%@page import="javabean.DB"%>
<%@page import="javabean.TypeMap"%>
<style>
    #search input{
        width: 80px;
    }
    #id{
    }
</style>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form id="search" action="search_bar" method="post" >
            <%
                String problem = "", user = "";
                int id = -1;
                if( request.getParameter("problem_id") != null && 
                        !request.getParameter("problem_id").equals("") )
                    id = Integer.parseInt(request.getParameter("problem_id"));
                if( id != -1 ) 
                    problem += (char)('A' + id - 1) + "";
                
                if( request.getParameter("user") != null )
                    user = request.getParameter("user");
                
            %>
            Problem ID: <input type="text" name="problem_id" value="<%=problem%>" >
            UserName: <input type="text" name="user" value="<%=user%>" >
            Language: <select name="language" >
                         <%
                            int lang = -1;
                            if( request.getParameter("language") != null && 
                                    !request.getParameter("language").equals("") ) {
                                lang = Integer.parseInt(request.getParameter("language"));
                            }
                         %>
                         <option value ="" >  All</option>
                        <%
                            for(int i=0; i<TypeMap.lang_num; i++) {
                                String html = "<option value =\"" + i + "\" ";
                                if( i == lang ) {
                                    html += " selected ";
                                }
                                html += ">" + TypeMap.Language(i) + "</option>";
                                out.println(html);
                            }
                        %>
                     </select>

            Result: <select name="result" >
                        <%//实现回显T T 。。
                            id = -1;
                            if( request.getParameter("result") != null && 
                                    !request.getParameter("result").equals("") ) {
                                id = Integer.parseInt(request.getParameter("result"));
                            }
                        %>
                        <option value ="" >  All                 </option>
                        <%
                            for(int i=0; i<TypeMap.result_num; i++) {
                                String html = "<option value =\"" + i + "\" ";
                                if( i == id ) {
                                    html += " selected ";
                                }
                                html += ">" + TypeMap.Result(i) + "</option>";
                                out.println(html);
                            }
                        %>
                        
                   </select>
            <input type="submit" value="Go" style="width: 40px" >
        </form>
    </body>
</html>
