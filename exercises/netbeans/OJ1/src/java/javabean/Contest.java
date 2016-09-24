/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Time;
import java.sql.Timestamp;
import java.util.Date;

/**
 *
 * @author ZXY
 */
public class Contest {
    private String password, contestName = null, introduce;
    private Timestamp startTime, endTime;
    private Time length;
    private boolean right;

    public Contest() throws SQLException
    {
        String id = "1";
        ResultSet sqlRst = null;
        Statement sqlStmt = null;
        DB db = new DB();
        String sql = "select * from contest_info where id = " + id;
        sqlRst = db.query(sql);
        while( sqlRst.next() )
        {
            introduce = sqlRst.getString("introduce");
            contestName = sqlRst.getString("name");
            password = sqlRst.getString("password");
            length = sqlRst.getTime("length");
            startTime = sqlRst.getTimestamp("start_time");
            right = sqlRst.getBoolean("public");
            introduce = sqlRst.getString("introduce");
        }

        //时差么，囧，差8个小时
        if( contestName != null )
            endTime = new Timestamp(startTime.getTime() + length.getTime() + 28800000);
        db.close();
    }
    
    //删除一场比赛
    public static void delContest() throws SQLException{
        String id = "1";
        DB db = new DB();
        db.delete("contest_info", "1");
        db.close();
    }
    
    public String Status() {
        Date now = new Date();
        if( startTime.after(now) )
            return "Pending";
        if( endTime.before(now) )
            return "Ended";
        return "Running";
    }
    /**
     * @return the password
     */
    public String getPassword() {
        return password;
    }

    /**
     * @param password the password to set
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * @return the contestName
     */
    public String getContestName() {
        return contestName;
    }

    /**
     * @param contestName the contestName to set
     */
    public void setContestName(String contestName) {
        this.contestName = contestName;
    }

    /**
     * @return the introduce
     */
    public String getIntroduce() {
        return introduce;
    }

    /**
     * @param introduce the introduce to set
     */
    public void setIntroduce(String introduce) {
        this.introduce = introduce;
    }
    
    /**
     * @return the startTime
     */
    public Timestamp getStartTime() {
        return startTime;
    }

    /**
     * @param startTime the startTime to set
     */
    public void setStartTime(Timestamp startTime) {
        this.startTime = startTime;
    }

    /**
     * @return the length
     */
    public Time getLength() {
        return length;
    }

    /**
     * @param length the length to set
     */
    public void setLength(Time length) {
        this.length = length;
    }

    /**
     * @return the right
     */
    public boolean isRight() {
        return right;
    }

    /**
     * @param right the right to set
     */
    public void setRight(boolean right) {
        this.right = right;
    }

    /**
     * @return the endTime
     */
    public Timestamp getEndTime() {
        return endTime;
    }

    /**
     * @param endTime the endTime to set
     */
    public void setEndTime(Timestamp endTime) {
        this.endTime = endTime;
    }

}
