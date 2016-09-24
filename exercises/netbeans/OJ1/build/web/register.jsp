<%-- 
    Document   : register
    Created on : 2011-11-24, 14:37:52
    Author     : Scriptkids
--%>

<!DOCTYPE html>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<html>
    <head>
        <title>注册账号</title>
        <link href="Css/style.css" rel="stylesheet" type="text/css" media="screen"/>
    </head>
    <body>
        <div id="Register">
            <h1>注册</h1>
            <form action="Register" method="post">
                <fieldset>
                    <label for="username">账号:</label>
                    <input type="text" id="username" name="username"/>

                    <label for="passwd">密码: </label>
                    <input type="text" id ="passwd" name="passwd"/>

                    <label for="nickname">昵称: </label>
                    <input type="text" id ="nickname" name="nickname"/>

                    <label for="email"> 邮箱:</label>
                    <input type="email" id ="email" name="email"/>

                    <label for="question">密码提示问题: </label>
                    <input type="text" id ="question" name="question"/>

                    <label for="answer">密码提示问题答案: </label>
                    <input type="text" id ="answer" name="answer"/>

                    <input type="submit" value="提交"/>
                </fieldset>
            </form>
        </div>
    </body>
</html>


