//ѧ��������
#include <iostream>
#include <string.h>


#pragma once
class student_LinkList
{
    private:
        struct student_Node
        {
            int  student_ID;//ѧ��ID
            char student_Sex[20];//ѧ���Ա�
            char student_Name[20];//ѧ������
            char student_number[20];//ѧ��ѧ��
            char student_phone[20];//ѧ���绰
            char student_brithday[20];//ѧ������
            char student_qq[20];//ѧ��QQ
            char student_wechat[20];//ѧ��΢��
            char student_info[100];//ѧ�����
            int student_grade;//ѧ���ɼ�
            student_Node *next;//ָ����һ���ڵ��ָ��
        }*head;//ͷָ��
        int length;//������
        int identifier;//ѧ��ID��ʶ��

    public:
        student_LinkList();//���캯��
        student_LinkList(char sex[],char name[],char phone[]);//���캯��
        ~student_LinkList();//��������

    /*ѧ����������*/
    public:
        void student_setinfo(int id,char info[]);//ѧ���޸ĸ��˼��
        void student_setsex(int id,char sex[]);//ѧ���޸��Ա�
        // void student_setphone(int id,char phone[]);//ѧ���޸��ֻ���
        void student_setbrithday(int id,char brithday[]);//ѧ���޸�����
        void student_setqq(int id,char qq[]);//ѧ���޸�QQ
        void student_setwechat(int id,char wechat[]);//ѧ���޸�΢��

        void student_get(int id);//ѧ�����������Ϣ
        char* student_getgrade(int id);//ѧ����ȡ�ɼ�
        int student_getorder(int id);//ѧ����ȡ����
    
    /*����Ա��������*/
    public:
        void admin_addstudent(char sex[],char name[],char phone[]);//����Ա���ѧ��
        void admin_deletestudent(int id);//����Աɾ��ѧ��
        void admin_setphone(int id,char phone[]);//����Ա�޸�ѧ���ֻ���
        void admin_setgrade(int id,int grade);//����Ա�޸�ѧ���ɼ�
        
        void admin_getstudentlist();//����Ա��ȡѧ���б�
        void admin_orderstudentlist();//����Ա��ȡѧ�������б�
        void admin_getstudentinfo(int id);//����Աͨ��id��ȡѧ����Ϣ
        void admin_getstudentinfo(char number[]);//����Աͨ��������ȡѧ����Ϣ
    
    /*�����������*/
    public:
        student_Node* node_get(int id);//��ȡ�ڵ�
        void node_insert(student_Node *p);//����ڵ�
        void list_delete(int id);//ɾ���ڵ�
        int getlength();//��ȡ������
        void top_insert(student_Node *p);//��ĳ���ɾȥ������ͷ���֮����������
        void order();//��������(�ɼ�)
        void idorder();//����id����
        int list_empty();//�ж������Ƿ�Ϊ��
    
    /*���ߺ���*/
    public:
        int getidentifier();//��ȡѧ��ID��ʶ��
        int get_studentid(char name[]);//ͨ��������ȡѧ��ID

};