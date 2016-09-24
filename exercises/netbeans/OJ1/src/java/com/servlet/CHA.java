/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package com.servlet;
import java.util.Date;
import java.text.*;
import java.io.*;
import javabean.DB;
/**
 *
 * @author fookwood
 */
public class CHA {
    public static String getUsername(String userid){
        DB db = new DB();
        String ans="",sql = "SELECT username FROM users WHERE id = "+ userid;
        try{
            java.sql.ResultSet rs = db.query(sql);
            while( rs.next() ) {
                ans = rs.getString("username");
                break;
            }
            rs.close();
        }catch( Exception e){}
        return ans;
    }
    public static String getrunid(String time){
        DB db = new DB();
        String ans="",sql = "SELECT id FROM code WHERE submit_time = '" + time +"'";
        try{
            java.sql.ResultSet rs = db.query(sql);
            while( rs.next() ) {
                ans = rs.getString("id");
                break;
            }
            rs.close();
        }catch( Exception e){}
        return ans;
    }
    public static String DateToString() {
        String dateStr = "";
        java.util.Date date = new Date(); //
        try{
            SimpleDateFormat DF = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
            dateStr = DF.format(date);
        } catch (Exception e) {
            //out.print(e.toString());
        }
        return dateStr;
    }
    //
    public static void stringToFile(String id,String content,String path,String lang) {
        try{
            RandomAccessFile rf = new RandomAccessFile(path+"/codes/"+id+((lang.equals("0"))?".c":".cpp"),"rws");
            rf.seek(rf.length());
            rf.writeBytes(content+"\n");
            rf.close();
        }catch(Exception e){}
    }
    //
    public static String fileToString(String filePath) throws IOException {
        BufferedReader br = null;
        String ret = null;
        File file = new File(filePath);
        try {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath), "UTF-8"));
            String line = null;
            StringBuffer sb = new StringBuffer((int)file.length());
            while( (line = br.readLine() ) != null ) {
                sb.append(line);
            }
            ret = sb.toString();
        } finally {
            if(br!=null) {try{br.close();} catch(Exception e){} }
        }
        return ret;
    }
}
