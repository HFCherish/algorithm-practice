package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.util.*;

public final class jspFunction_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.Vector _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public Object getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>request用法</title>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <font size=\"5\">\n");
      out.write("        客户使用的协议是：\n");
      out.write("        ");
String protocol = request.getProtocol();
        out.println(protocol);
      out.write("\n");
      out.write("        <br>获取接受客户提交信息 的页面：\n");
      out.write("        ");
String path = request.getServletPath();
        out.println(path);
      out.write("\n");
      out.write("        <br>接受客户提交信息的长度：\n");
      out.write("        ");
int length = request.getContentLength();
        out.println(length);
      out.write("\n");
      out.write("        <br>客户提交信息的方式：\n");
      out.write("        ");
String method = request.getMethod();
        out.println(method);
      out.write("\n");
      out.write("        <br>获取HTTP头文件中User-Agent的值：\n");
      out.write("        ");
String header1 = request.getHeader("User-Agent");
        out.println(header1);
      out.write("\n");
      out.write("        <br>获取HTTP头文件中accept的值：\n");
      out.write("        ");
String header2 = request.getHeader("accept");
        out.println(header2);
      out.write("\n");
      out.write("        <br>获取客户的IP地址：\n");
      out.write("        ");
String IP=request.getRemoteAddr();
        out.println(IP);
      out.write("\n");
      out.write("        <br>获取客户机的名称：\n");
      out.write("        ");
String clientName = request.getRemoteHost();
        out.println(clientName);
      out.write("\n");
      out.write("        <br>获取服务器的名称：\n");
      out.write("        ");
String serverName = request.getServerName();
        out.println(serverName);
      out.write("\n");
      out.write("        <br>获取服务器的端口号：\n");
      out.write("        ");
int serverPort = request.getServerPort();
        out.println(serverPort);
      out.write("\n");
      out.write("        <br>获取客户提交的所有参数的名字：\n");
      out.write("        ");
Enumeration enume = request.getParameterNames();
        while(enume.hasMoreElements())
                       {
            String s = (String)enume.nextElement();
            out.println(s);
        }
      out.write("\n");
      out.write("        <br>获取头名字的一个枚举：\n");
      out.write("        ");
Enumeration enums = request.getHeaderNames();
        while(enums.hasMoreElements())
                       {
            String s =(String)enums.nextElement();
            out.println(s);
        }
      out.write("\n");
      out.write("        <br>获取头文件中指定头名字的全部值的一个枚举：\n");
      out.write("        ");
Enumeration enuma = request.getHeaders("cookie");
        while(enuma.hasMoreElements())
                       {
            String s =(String)enuma.nextElement();
            out.println(s);
        }
      out.write("\n");
      out.write("        </font>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
