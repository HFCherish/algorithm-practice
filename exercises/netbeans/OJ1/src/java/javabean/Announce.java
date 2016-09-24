/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author ZXY
 */
//db: id, msg
public class Announce {
    private int num;
    public Map<Integer, String> ann = new HashMap<Integer, String>();
    
    public Announce() throws SQLException{
        DB db = new DB();
        num = db.query_num("announcement");
        ResultSet sqlRst = db.query("select * from announcement order by id");
        while( sqlRst.next() )
        {
            int ind = sqlRst.getInt("id");
            String msg = sqlRst.getString("content");
            ann.put(ind, msg);
        }
        db.close();
    }
    
    public String getMsg(int ind){
        return (String) ann.get(ind);
    }
    
    public static void update(String ind, String msg) throws SQLException{
        DB db = new DB();
        db.update("announcement", "content", ind, msg);
        db.close();
    }
    public static void clear() throws SQLException{
        DB db = new DB();
        db.delete_all("announcement");
        db.close();
    }
    
    public void add(String msg) throws SQLException{
        DB db = new DB();
        db.insert("announcement", "content", "\'" + msg + "\'");
        db.close();
    }
    
    public static void delete(String id) throws SQLException{
        DB db = new DB();
        db.delete("announcement", id+"");
        db.close();
    }

    /**
     * @return the num
     */
    public int getNum() {
        return num;
    }

    /**
     * @param num the num to set
     */
    public void setNum(int num) {
        this.num = num;
    }
}
