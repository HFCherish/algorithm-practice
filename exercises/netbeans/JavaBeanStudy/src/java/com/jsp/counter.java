/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
package com.jsp;
public class counter {
    private int count = 0;
    public counter()
    {}

    /**
     * @return the count
     */
    public int getCount() {
        count ++;
        return count;
    }

    /**
     * @param count the count to set
     */
    public void setCount(int count) {
        this.count = count;
    }
}
