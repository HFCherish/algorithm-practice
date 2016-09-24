<%-- 
    Document   : index
    Created on : 2011-11-24, 14:26:22
    Author     : Scriptkids
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <title>登录</title>
        <link href="Css/style.css" rel="stylesheet" type="text/css" media="screen" />
    </head>

    <body>

        <div id="Login">
            <h1>登录</h1>
            <form action="Login" name ="LoginForm" method="post">
                <fieldset>
                    <label for="username">帐号:</label>
                    <input type="text" id="username" name="username" placeholder="请输入用户名" />
                    <label for="passwd">密码:</label>
                    <input type="password" id="passwd" name="passwd" placeholder="密码"/>
                    <input type="submit" value="提交" onclick="validateLogin()" />
                </fieldset>
            </form>
            <a href="register.jsp">亲，如果木有帐号，先来注册一个把。</a> <br/>
            
        </div>

       
        <script language="JavaScript">
            function validateLogin(){
                var UserName=document.LoginForm.username.value;
                var UserPassword=document.LoginFrom.password.value;
                if(UserName==""){
                    alert("亲，你忘记输入帐号了呦。");
                    return false;
                }
                else if(UserPassword==""){
                   alert("亲，你忘记输入密码了哦。");
                    return false;
                }
            
                
            }
            </script>
     
    </body>
</html>
