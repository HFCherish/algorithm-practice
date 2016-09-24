/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import java.sql.ResultSet;
import java.sql.SQLException;
import javabean.DB;
import javabean.Format;
import javax.servlet.http.HttpSession;

/**
 *
 * @author ZXY
 */
public class showProblemSet {
    
    public static String showContestProblem(HttpSession session) throws SQLException{
        String html = "";
        DB db = new DB();
        int num = db.query_num("problems");
        String user = String.valueOf(session.getAttribute("username"));
        // 题目id从1开始
        for(int i=1; i<=num; i++){
            html += "<tr>";
            //Solved，从session里获得用户名然后取得
            html += "<td style=\"color:red\" >";
            //用的IN语句，虽然能查出来，不过效率？
            String sql = "select id from code where result = 0 and problem_id = " + i + " and user_id IN "
                    + "( select id from users where name = \"" + user + "\")";
            ResultSet rst = db.query(sql);
            while( rst.next() ) {
                html += "Yes";
                break;
            }
            html += "</td>";
            
            //Pro.id
            html += "<td>" + (char)(i + 'A' - 1) + "</td>";
            //Title
            sql = "select title from problems where id = " + i;
            rst = db.query(sql);
            while( rst.next() )
                html += "<td><a href=\"ProblemDetail.jsp?id=" + i + "&ConstID=" + (char)(i-1+'A') + "\">" 
                        + rst.getString("title") + "</a></td>";
            
            //Ratio，囧了个囧，还得计算，冤孽啊
            html += "<td>";
            int sum = db.query_num("code", "where problem_id = " + i);
            int ac = db.query_num("code", "where result = 0 and problem_id = " + i);
            // 需要控制显示小数点后两位
            html += (sum == 0 ? "0.00" : Format.Double(ac*100.0/sum, 2)) + "%(" + ac + "/" + sum + ")";
            html += "</td>";
            
            html += "</tr>";
        }
        db.close();
        return html;
    }
    
}
