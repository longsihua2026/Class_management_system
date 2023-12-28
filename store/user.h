//学生链表类
#include <iostream>
#include <string.h>


#pragma once
class student_LinkList
{
    private:
        struct student_Node
        {
            int  student_ID;//学生ID
            char student_Sex[20];//学生性别
            char student_Name[20];//学生姓名
            char student_number[20];//学生学号
            char student_phone[20];//学生电话
            char student_brithday[20];//学生生日
            char student_qq[20];//学生QQ
            char student_wechat[20];//学生微信
            char student_info[100];//学生简介
            int student_grade;//学生成绩
            student_Node *next;//指向下一个节点的指针
        }*head;//头指针
        int length;//链表长度
        int identifier;//学生ID标识符

    public:
        student_LinkList();//构造函数
        student_LinkList(char sex[],char name[],char phone[]);//构造函数
        ~student_LinkList();//析构函数

    /*学生操作函数*/
    public:
        void student_setinfo(int id,char info[]);//学生修改个人简介
        void student_setsex(int id,char sex[]);//学生修改性别
        // void student_setphone(int id,char phone[]);//学生修改手机号
        void student_setbrithday(int id,char brithday[]);//学生修改生日
        void student_setqq(int id,char qq[]);//学生修改QQ
        void student_setwechat(int id,char wechat[]);//学生修改微信

        void student_get(int id);//学生输出个人信息
        char* student_getgrade(int id);//学生获取成绩
        int student_getorder(int id);//学生获取排名
    
    /*管理员操作函数*/
    public:
        void admin_addstudent(char sex[],char name[],char phone[]);//管理员添加学生
        void admin_deletestudent(int id);//管理员删除学生
        void admin_setphone(int id,char phone[]);//管理员修改学生手机号
        void admin_setgrade(int id,int grade);//管理员修改学生成绩
        
        void admin_getstudentlist();//管理员获取学生列表
        void admin_orderstudentlist();//管理员获取学生排名列表
        void admin_getstudentinfo(int id);//管理员通过id获取学生信息
        void admin_getstudentinfo(char number[]);//管理员通过姓名获取学生信息
    
    /*链表操作函数*/
    public:
        student_Node* node_get(int id);//获取节点
        void node_insert(student_Node *p);//插入节点
        void list_delete(int id);//删除节点
        int getlength();//获取链表长度
        void top_insert(student_Node *p);//将某结点删去并插入头结点之后（用于排序）
        void order();//链表排序(成绩)
        void idorder();//链表按id排序
        int list_empty();//判断链表是否为空
    
    /*工具函数*/
    public:
        int getidentifier();//获取学生ID标识符
        int get_studentid(char name[]);//通过姓名获取学生ID

};