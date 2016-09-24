/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

/**
 * Web application lifecycle listener.
 * @author Administrator
 */
public class SessionListener implements HttpSessionListener {

    public void sessionCreated(HttpSessionEvent se) {
        //修改在线人数
       String current = (String)se.getSession().getServletContext().getAttribute("online");
       if(current == null)   current = "0";
       int c = Integer.parseInt(current);
       c++;
       current = String.valueOf(c);
       se.getSession().getServletContext().setAttribute("online",current);
       //修改历史人数
       String his = (String)se.getSession().getServletContext().getAttribute("Counter");
       if(his == null) his = "0";
       int total = Integer.parseInt(his) + 1;
       his = String.valueOf(total);
       se.getSession().getServletContext().setAttribute("Counter", his);
    }

    public void sessionDestroyed(HttpSessionEvent se) {
        //修改在线人数
        String current = (String)se.getSession().getServletContext().getAttribute("online");
        if(current == null) current = "0";
        int c = Integer.parseInt(current);
        c--;
        current = String.valueOf(c);
        se.getSession().getServletContext().setAttribute("online", current);
    }
}
