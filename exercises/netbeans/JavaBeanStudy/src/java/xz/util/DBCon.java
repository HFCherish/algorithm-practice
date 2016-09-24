/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package xz.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Administrator
 */
public class DBCon {
   public static Connection getConnection(){
    String url = "jdbc:mysql://localhost/test";
    String user = "root";
    String psw = "javaee";
    Connection conn = null;
    
   try
   {
       Class.forName("org.git.mm.mysql.Driver");
   }catch(ClassNotFoundException e)
   {
       e.printStackTrace();
   }
   try
   {
       conn = DriverManager.getConnection(url,user,psw);
       conn.setAutoCommit(false);
       return conn;
   }catch(SQLException e)
   {
       e.printStackTrace();
   }
   
   return null;}
}
