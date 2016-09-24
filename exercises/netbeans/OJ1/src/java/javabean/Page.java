/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

/**
 *
 * @author ZXY
 */
public class Page {
    private int curPage;    //当前是第几页
    private int sumPage;    //总页数
    private int sumRow;     //总行数
    private int ROW;        //显示每页显示多少行
    private int start;      //当前页的起始行
    private int end;        //当前页终止页
    
    //初始化，当前页面，总的行数，每一页显示多少行
    public void init(int curPage, int sumRow, int ROW){
        this.sumRow = sumRow;
        this.ROW = ROW;
        this.sumPage = (int)Math.ceil(sumRow*1.0/ROW);
        setCurPage(curPage);
    }
    /**
     * @return the curPage
     */
    public int getCurPage() {
        return curPage;
    }

    /**
     * @param curPage the curPage to set
     */
    public void setCurPage(int curPage) {
        this.curPage = curPage;
        setStart();
        setEnd();
    }

    /**
     * @return the sumPage
     */
    public int getSumPage() {
        return sumPage;
    }

    /**
     * @param sumPage the sumPage to set
     */
    public void setSumPage(int sumPage) {
        this.sumPage = sumPage;
    }

    /**
     * @return the ROW
     */
    public int getROW() {
        return ROW;
    }

    /**
     * @param ROW the ROW to set
     */
    public void setROW(int ROW) {
        this.ROW = ROW;
    }

    /**
     * @return the start
     */
    public int getStart() {
        return start;
    }

    /**
     * @param start the start to set
     */
    public void setStart() {
        this.start = (curPage - 1) * ROW + 1;
    }

    /**
     * @return the end
     */
    public int getEnd() {
        return end;
    }

    /**
     * @param end the end to set
     */
    public void setEnd() {
        if( curPage == sumPage )
            this.end = sumRow;
        else
            this.end = curPage * ROW;
    }

    /**
     * @return the sumRow
     */
    public int getSumRow() {
        return sumRow;
    }

    /**
     * @param sumRow the sumRow to set
     */
    public void setSumRow(int sumRow) {
        this.sumRow = sumRow;
    }
    
}
