/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javabean;

/**
 *
 * @author ZXY
 */
public class Status {
    private int run_id, time, memory, code_len;
    private String user, result, language, submit_time;
    private char problem_id;

    /**
     * @return the run_id
     */
    public int getRun_id() {
        return run_id;
    }

    /**
     * @param run_id the run_id to set
     */
    public void setRun_id(int run_id) {
        this.run_id = run_id;
    }

    /**
     * @return the time
     */
    public int getTime() {
        return time;
    }

    /**
     * @param time the time to set
     */
    public void setTime(int time) {
        this.time = time;
    }

    /**
     * @return the memory
     */
    public int getMemory() {
        return memory;
    }

    /**
     * @param memory the memory to set
     */
    public void setMemory(int memory) {
        this.memory = memory;
    }

    /**
     * @return the code_len
     */
    public int getCode_len() {
        return code_len;
    }

    /**
     * @param code_len the code_len to set
     */
    public void setCode_len(int code_len) {
        this.code_len = code_len;
    }

    /**
     * @return the user
     */
    public String getUser() {
        return user;
    }

    /**
     * @param user the user to set
     */
    public void setUser(String user) {
        this.user = user;
    }

    /**
     * @return the result
     */
    public String getResult() {
        return result;
    }
    
    public String getResult_color(){
        if( this.result.equals("Accepted") )
            return "style=\"color: red\"";
        return "";
    }
    /**
     * @param result the result to set
     */
    public void setResult(String result) {
        this.result = result;
        getResult_color();
    }

    /**
     * @return the language
     */
    public String getLanguage() {
        return language;
    }

    /**
     * @param language the language to set
     */
    public void setLanguage(String language) {
        this.language = language;
    }

    /**
     * @return the submit_time
     */
    public String getSubmit_time() {
        return submit_time;
    }

    /**
     * @param submit_time the submit_time to set
     */
    public void setSubmit_time(String submit_time) {
        this.submit_time = submit_time;
    }

    /**
     * @return the problem_id
     */
    public char getProblem_id() {
        return problem_id;
    }

    /**
     * @param problem_id the problem_id to set
     */
    public void setProblem_id(char problem_id) {
        this.problem_id = problem_id;
    }
}
