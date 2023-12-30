//角色及功能分为学生和管理员两种(学生账号与管理员账号分离)
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
// #include <iomanip>
// #define admin 1
// #define other 2

#pragma once
class role
{
    private:
        int id;
        std::string username;
        std::string password;
        int rule;    
    public:
        role();//角色初始化,如果没有用户则创建一个admin用户
        // ~role();//析构
        
        static void read_role();//通过文件读取用户列表
        void write_role(std::string username,std::string password,int rule);//通过文件写入角色信息
        void create_user(std::string username="admin",std::string password="123456",int rule=1);//创建用户系统，初始用户为admin,123456。
        void sign_up();//注册
        int sign_in();//登录
        void sign_out();//注销
        void change_password();//修改密码
        // void change_rule();
        std::string get_username();//获取用户名
        std::string get_password();//获取密码
        bool get_rule();//获取权限
};
