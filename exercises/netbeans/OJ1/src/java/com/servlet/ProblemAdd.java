/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javabean.DB;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author PL
 */
public class ProblemAdd extends HttpServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException, SQLException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            String title ="",  description="",input="",output="",sampleInput="",sampleOutput="",source="",hint="",inputData="",outputData="";
            int timeLimit, memoryLimit;
            title = request.getParameter("title");
            timeLimit = Integer.parseInt(request.getParameter("timeLimit"));
            memoryLimit = Integer.parseInt(request.getParameter("memoryLimit"));
            description = request.getParameter("description");
            input = request.getParameter("input");
            output = request.getParameter("output");
            sampleInput = request.getParameter("sampleInput");
            sampleOutput = request.getParameter("sampleOutput");
            source = request.getParameter("source");
            hint = request.getParameter ("hint");
            inputData = request.getParameter("inputData");
            outputData = request.getParameter("outputData");
            String sql1 = "insert into problems (title,outputData,inputData,hint,source,sampleInput,sampleOutput,output,input,description,timeLimit,memoryLimit) values ( '"+title+"','"+outputData+"','"+inputData+"','"+hint+"','"+source+"','"+sampleInput+"','"+sampleOutput+"','"+output+"','"+input+"','"+description+"','"+timeLimit+"','"+memoryLimit+"')";
            DB db = new DB();
            db.insert(sql1);
        } finally {
            response.sendRedirect("Problem_Manage.jsp");
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
            processRequest(request, response);
        } catch (SQLException ex) {
            Logger.getLogger(ProblemAdd.class.getName()).log(Level.SEVERE, null, ex);
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
            processRequest(request, response);
        } catch (SQLException ex) {
            Logger.getLogger(ProblemAdd.class.getName()).log(Level.SEVERE, null, ex);
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

    private void outprintln(String string) {
        throw new UnsupportedOperationException("Not yet implemented");
    }
}
