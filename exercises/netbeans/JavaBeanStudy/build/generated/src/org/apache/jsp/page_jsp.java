package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.lang.*;

public final class page_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("\n");
      out.write("\n");

    Connection sqlCon;
    Statement sqlStmt;
    ResultSet sqlRst;
    String strCon;
    String strSQL;
    int intPageSize;        //一页显示的记录数
    int intPageCount;       //总页数
    int intPage;            //待显示页码
    String outtext;
    String strPage;
    int i;
    intPageSize = 2;
    strPage = request.getParameter("page");
    if(strPage == null)     //未查到page参数，此时显示第一页数据
               {
        intPage = 1;
    }
    else
               {
        intPage = Integer.parseInt(strPage);
        if(intPage < 1)  intPage = 1;
    }
    //装载JDBC驱动程序
    Class.forName("org.gjt.mm.mysql.Driver").newInstance();
    //连接数据库
    sqlCon = java.sql.DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","123");
    //创建语句对象
    sqlStmt = sqlCon.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE,java.sql.ResultSet.CONCUR_READ_ONLY);
    sqlRst = sqlStmt.executeQuery("select customerid,phone from customer");
    //获取记录总数
    sqlRst.last();
    int RowCount = sqlRst.getRow();
    //获取总页数
    intPageCount = (RowCount + intPageSize -1) / intPageSize;
    //调整待显示页码
    if(intPage > intPageCount)  intPage = intPageSize;   

      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>show page</title>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <table>\n");
      out.write("            <tr>\n");
      out.write("                <td>页次：");
      out.print(intPage);
      out.write('/');
      out.print(intPageCount);
      out.write("页</td>\n");
      out.write("                <td>");
      out.print(intPageSize);
      out.write("条/页</td>\n");
      out.write("            </tr>\n");
      out.write("            <tr>\n");
      out.write("                <th>ID</th>\n");
      out.write("                <th>电话</th>\n");
      out.write("            </tr>\n");
      out.write("            ");

                if(intPageCount > 0)
                                       {
                sqlRst.absolute((intPage-1)*intPageSize + 1);
                i = 1;
                while((i <= intPageSize) && !sqlRst.isAfterLast())
                                       {
                    String id = sqlRst.getString(1);
                    String phone = sqlRst.getString(2);
            
      out.write("\n");
      out.write("            <tr>\n");
      out.write("                <td>");
      out.print(id);
      out.write("</td>\n");
      out.write("                <td>");
      out.print(phone);
      out.write("</td>\n");
      out.write("            </tr>\n");
      out.write("            ");

                sqlRst.next();
                i++;
                               }
                               }
            
      out.write("            \n");
      out.write("        </table>\n");
      out.write("            ");

                if(intPage > 1)
            
      out.write("\n");
      out.write("            <a href=\"page.jsp?page=");
      out.print(intPage-1);
      out.write("\">上一页</a>\n");
      out.write("            ");

                if(intPage < intPageCount)
            
      out.write("\n");
      out.write("            <a href=\"page.jsp?page=");
      out.print(intPage+1);
      out.write("\">下一页</a>\n");
      out.write("    </body>\n");
      out.write("</html>\n");

            if(sqlRst != null)            
            try
                                       {
                sqlRst.close();
            }catch(SQLException e1){}
            finally{
                try{
                    if(sqlStmt != null) sqlStmt.close();
                }catch(SQLException e2){}
                finally
                                               {
                    try{
                        if(sqlCon != null) sqlCon.close();
                    }catch(SQLException e3){}
                }
            }

      out.write('\n');
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
