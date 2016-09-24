/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

import java.util.Date;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;

/**
 *
 * @author ZXY
 */
public class Format {
    
    //输出double后num位
    public static String Double(double val, int num) {
        String str = "%." + num + "f";
        System.out.println(str);
        return String.format(str, val);
    }
    
    //格式化为yyyy-MM-dd HH:mm:ss,大H是24小时制
    public static String YYMMDDHHMMSS(Timestamp time){
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        return sdf.format(time);
    }
    
    public static String YYMMDDHHMMSS(Date time){
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        return sdf.format(time);
    }
    
    //格式化输入字符串，防止恶意输入
    public static String html(String code){
        String html = "";
        int len = code.length();
        for(int i=0; i<len; i++){
            switch(code.charAt(i)){
                case ' '  : html += "&nbsp;";   break;
                case '\n' : html += "<br>";     break;
                case '<'  : html += "&lt;";     break;
                case '>'  : html += "&gt;";     break;
                case '&'  : html += "&amp;";    break;
                case '"'  : html += "&quot;";   break;
                case '\'' : html += "&apos;";   break;
                case '/'  : html += "&#47;";    break;
                case '\t' : html += "&nbsp;&nbsp;&nbsp;&nbsp;"; break;
                default : html += code.charAt(i);
            }
        }
        return html;
    }
}
