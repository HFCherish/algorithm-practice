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
public class CookieServlet extends HttpServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            /* TODO output your page here
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet CookieServlet</title>");  
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet CookieServlet at " + request.getContextPath () + "</h1>");
            out.println("</body>");
            out.println("</html>");
             */
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
    protected void doGet(HttpServletRequest request, HttpServletResponse res)
            throws ServletException, IOException {
         Cookie cookie = null;
         Cookie[] cookies = request.getCookies();
         boolean newCookie = false;
         if(cookies != null){
            for(int i=0; i<cookies.length; i++)
            {
                if(cookies[i].getName().equals("SimpleServlet"))
                {
                    cookie = cookies[i];
                }
            }
         }
         if(cookie == null)
         {
             newCookie = true;
             int maxAge = 10000;
             cookie = new Cookie("SimpleServlet","created by xz");
             cookie.setPath(request.getContextPath());
             cookie.setMaxAge(maxAge);
             res.addCookie(cookie);
         }
         res.setContentType("text/html");
         java.io.PrintWriter out = res.getWriter();
         out.println("<html><head><title>cookie info</title></head>" + 
                 "<body><h2>Information about the cookie named \"ServletStudy\"</h2>" + 
                 "<p>cookies value:" + cookie.getValue() + "</p>" +
                 "<p>cookies Max-Age:" + cookie.getMaxAge() + "</p>" +
                 "<p>cookies Path:" + cookie.getPath() + "</p>" +
                 "</body></html>");
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
