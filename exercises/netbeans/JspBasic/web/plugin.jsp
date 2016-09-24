<%-- 
    Document   : plugin
    Created on : 2011-11-5, 21:59:24
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>plugin</title>
    </head>
    <body>
        <jsp:plugin type="applet" code="Circle.class">
            <jsp:fallback>
                Plugin tag OBJECT or EMBED not supported by browser.
            </jsp:fallback>
        </jsp:plugin>
    </body>
</html>
s