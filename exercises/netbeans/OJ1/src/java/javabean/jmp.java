/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

/**
 *
 * @author ZXY
 */
public class jmp {
    public static String to(String str, int second){
         return ("<meta  http-equiv=refresh  content=" + second 
                 + ";URL=" + str + ">");  
    }
}
