/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import domain.Status;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import javabean.DB;



/**
 *
 * @author pz
 */
public class StatusDao {
    DB db = new DB();    
    
    /*
     * 用于后台，从数据库中查询所有用户提交代码的status
     */
    public List findAllStatus() throws SQLException     
    {
        List list = new ArrayList();
        String listSQL = "select * from code";
        try
        {
            ResultSet rs = db.query(listSQL);
            while(rs.next())
            {
                Status code = new Status();
                code.setId(rs.getInt(1));
                code.setProblem_id(rs.getInt(2));
                ResultSet name = db.select("nickname", "user", Integer.toString(rs.getInt(3)));
                code.setUser_name(name.getString(4));
                code.setRun_time(rs.getInt(4));
                code.setRun_memory(rs.getInt(5));
                code.setCode_length(rs.getInt(6));
                code.setSubmit_time(rs.getDate(7));
                code.setLanguage(rs.getInt(8));
                code.setResult(rs.getInt(9));
                code.setCode(rs.getString(10));
                list.add(code);
            }
            DB.connection.commit();
            db.close();
            return list;
        }catch(Exception e)
        {
        }finally
        {
            if(DB.connection != null) 
                try
                {
                    db.close();
                }catch(SQLException e)
                {
                }
        }
        return list;
    }
    
    /*
     * 用于前台，从数据库中查询当前用户提交代码的status
     */
    public List findSelfStatus(int userID) throws SQLException
    {
        List list = new ArrayList();
        String listSQL = "select * from code where user_id = " + userID;
            ResultSet rs = db.query(listSQL);
            while(rs.next())
            {
                Status code = new Status();
                code.setId(rs.getInt(1));
                code.setProblem_id(rs.getInt(2));
                ResultSet name = db.select("nickname", "user", Integer.toString(userID));
                code.setUser_name(name.getString(4));
                code.setRun_time(rs.getInt(4));
                code.setRun_memory(rs.getInt(5));
                code.setCode_length(rs.getInt(6));
                code.setSubmit_time(rs.getDate(7));
                code.setLanguage(rs.getInt(8));
                code.setResult(rs.getInt(9));
                list.add(code);
            }
            DB.connection.commit();
            db.close();
        return list;
    }
}
