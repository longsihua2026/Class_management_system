//��ɫ�����ܷ�Ϊѧ���͹���Ա����(ѧ���˺������Ա�˺ŷ���)
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
        role(std::string username="admin",std::string password="123456",int rule=1);//��ɫ��ʼ��
        // ~role();//����

        void test1();//����
        static void test2();//����2
        
        void sign_up();//ע��
        void sign_in();//��¼
        void sign_out();//ע��
        void change_password();//�޸�����
        void change_username();//�޸��û���
        // void change_rule();
        char* get_username();//��ȡ�û���
        char* get_password();//��ȡ����
        bool get_rule();//��ȡȨ��
        void read_role();//ͨ���ļ���ȡ��ɫ��Ϣ
        void write_role(std::string username,std::string password,int rule);//ͨ���ļ�д���ɫ��Ϣ
};
