/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

/**
 *
 * @author ZXY
 */
public class TypeMap {
    
    public static int result_num = 10;
    public static int lang_num = 3;
    public static String Result(int ind){
        ind++;
        String result[] = {
            "Processing",
            "Accepted",
            "Wrong Answer",
            "Time Limit Exceeded",
            "Memory Limit Exceeded",
            "Runtime Error",
            "Compilation Error",
            "Output Limit Exceeded",
            "Input Limit Exceeded",
            "Presentation Error"};  
        return result[ind];
    }
    
    public static String Language(int ind){
        int num = 3;
        String result[] = {"C", "C++", "Java"};
        return result[ind];
    }
    
    public static String Right(boolean right){
        if( right ) return "Public";
        return "Private";
    }
}
