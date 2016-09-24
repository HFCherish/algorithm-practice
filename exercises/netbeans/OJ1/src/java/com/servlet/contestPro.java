/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import javabean.Contest;
import javabean.DB;
import javabean.jmp;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.text.ParseException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javabean.Format;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author ZXY
 */
public class contestPro extends HttpServlet {


    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException, ParseException, SQLException {
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        PrintWriter out = response.getWriter();
        try {
            String name      = Format.html(request.getParameter("contestName"));
            String length    = request.getParameter("length");
            String passwd    = request.getParameter("password");
            String startTime = request.getParameter("startTime");
            String introduce = Format.html(request.getParameter("introduce"));
            
            if( name == null || name.equals("") || length == null 
                    || length.equals("") || startTime == null || startTime.equals("") ){
                out.println("请补充完整比赛信息，两秒后自动跳转");
                out.println(jmp.to("changeContestInfo.jsp", 2));
                return ;
            }
            Contest contest = new Contest();
            DB db = new DB();
            try{
                if( contest.getContestName() != null )
                {
                    String table = "contest_info";
                    String id = "1";
                    db.update(table, "name", id, name);
                    db.update(table, "length",      id, length);
                    db.update(table, "password",    id, passwd);
                    db.update(table, "start_time",  id, startTime);
                    db.update(table, "introduce",   id, introduce);
                }
                else
                {
                    String sql = "insert into contest_info(id, name, start_time, length, public, password, introduce) "
                    + "values( 1," + "\'" + name + "\'" + "," + 
                    "\"" + startTime + "\"" + "," + "\"" + length + "\"" + "," + 
                    (passwd.equals("") == true ? "1" : "0") + ",'" + passwd + "','" + introduce + "')";
                    db.insert(sql);
                }
            } catch (SQLException e){
                out.print("您的输入有误，请重新输入，两秒后自动跳转");
                out.println(jmp.to("changeContestInfo.jsp", 2));   
                out.println(e.toString());
                db.close();
                return ;
            }
            /* 检测时间是否在现在时间之前，如果在之前的话，不能添加比赛。
            Contest contest1 = new Contest();
            if( contest1.getStartTime().before(new Date()) ){
                out.println("比赛开始时间需要在现在之间之后，请重新输入，两秒后自动跳转");
                out.println(jmp.to("changeContestInfo.jsp", 2));
                db.close();
                return ;
            }*/
            out.println("操作成功！两秒后自动跳转主页。");
            out.println(jmp.to("Manage.jsp", 2));
            db.close();
            
        } finally { 
            out.close();
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
        try {
            try {
                processRequest(request, response);
            } catch (SQLException ex) {
                Logger.getLogger(contestPro.class.getName()).log(Level.SEVERE, null, ex);
            }
        } catch (ParseException ex) {
            Logger.getLogger(contestPro.class.getName()).log(Level.SEVERE, null, ex);
        }
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
        try {
            try {
                processRequest(request, response);
            } catch (SQLException ex) {
                Logger.getLogger(contestPro.class.getName()).log(Level.SEVERE, null, ex);
            }
        } catch (ParseException ex) {
            Logger.getLogger(contestPro.class.getName()).log(Level.SEVERE, null, ex);
        }
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
