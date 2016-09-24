/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Time;

/**
 *
 * @author ZXY
 */
public class User {
    
    private int solved;
    private Time time;
    
    public User(int id, int num) throws SQLException{
        DB db = new DB();
        String sql = "select DISTINCT problem_id from code where user_id = " + id + " and result = 0";
        ResultSet sqlRst = db.query(sql);
        sqlRst.last();
        solved = sqlRst.getRow();
        sql = "select total_time from users where id = " + id;
        sqlRst = db.query(sql);
        while( sqlRst.next() )
            time = sqlRst.getTime(1);
        
        db.close();
    }
}
