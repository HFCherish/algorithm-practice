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
public class CartServlet extends HttpServlet {

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
            HttpSession session = req.getSession(true);
            HashMap cart = (HashMap) session.getAttribute("cart");
            if(cart == null)
            {
                cart = new HashMap();
                cart.put("apple", "0");
                cart.put("banana", "0");
                cart.put("grape", "0");
                session.setAttribute("cart",cart);
            }
            String apple_amount = req.getParameter("apple_amount");
            String banana_amount = req.getParameter("banana_amount");
            String grape_amount = req.getParameter("grape_amount");
            String appleAmount = (String)cart.get("apple");
            String bananaAmount = (String)cart.get("banana");
            String grapeAmount = (String)cart.get("grape");
            int new_apple_amount = Integer.parseInt(apple_amount,10) + Integer.parseInt(appleAmount,10);
            int new_banana_amount = Integer.parseInt(banana_amount,10) + Integer.parseInt(bananaAmount,10);
            int new_grape_amount = Integer.parseInt(grape_amount,10) + Integer.parseInt(grapeAmount,10);
            cart.put("apple", String.valueOf(new_apple_amount));
            cart.put("banana", String.valueOf(new_banana_amount));
            cart.put("grape", String.valueOf(new_grape_amount));
            
            out.println("<html><head><title>购物车内容</title></head>"
                    + "<body><h1>你的购物车里有</h1>"
                    + new_apple_amount + "斤苹果 " + new_banana_amount + "斤香蕉 " + new_grape_amount + "斤葡萄\n"
                    + "<hr><a href=\"" + res.encodeURL("catalog") + "\" >回到水果店</input></body></html>");
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
