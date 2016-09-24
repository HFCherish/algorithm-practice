package com.servlet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.*;
import javabean.DB;

/**
 *
 * @author zhangjiyang
 */
@WebServlet(name = "Register", urlPatterns = {"/Register"})
public class Register extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String username = request.getParameter("username");
        String passwd = request.getParameter("passwd");
        String nickname = request.getParameter("nickname");
        String question = request.getParameter("question");
        String answer = request.getParameter("answer");
        String email = request.getParameter("email");
        String school = request.getParameter("school");
        username = '"' + username + '"';
        passwd = '"' + passwd + '"';
        nickname = '"' + nickname + '"';
        email = '"' + email + '"';
        answer = '"' + answer + '"';
        school = '"' + school + '"';
        question = '"' + question + '"';
        try {
            
            DB db = new DB();
            String sql2 = "select max(id) from users";
            ResultSet rs = db.query(sql2);
            int id = 0;
            while (rs.next()) {
                id = rs.getInt("max(id)");
            }
            id++;
            String sql = "insert into oj.users(id, name, password, nickname, safe_problem, safe_answer,email,school) values(" 
                    + id + ',' + username + ',' + passwd + ',' + nickname + ',' + question + ',' + answer + ',' + email + ',' + school + ')';
            out.println(sql);
            db.update(sql);
            out.print("注册成功");
            db.close();
        }catch(com.mysql.jdbc.exceptions.jdbc4.MySQLIntegrityConstraintViolationException e)
        {
            out.print("啊哦,帐号或者昵称已经有人使用了,");
            out.print("<br/>");
            out.print("请更换一个吧.");
             out.println("<a href='register.jsp'>注册</a>");
        
        }
       
        catch (SQLException e) {

            out.print(e.toString());
            out.print("<br/>");
            out.printf("<h1>Ooops! something wrong!maybe you can change your username or nickname</h1>");
        } catch (Exception e) {
            out.print("<br/>");
            out.printf("<h1>oops! something wrong!maybe you can change your username or nickname</h1>");
            out.print(e.toString());
        } finally {
            //   try{
            //  Thread.sleep(3000);
            //   }
            //     catch(Exception e){
            //        }
            // response.sendRedirect("index.html");
        }
        out.println("<a href='index.jsp'>登陆</a>");
        // response.sendRedirect("index.html");
        try {
        } finally {
            out.close();
            response.sendRedirect("index.jsp");
        }
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
