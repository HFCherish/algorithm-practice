/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author ZXY
 */
public class Check {
    
    //检测session中的普通用户是否合法
    public static boolean check_user(String name) throws SQLException{
        DB db = new DB();
        String sql = "select id from users where name = \"" + name + "\"";
        ResultSet rst = db.query(sql);
        while( rst.next() ){
            db.close();
            return true;
        }
        db.close();
        return false;
    }
    
    //检测session中的管理员是否为管理员
    public static boolean check_admin(String name) throws SQLException{
        DB db = new DB();
        String sql = "select id from users where name = \"" + name + "\" and power = 1";
        ResultSet rst = db.query(sql);
        while( rst.next() ){
            db.close();
            return true;
        }
        db.close();
        return false;
    }
}
