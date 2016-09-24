/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package show;

import javabean.Page;

/**
 *
 * @author ZXY
 */
public class showPage {
    
    public static String show(String url, Page curpage) {
        
        String html = "";
        int sum = curpage.getSumPage();
        for(int i=1; i<=sum; i++){
            html += "<a href=\"" + url + "page=" + i + "\"";
            if( i == curpage.getCurPage() )
                html += " style=\"font-weight: bold\"";
            html += ">[" + i + "]</a>"; 
        }
        return html;
    }
    
    public static void main(String[] args){
        Page curpage = new Page();
        curpage.init(1, 10, 3);
        System.out.print(show("lala.jsp", curpage));
    }
}
