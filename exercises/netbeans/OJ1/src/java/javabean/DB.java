/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author ZXY
 */
public class DB {
    private static String dbDriver = "org.gjt.mm.mysql.Driver";
    private static String url = "jdbc:mysql://localhost:3306/OJ";
    private static String usr = "root";
    private static String psw = "123";
    public  static Connection connection = null;
    public  ResultSet sqlRst = null;
    public  Statement sqlStmt = null;
    public  PreparedStatement stmt = null;
    
    static{
        try{
            Class.forName( dbDriver ).newInstance();
            connection = DriverManager.getConnection(url + "?user=" + 
                    usr + "&password=" + psw + "&useUnicode=true&characterEncoding=utf-8");
        } catch (Exception x){
            System.out.println("数据库加载失败");
        }
    }
    
    public DB() {
        try{

            if( connection == null || connection.isClosed() )
                    connection = DriverManager.getConnection(url, usr, psw);
             sqlStmt = (Statement) DB.connection.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE, 
                  java.sql.ResultSet.CONCUR_READ_ONLY);
        } catch(SQLException e){
            e.printStackTrace();
        }
    }
    
    //插入语句
    public void insert(String sql) throws SQLException{
        stmt = connection.prepareStatement(sql);
        stmt.executeUpdate();
    }
    
    //插入值
    public void insert(String table, String column, String val) throws SQLException{
        String sql = "insert " + table + "(" + column + ")" + " values(" + val +")";
        insert(sql);
    }
    //删除语句
    public void delete(String sql) throws SQLException{
        insert(sql);
    }
    
    //删除一个
    public void delete(String table, String id) throws SQLException{
        String sql = "delete from " + table + " where id = " + id;
        delete(sql);
    }
    
    public void delete_all(String table) throws SQLException{
        String sql = "delete from " + table;
        delete(sql);
    }
    
    //查询语句
    public ResultSet query(String sql) throws SQLException{
        return sqlStmt.executeQuery(sql);
    }
    
    //查询语句
    public ResultSet select(String column, String table, String val) throws SQLException{
        String sql = "select " + column + " from " + table + " where id = " + val;
        return sqlStmt.executeQuery(sql);  
    }
    
    public ResultSet select(String column, String table, String id, String val) throws SQLException{
        String sql = "select " + column + " from " + table + " where " + id + " = " + val;
        return query(sql);
    }

    //更新语句
    public void update(String sql) throws SQLException {
        insert(sql);
    }
    public void update(String table, String column, String id, String val) throws SQLException{
        String sql = "update " + table + " set " + column + " = '" + val + "' where id = " + id;
        insert(sql);
    }
    
    public int query_max_id(String table, String column) throws SQLException{
        String sql = "select max(" + column + ") from " + table;
        sqlRst = query(sql);
        while( sqlRst.next() )
            return sqlRst.getInt("max(" + column + ")");
        return 0;
    }
    
    public int query_num(String table, String str) throws SQLException{
        String sql = "select count(*) from " + table + " " + str;
        sqlRst = query(sql);
        while( sqlRst.next() )
            return sqlRst.getInt("count(*)");
        return 0;        
    }
    public int query_num(String table) throws SQLException{
        String sql = "select count(*) from " + table;
        sqlRst = query(sql);
        while( sqlRst.next() )
            return sqlRst.getInt("count(*)");
        return 0;   
    }
    public void close() throws SQLException{
        sqlStmt.close();
        connection.close();
    }

}