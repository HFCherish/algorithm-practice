/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package service;

/**
 *
 * @author pz
 */
public class Mapping {
    
    /*
     * 根据代码测评结果id映射错误类型
     */
    public static String errorType(int resultId)
    {
        String result[] = {
            "Accepted",
            "Wrong Answer",
            "Time Limit Exceed",
            "Time Limit Exceed",
            "Time Limit Exceed",
            "Memory Limit Exceed",
            "Runtime Error",
            "Compile Error",
            "Output Limit Exceed",
            "Input Limit Exceed",
            "Presentation Error"};   
        return result[resultId];
    }
    
    /*
     * 根据用户代码语言ID映射代码语言类型
     */
    public static String languageType(int langID)
    {
        String lang[] = {"C++","C"};      
        return lang[langID];
    }
}
