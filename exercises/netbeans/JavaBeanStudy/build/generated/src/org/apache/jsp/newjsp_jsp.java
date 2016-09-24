package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class newjsp_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      response.setContentType("text/html");
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
      out.write("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
      out.write("<html xmlns=\"http://www.w3.org/1999/xhtml\" >\n");
      out.write("<head>\n");
      out.write("<title>?CSS?????? by www.865171.cn</title>\n");
      out.write("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
      out.write("</head>\n");
      out.write("<body>\n");
      out.write("<h2>2) ? 2</h2>\n");
      out.write("\n");
      out.write("<div id=\"bluemenu\" class=\"bluetabs\">\n");
      out.write("<ul>\n");
      out.write("<li><a href=\"http://www.865171.cn/\">??</a></li>\n");
      out.write("<li><a href=\"http://www.865171.cn/\" rel=\"dropmenu1_b\">DIV+CSS</a></li>\n");
      out.write("<li><a href=\"http://www.865171.cn/\" rel=\"dropmenu2_b\">???</a></li>\n");
      out.write("<li><a href=\"http://www.865171.cn/\">????</a></li>\n");
      out.write("</ul>\n");
      out.write("</div>\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!--1st drop down menu -->                                                   \n");
      out.write("<div id=\"dropmenu1_b\" class=\"dropmenudiv_b\">\n");
      out.write("<a href=\"http://www.865171.cn/\">CSS??</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">CSS??</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">CSS??</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">CSS????</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">CSS??</a>\n");
      out.write("<a href=\"www.865171.cn/\">CSS??</a>\n");
      out.write("<a href=\"www.865171.cn/\">??</a>\n");
      out.write("</div>\n");
      out.write("\n");
      out.write("\n");
      out.write("<!--2nd drop down menu -->                                                \n");
      out.write("<div id=\"dropmenu2_b\" class=\"dropmenudiv_b\" style=\"width: 150px;\">\n");
      out.write("<a href=\"http://www.865171.cn/\">CSS Drive</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">JavaScript Kit</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">Coding Forums</a>\n");
      out.write("<a href=\"http://www.865171.cn/\">JavaScript Reference</a>\n");
      out.write("</div>\n");
      out.write("\n");
      out.write("</body>\n");
      out.write("</html>");
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
