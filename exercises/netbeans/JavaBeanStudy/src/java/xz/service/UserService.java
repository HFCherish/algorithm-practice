/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package xz.service;

import xz.domain.User;
/**
 *
 * @author Administrator
 */
public class UserService {
    public static boolean CheckLogin(User user)
    {
        if(user.getName().equals("admin") && user.getPassword().equals("123456"))
        {
            return true;
        }
        return false;
    }
}
