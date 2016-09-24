/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import javabean.Contest;
import java.sql.SQLException;

/**
 *
 * @author ZXY
 */
public class showContest {
    public static String showNow(String id,String url) throws SQLException{
         String html="";
         Contest contest = new Contest();
         if( contest.getContestName() == null ){
                html +="您好，本系统目前没有比赛，您可以发起一场比赛<br>";
               html+="<a href='"+url+"'>添加比赛</a>";
         }
         return html;
    }
    
    public  static String showIsRight(boolean flag){
        if(flag)
            return "Public";
        return "Private";
    }
    
    
    public static String showInfo(String id) throws SQLException{
        Contest contest = new Contest();
        if( contest.getContestName() == null ) return "";
        String html = "已经有一场比赛" + "<br>";
        html += "比赛名称为：" + contest.getContestName() + "<br>";
        html += "比赛权限为：";
        html += showIsRight(contest.isRight()) + "<br>";
        
        if( !contest.isRight() )
            html += "比赛密码：" + contest.getPassword() + "<br>";
        html += "比赛开始时间为：" + contest.getStartTime().toString() + "<br>"
               + "比赛持续时间为：" + contest.getLength().toString() + "<br>";
        return html;
    }
    
    public static String rightToChange(String delet, String modify) throws SQLException{
        Contest contest = new Contest();
        if( contest.getContestName() == null ) return "";
        String html = "";
        html += "<a href='" + delet + "'>删除本场比赛</a>;" + "<br>";
        html += "<a href='" + modify + "'>修改本场比赛信息</a>";
        return html;
                
    }
}

