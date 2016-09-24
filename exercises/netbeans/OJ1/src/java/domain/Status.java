/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package domain;
import java.util.Date;
import service.Mapping;

/**
 *
 * @author pz
 */
public class Status {
    private int id;
    private int problem_id;
    private String user_name;
    private String result;
    private String language;
    private int run_time;
    private int run_memory;
    private int code_length;
    private Date submit_time;
    private String code;

    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * @return the problem_id
     */
    public int getProblem_id() {
        return problem_id;
    }

    /**
     * @param problem_id the problem_id to set
     */
    public void setProblem_id(int problem_id) {
        this.problem_id = problem_id;
    }


    /**
     * @return the result
     */
    public String getResult() {
        return result;
    }

    /**
     * @param result the result to set
     */
    public void setResult(int resultID) {
        this.result = Mapping.errorType(resultID);
    }


    /**
     * @return the run_time
     */
    public int getRun_time() {
        return run_time;
    }

    /**
     * @param run_time the run_time to set
     */
    public void setRun_time(int run_time) {
        this.run_time = run_time;
    }

    /**
     * @return the run_memory
     */
    public int getRun_memory() {
        return run_memory;
    }

    /**
     * @param run_memory the run_memory to set
     */
    public void setRun_memory(int run_memory) {
        this.run_memory = run_memory;
    }

    /**
     * @return the code_length
     */
    public int getCode_length() {
        return code_length;
    }

    /**
     * @param code_length the code_length to set
     */
    public void setCode_length(int code_length) {
        this.code_length = code_length;
    }

    /**
     * @return the submit_time
     */
    public Date getSubmit_time() {
        return submit_time;
    }

    /**
     * @param submit_time the submit_time to set
     */
    public void setSubmit_time(Date submit_time) {
        this.submit_time = submit_time;
    }

    /**
     * @return the code
     */
    public String getCode() {
        return code;
    }

    /**
     * @param code the code to set
     */
    public void setCode(String code) {
        this.code = code;
    }

    /**
     * @return the user_name
     */
    public String getUser_name() {
        return user_name;
    }

    /**
     * @param user_name the user_name to set
     */
    public void setUser_name(String user_name) {
        this.user_name = user_name;
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
    public void setLanguage(int langID) {
        this.language = Mapping.languageType(langID);
    }


 
    
}
