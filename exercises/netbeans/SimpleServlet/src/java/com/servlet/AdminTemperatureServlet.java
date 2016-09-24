/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Administrator
 */
public class AdminTemperatureServlet extends HttpServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       
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
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            String temperature = (String)getServletContext().getAttribute("Temperature");
            if(temperature == null)
            {
                temperature = (String)getInitParameter("Temperature");
                getServletContext().setAttribute("Temperature",temperature);
            }
            out.println("<html><head><title>气温更新</title></head>\n"
                    + "<body><h1>当前气温</h1>"
                    + "<form action=\"" + response.encodeURL("adminTemperature") + "\" method=\"post\">"
                    + "当前气温（摄氏度）"
                    + "<input type=\"text\" name=\"temperature\" value=" + temperature + ">"
                    + "<input type=\"submit\" name=\"btn_submit\" value=\"更新\">"
                    + "</form></body></html>");
        } finally {            
            out.close();
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
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();
        try{
            String temperature = request.getParameter("temperature");
            getServletContext().setAttribute("Temperature", temperature);
            out.println("<html><head><title>气温显示</title></head>\n"
                    + "<body>当前气温：" + temperature + "摄氏度</body></html>");
        }finally{
            out.close();
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
