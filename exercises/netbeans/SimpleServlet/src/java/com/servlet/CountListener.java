/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

/**
 * Web application lifecycle listener.
 * @author Administrator
 */
public class CountListener implements ServletContextListener {
    String path = "";
    public void contextInitialized(ServletContextEvent sce) {
        CounterFile f = new CounterFile();
        String name = sce.getServletContext().getInitParameter("CounterPath");
        path = sce.getServletContext().getRealPath(name);
        try
        {
            String temp = f.ReadFile(path);
            System.out.println(temp);
            sce.getServletContext().setAttribute("Counter", temp);
        }catch(Exception e){
            System.out.println(e.toString());
        }
    }

    public void contextDestroyed(ServletContextEvent sce) {
        try
        {
            String current = (String)sce.getServletContext().getAttribute("Counter");
            CounterFile f = new CounterFile();
            f.WriteFile(path, current);
        }catch(Exception e){
            System.out.println(e.toString());
        }
    }
}
