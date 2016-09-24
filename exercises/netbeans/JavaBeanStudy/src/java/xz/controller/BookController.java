/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package xz.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.List;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import xz.dao.BookDao;
import xz.domain.Book;

/**
 *
 * @author Administrator
 */
@WebServlet(name = "BookController", urlPatterns = {"/BookController"})
public class BookController extends HttpServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int arg = Integer.parseInt((request.getParameter("arg")));
        switch(arg)
        {
            case 1:
                this.saveBooks(request,response);
                break;
            case 2:
                this.saveBooks(request,response);
                break;
        }
    }
    
    public void findAllBooks(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException
    {
        BookDao dao = new BookDao();
        List list = dao.findAllBooks();
        request.setAttribute("booklist",list);
        RequestDispatcher dispatcher = request.getRequestDispatcher("showAllBooks.jsp");
        dispatcher.forward(request,response);
    }
    
    public void saveBooks(HttpServletRequest req,HttpServletResponse res) throws UnsupportedEncodingException, ServletException, IOException
    {
        req.setCharacterEncoding("utf-8");
        String name = req.getParameter("name");
        String price = req.getParameter("price");
        String author = req.getParameter("author");
        String bookConcern = req.getParameter("bookConcern");
        String counts = req.getParameter("counts");
        
        Book book = new Book();
        book.setName(name);
        book.setAuthor(author);
        book.setPrice(Double.parseDouble(price));
        book.setBookConcern(bookConcern);
        book.setCounts(Integer.parseInt(counts));
        
        BookDao dao = new BookDao();
        try
        {
            dao.saveBook(book);
        }catch(Exception e)
        {
            e.printStackTrace();
        }
        this.findAllBooks(req, res);
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
