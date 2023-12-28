//角色及功能分为学生和管理员两种(学生账号与管理员账号分离)
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
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
        role(std::string username="admin",std::string password="123456",int rule=1);//角色初始化
        // ~role();//析构

        void test1();//测试
        static void test2();//测试2
        
        void sign_up();//注册
        void sign_in();//登录
        void sign_out();//注销
        void change_password();//修改密码
        void change_username();//修改用户名
        // void change_rule();
        char* get_username();//获取用户名
        char* get_password();//获取密码
        bool get_rule();//获取权限
        void read_role();//通过文件读取角色信息
        void write_role(std::string username,std::string password,int rule);//通过文件写入角色信息
};
