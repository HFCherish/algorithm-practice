/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
import javabean.DB;
import javax.servlet.annotation.WebServlet;

/**
 *
 * @author zhangjiyang
 */
@WebServlet(name = "Login", urlPatterns = {"/Login"})
public class Login extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        String username = new String();
        String passwd = new String();

        username = request.getParameter("username");
        passwd = request.getParameter("passwd");
        if (username == null) {
            username = "";
        }
        if (passwd == null) {
            passwd = "";
        }
        try {
            /*
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            String url = "jdbc:mysql://localhost/oj?useUnicode=true&characterEncoding=UTF-8";
            Connection connection = DriverManager.getConnection(url, "root", "m121");
            String sql = "select * from Users where username='" + username
                    + "' and password = '" + passwd + "'";
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
             * 
             */
            DB db = new DB();
            ResultSet rs=db.query( "select * from users where name='"+username+"' and password='"+passwd+"'");
            if (rs.next()) {
                //out.println("登录成功！");
                HttpSession session = request.getSession(true);
                session.setAttribute("username", username);
                out.println(session.getId());
                out.println(session.getAttribute("username"));
                db.close();
                RequestDispatcher dispatcher = request.getRequestDispatcher("login_success.jsp");
                dispatcher.forward(request, response);
            } else {
                //out.println("用户名不存在或密码错误！");
                db.close();
                RequestDispatcher dispatcher = request.getRequestDispatcher("login_failure.jsp");
                dispatcher.forward(request, response);
                
            }
        } catch (Exception e) {
            out.println(e.toString());
            out.println("error occurd");
        } finally {
            //   rs.close();
            // stmt.close();
            //connection.close();
        }
       // response.sendRedirect("");




    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /** 
     * Handles the HTTP <code>GET</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /** 
     * Handles the HTTP <code>POST</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        request.setCharacterEncoding("UTF-8");
        processRequest(request, response);
    }

    /** 
     * Returns a short description of the servlet.
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>
}
