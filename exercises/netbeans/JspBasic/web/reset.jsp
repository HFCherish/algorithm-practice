<%-- 
    Document   : reset
    Created on : 2011-11-27, 22:16:21
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
        <form style="text-align: center;">
            <fieldset>
                <legend>基本信息</legend>
                用户名<input type="text" value="djklj">
                密码<input type="password">               
            </fieldset>
            <fieldset>
                <legend>附加信息</legend>
                性别<input type="radio" name="gender">男
                <input type="radio" name="gender">女
                个人介绍<textarea value="fjklds"></textarea>
                <select>
                    <option value="kdjlj">计算机</option>
                    <option>简单快乐</option>
                </select>
            </fieldset>
            <fieldset>
                <input type="submit" value="submit" />
                <input type="reset" value="reset" />
            </fieldset>
        </form>
    </body>
</html>
