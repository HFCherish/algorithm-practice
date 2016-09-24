

<%@page import="javabean.DB"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="com.servlet.CHA" %>
<%@page import="java.io.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%
            request.setCharacterEncoding("UTF-8");
            //从表单获取传递的参数。。
            String problem_id = request.getParameter("ProblemID");
            String user_id = "1";
            int    code_length = request.getParameter("Code").length();
            String submit_time = CHA.DateToString();
            String language = request.getParameter("Language");
            String code = request.getParameter("Code");

            //以下组成一个SQL语句。。。
            String sql = "INSERT INTO code (problem_id,user_id,code_length,submit_time,language,code)";
            sql += " VALUES (";
            sql += "'" + problem_id + "',";
            sql += user_id+",";
            sql += code_length+",";
            sql += "'" + submit_time + "',";
            sql +=  language + ",";
            sql += "'" + code + "')";

            //先将已知的东西放到数据库中，这样在下面就可以得到RUN_ID
            DB db = new DB();
            db.insert(sql);
            String id = CHA.getrunid(submit_time);

        %>
        <%
            
            //获取文件的真实目录，其实就是为了获取当前工作目录
            String path = request.getRealPath("");
            //将代码写入文件，哈哈哈哈哈哈哈哈
            CHA.stringToFile(id, code, path, language);

            //out.print(path);
            int exitVal = 0;
            Runtime rt = Runtime.getRuntime();
            String file = id+((language.equals("0"))?".c":".cpp");
            String TL = "1000";
            String ML = "1000";
            String tt = "0";
            String mm = "0";
            try{
                Process proc = rt.exec("./onj "+file+" "+problem_id+" "+TL+" "+ML,null,new File(path));
                exitVal = proc.waitFor();
                out.print("Process exitValue: " + exitVal + "<br/>");
            } catch (Exception t){
                out.print(t.toString());
            }

            if( exitVal == 0 || exitVal ==1 || exitVal==8 ){
                tt = CHA.fileToString(path+"/tmp/"+file+".TIME");
                mm = CHA.fileToString(path+"/tmp/"+file+".MEM" );
                
            }
            if( exitVal == 2 ) tt = TL;
            if( exitVal == 3 ) mm = ML;
            db.update("code", "run_time", id, tt);
            db.update("code", "run_memory", id, mm);
            db.update("code", "result", id, ""+exitVal);

            db.close();
          %>
    </body>
</html>
