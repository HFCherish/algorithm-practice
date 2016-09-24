/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import javabean.Announce;
import java.sql.SQLException;
import java.util.Arrays;
import java.util.Set;

/**
 *
 * @author ZXY
 */
public class showAnnounce {
    
    public static String showMsg() throws SQLException{
        String html = "";
        Announce ann = new Announce();
        Set set = ann.ann.entrySet();     
        Object[] key =  ann.ann.keySet().toArray();     
        Arrays.sort(key);     
        int ind = 1;
        for(int i = 0; i<key.length; i++)   
        {    
            html += "<tr><td width = 50px>" + (ind++) + "</td><td width = 500px>" + ann.ann.get(key[i]) + "</td>";
            html += "<td><a href=\"modifyAnn.jsp?id=" + key[i] + "\">" 
                    + "修改</a></td>";
            html += "<td><a href=\"deletAnn?id=" + key[i] + "\">" 
                    + "删除</a></td></tr>";  
        }  

        return html;
    }
   /*
    public static String showAdd(){
        Announce ann = new Announce();
        String html = "添加公告：";
    }
     */
    
}
