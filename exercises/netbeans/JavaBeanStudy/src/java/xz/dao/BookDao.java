/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package xz.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import xz.util.DBCon;
import xz.domain.Book;

/**
 *
 * @author Administrator
 */
public class BookDao {
    private Connection conn;
    
    public List findAllBooks()
    {
        conn = DBCon.getConnection();
        String listSQL = "select * from books";
        List list = new ArrayList();
        try{
            PreparedStatement psmt = conn.prepareStatement(listSQL);
            ResultSet rs = psmt.executeQuery();
            while(rs.next())
            {
                Book book = new Book();
                book.setId(rs.getLong(1));
                book.setName(rs.getString(2));
                book.setPrice(rs.getDouble(3));
                book.setAuthor(rs.getString(4));
                book.setBookConcern(rs.getString(5));
                book.setCounts(rs.getInt(6));
                list.add(book);
            }
            conn.commit();
            return list;
        }catch(Exception e)
        {
            e.printStackTrace();
        }finally
                {
                    if(conn != null)
                    {
                        try{
                            conn.close();
                        }catch(SQLException e){
                            e.printStackTrace();
                        }
                    }
                }
                return list;
    }
    
    public boolean saveBook(Book book) throws Exception
    {
        conn = DBCon.getConnection();
        String listSQL = "insert into books values(?,?,?,?,?)";
        PreparedStatement psmt = conn.prepareStatement(listSQL);
        try
        {
            psmt.setString(1,book.getName());
            psmt.setDouble(2,book.getPrice());
            psmt.setString(3,book.getAuthor());
            psmt.setString(4,book.getBookConcern());
            psmt.setInt(5,book.getCounts());
            psmt.executeUpdate();
            conn.commit();
            return true;
        }catch(SQLException e)
        {
            conn.rollback();
            e.printStackTrace();
        }finally{
            conn.close();
        }
        return false;
    }
      
}
