/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Time;
import java.sql.Timestamp;
import javabean.Contest;
import javabean.DB;
import javabean.Page;

/**
 *
 * 显示ranklist除表格外的东西
 * 
 * @author ZXY
 */
public class showRanklist {
    
    public static String showRank(Page curpage) throws SQLException{
        if( curpage.getSumRow() == 0 )
            return "";
        Contest contest = new Contest();
        DB db = new DB();
        String html = "";
        //别把管理员也弄上去 囧
        String sql = "select id, nickname, solved, total_time from users where power = 0 order by solved DESC,"
                + "total_time ASC";
        int num = db.query_max_id("problems", "id");
        
        int start = curpage.getStart();
        int end = curpage.getEnd();

        ResultSet sqlRst = null;
        sqlRst = db.query(sql);
        if( start != 1 )
            sqlRst.absolute(start-1);
        int rank = start;
        DB db1 = new DB();
        DB db2 = new DB();
        while( start++ <= end && sqlRst.next() ) {
            if( rank % 2 == 0 )
                html += "<tr class=\"even\">";
            else
                html += "<tr class=\"odd\">";
            html += "<td>" + (rank++) + "</td>";
            String name = sqlRst.getString("nickname");
            int id          = sqlRst.getInt("id");
            int solved      = sqlRst.getInt("solved");
            Time total_time  = sqlRst.getTime("total_time");
            
            html += "<td>" + name       + "</td>";
            html += "<td>" + solved     + "</td>";
            html += "<td>" + total_time.toString() + "</td>";
            for(int i=1; i<=num; i++) {
                sql = "select submit_time from code where user_id = " + id + " and result = 0 "
                        + " and problem_id = " + i + " order by submit_time ASC";
                
                ResultSet tmp = db1.query(sql);
                Timestamp time = new Timestamp(System.currentTimeMillis());
               
                boolean ac = false;
                while( tmp.next() )
                {
                    ac = true;
                    time = tmp.getTimestamp(1);
                    break;
                }
                sql = "select count(*) from code where user_id = " + id + " and problem_id = " + i 
                        + " and submit_time <= \"" + time + "\"";
                
                tmp = db2.query(sql);
                int cnt = 1;
                while( tmp.next() ){
                    cnt = tmp.getInt("count(*)");
                }
                if( ac ){
                    html += "<td bgcolor=\"lightgreen\">";
                    Time t = new Time(time.getTime() - contest.getStartTime().getTime());
                    html += t.toString();
                    if( cnt != 1 )
                        html += "<br>(" + -(cnt-1) + ")";
                }
                else {
                    if( cnt != 0 )
                        html += "<td bgcolor=\"red\">";
                    else
                        html += "<td>";
                    if( cnt != 0 )
                        html += -cnt;
                }
                
                html += "</td>";
            }
            html += "</tr>";
        }
        db1.close();
        db2.close();
        db.close();
        return html;
    }
    
    public static void main(String[] args) throws SQLException{
        Page curpage = new Page();
        curpage.init(1, 8, 3);
        curpage.setCurPage(1);
        System.out.println(showRanklist.showRank( curpage ));
    }
    
}
