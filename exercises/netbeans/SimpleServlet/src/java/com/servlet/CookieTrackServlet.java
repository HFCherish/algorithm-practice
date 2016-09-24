/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.Cookie;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Administrator
 */
public class CookieTrackServlet extends HttpServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       Cookie cookie = null;
       Cookie[] cookies = request.getCookies();
       if(cookies != null)
       {
           boolean flag = false;
           for(int i=0; i<cookies.length && (!flag); i++)
           {
               if(cookies[i].getName().equals("VisitTimes"))
               {
                   String v = cookies[i].getValue();
                   int value = Integer.parseInt(v) + 1;
                   cookies[i].setValue(String.valueOf(value));
                   response.addCookie(cookies[i]);
                   flag = true;
                   cookie = cookies[i];
               }
           }
       }
       
       if(cookie == null)
       {
           int maxAge = -1;
           cookie = new Cookie("VisitTimes","1");
           cookie.setPath(request.getContextPath());
           cookie.setMaxAge(maxAge);
           response.addCookie(cookie);
       }
       
       response.setContentType("text/html;charset=utf-8");
       PrintWriter out = response.getWriter();
       //out.println("<html><head><title>Cookie跟踪会话</title></head></body><h2>您好！</h2><p>欢迎您第" + 
              // cookie.getValue() + "次访问本页面</p></body></html>");   
       try{
       out.println("<html>\n" + "<head>\n" + "<title>Cookie跟踪会话</title>\n" + "</head>\n" +
               "<body>\n" + "<h2>您好！</h2>\n" + "欢迎您第" + cookie.getValue() + "次访问本页面" + "</body>\n" + "</html>");
       }finally{
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
        response.setContentType("text/html; charset=utf-8");
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
