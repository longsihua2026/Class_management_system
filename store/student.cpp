#include "user.h"

student_LinkList::student_LinkList()
{
    head = new student_Node;//ͷ���
    head->next = NULL;
    length = 0;
    identifier = 1;//ѧ��id���ɱ�ʶ��
}
student_LinkList::student_LinkList(char sex[],char name[],char phone[])
{//���캯��
    student_Node *p;
    head = new student_Node;
    p = new student_Node;
    length = 1;
    identifier = 1;//ѧ��id���ɱ�ʶ��
    head->next = p;//ͷָ��ָ���һ���ڵ�
    p->next = NULL;
    p->student_ID = identifier;
    identifier++;
    strcpy(p->student_Name,name);
    const char* number_after = std::to_string(p->student_ID).c_str();
    char number_frint[]="2022211003000x";
    strcpy(p->student_number,strcat(number_frint,number_after));
    strcpy(p->student_Sex,sex);
    strcpy(p->student_phone,phone);
    strcpy(p->student_brithday,"2003-01-15");
    strcpy(p->student_qq,"123456789");
    strcpy(p->student_wechat,"123456789");
    strcpy(p->student_info,"����һ��ѧ��");
    p->student_grade = 0;
}

student_LinkList::~student_LinkList()
{
    student_Node *p = head;
    while (p != NULL)
    {
        student_Node *q = p->next;
        delete p;
        p = q;
    }
    std::cout << "ѧ������������" << std::endl;
}


void student_LinkList::student_setinfo(int id,char info[])//ѧ���޸ĸ��˼��
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_info,info);
    std::cout << "�޸ļ��ɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setsex(int id,char sex[])//ѧ���޸��Ա�
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_Sex,sex);
    std::cout << "�޸��Ա�ɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setbrithday(int id,char brithday[])//ѧ���޸�����(���յ������ʽΪ"2003-01-15",������Դ˸�ʽ���ú���)
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_brithday,brithday);
    std::cout << "�޸����ճɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setqq(int id,char qq[])//ѧ���޸�QQ
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_qq,qq);
    std::cout << "�޸�QQ�ɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setwechat(int id,char wechat[])//ѧ���޸�΢��
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_wechat,wechat);
    std::cout << "�޸�΢�ųɹ�" << std::endl;
    return ;
}

void student_LinkList::student_get(int id)//ѧ������Լ�������Ϣ
{
    student_Node *p;
    p = node_get(id);
    std::cout << "-----------------------------------------------------------------"<< std::endl;
    std::cout << "ѧ��ID:" <<"      |      "<< p->student_ID << std::endl;
    std::cout << "ѧ������:" <<"    |      "<< p->student_Name << std::endl;
    std::cout << "ѧ��ѧ��:" <<"    |      "<< p->student_number << std::endl;
    std::cout << "ѧ������:" <<"    |      "<< p->student_brithday << std::endl;
    std::cout << "ѧ���绰:" <<"    |      "<< p->student_phone << std::endl;
    std::cout << "ѧ��QQ:" <<"      |      "<< p->student_qq << std::endl;
    std::cout << "ѧ��΢��:" <<"    |      "<< p->student_wechat << std::endl;
    std::cout << "ѧ�����:" <<"    |      "<< p->student_info << std::endl;
    if (p->student_grade == 0)
    {
        std::cout << "ѧ���ɼ�:" <<"    |      "<< "���޳ɼ���ɼ��쳣" << std::endl;
    }
    else
    {
        std::cout << "ѧ���ɼ�:" <<"    |      "<< p->student_grade << std::endl;
    }
    std::cout << "-----------------------------------------------------------------"<< std::endl;
}



char* student_LinkList::student_getgrade(int id)//ѧ����ȡ�Լ��ĳɼ�
{
    student_Node *p;
    p = node_get(id);
    if (p->student_grade == 0)
    {
        std::cout << "ѧ���ɼ�:" <<"    |      "<< "���޳ɼ���ɼ��쳣" << std::endl;
    }
    else
    {
        std::cout << "ѧ���ɼ�:" <<"    |      "<< p->student_grade << std::endl;
    }
    return NULL;
}

int student_LinkList::student_getorder(int id)//ѧ����ȡ�Լ�������
{
    order();
    int i = 1;
    if (head->next == NULL)
    {
        std::cout << "�����л�û��ѧ��" << std::endl;
        return 0;
    }
    student_Node *p = head->next;
    while(p->student_ID != id || p == NULL)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        std::cout << "ѧ��������,��ȷ���������" << std::endl;
        return 0;
    }
    std::cout<<"��������Ϊ��"<<i<<std::endl;
    return i;
}
