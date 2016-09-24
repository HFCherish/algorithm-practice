/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import javabean.DB;
import javabean.Format;
import javabean.Page;
import javabean.Status;
import javabean.TypeMap;

/**
 *
 * @author ZXY
 */
public class showStatus {
    
    public static List showStatu(Page curpage, String sql, boolean admin) throws SQLException{
        
        DB db = new DB();
        DB db1 = new DB();
        int start = curpage.getStart();
        int end = curpage.getEnd();
        ResultSet sqlRst = null;
        sqlRst = db.query(sql);
        if( start != 1 )
            sqlRst.absolute(start-1);
        
        List array = new ArrayList();
        
        while( start++ <= end && sqlRst.next() ) {
            
            Status st = new Status();
            int run_id = sqlRst.getInt("id");
            int user_id = sqlRst.getInt("user_id");
            //根据user_id 获得用户昵称
            sql = "select nickname from users where id = " + user_id;
            ResultSet rst = db1.query(sql);
            rst.absolute(1);
            String nickname = rst.getString("nickname");
            
            char problem_id = (char) (sqlRst.getInt("problem_id") + 'A' - 1);
            String result = TypeMap.Result(sqlRst.getInt("result"));
            String language = TypeMap.Language(sqlRst.getInt("language"));
            if( admin )
                language = "<a href=\"Code.jsp?run_id=" + run_id + "\">" + language + "</a>";
            int time = sqlRst.getInt("run_time");
            int memory = sqlRst.getInt("run_memory");
            int code_len = sqlRst.getInt("code_length");
            
            st.setRun_id(run_id);
            st.setUser(nickname);
            st.setProblem_id(problem_id);
            st.setTime(time);
            st.setMemory(memory);
            st.setCode_len(code_len);
            st.setResult(result);
            st.setLanguage(language);
            st.setSubmit_time(Format.YYMMDDHHMMSS(sqlRst.getTimestamp("submit_time")));
            array.add(st);
            
        }
        
        db.close();
        db1.close();
        return (List) array;
    }
    
}
