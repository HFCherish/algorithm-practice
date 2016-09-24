/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import java.sql.ResultSet;
import java.sql.SQLException;
import javabean.DB;

/**
 * 
 *显示Statistics 除标题外的表格
 * 
 * @author ZXY
 */
public class showStatistics {
    
    public static String showStatic() throws SQLException{
        
        DB db = new DB();
        String html = "";
        
        int num = db.query_max_id("problems", "id");
        
        for(int i=0; i<num; i++) {
            int sum = 0;
            html += "<tr>";
            html += "<td>" + (char)('A'+i) + "</td>";
            for(int k=0; k<=8; k++) {
                String sql = "select count(*) from code where problem_id = " + i
                        + " and result = " + k;
                ResultSet sqlRst = db.query(sql);
                while( sqlRst.next() )
                {
                    int cnt = sqlRst.getInt("count(*)");
                    html += "<td>" + cnt + "</td>";
                    sum += cnt;
                }
            }
            html += "<td>" + sum + "</td></tr>";
        }
        db.close();
        return html;
    }
    
    public static void main(String[] args) throws SQLException{
        System.out.println(showStatic());
    }
}
