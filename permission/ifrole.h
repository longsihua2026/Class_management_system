//��ɫ�����ܷ�Ϊѧ���͹���Ա����(ѧ���˺������Ա�˺ŷ���)
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
        role();//��ɫ��ʼ��,���û���û��򴴽�һ��admin�û�
        // ~role();//����
        
        static void read_role();//ͨ���ļ���ȡ�û��б�
        void write_role(std::string username,std::string password,int rule);//ͨ���ļ�д���ɫ��Ϣ
        void create_user(std::string username="admin",std::string password="123456",int rule=1);//�����û�ϵͳ����ʼ�û�Ϊadmin,123456��
        void sign_up();//ע��
        int sign_in();//��¼
        void sign_out();//ע��
        void change_password();//�޸�����
        // void change_rule();
        std::string get_username();//��ȡ�û���
        std::string get_password();//��ȡ����
        bool get_rule();//��ȡȨ��
};
