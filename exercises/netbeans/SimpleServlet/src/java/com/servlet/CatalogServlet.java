/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author Administrator
 */
public class CatalogServlet extends HttpServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        res.setContentType("text/html;charset=UTF-8");
        PrintWriter out = res.getWriter();
        try {
            HttpSession session = req.getSession();
            int itemCount = 0;
            HashMap cart = (HashMap)session.getAttribute("cart");
            if(cart != null)
            {
                itemCount = cart.size();
            }
            out.println("<html><head><title>简单购物车Example</title></head>"
                    + "<body><h1>欢迎来到开心水果店购物</h1>"
                    + "<table border = \"0\" width = \"100%\"><tr>"
                    + "<td align=\"left\" valign=\"bottom\"></td></tr></table><hr>"
                    + "<form method = \"POST\" action = \"" + res.encodeURL("cart") + "\">"
                    + "<table cellspacing=\"5\" cellpadding=\"5\"><tr>"
                    + "<th align=\"center\">种类</th>"
                    + "<th align=\"center\">单价</th>"
                    + "<th align=\"center\">数量</th></tr>"
                    + "<tr><td align=\"center\">苹果</td>"
                    + "<td align=\"center\">5.5</td>"
                    + "<td align=\"center\"><input type=\"text\" name=\"apple_amount\"></td></tr>"
                    + "<tr><td align=\"center\">香蕉</td>"
                    + "<td align=\"center\">4.5</td>"
                    + "<td align=\"center\"><input type=\"text\" name=\"banana_amount\"></td></tr>"
                    + "<tr><td align=\"center\">葡萄</td>"
                    + "<td align=\"center\">3.6</td>"
                    + "<td align=\"center\"><input type=\"text\" name=\"grape_amount\"></td></tr></table><hr>"
                    + "<input type=\"submit\" value=\"放入购物车\" name=\"btn_submit\"></form></body></html>");
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
