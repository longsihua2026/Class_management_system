#include "user.h"

student_LinkList::student_LinkList()
{
    head = new student_Node;//头结点
    head->next = NULL;
    length = 0;
    identifier = 1;//学生id生成标识符
}
student_LinkList::student_LinkList(char sex[],char name[],char phone[])
{//构造函数
    student_Node *p;
    head = new student_Node;
    p = new student_Node;
    length = 1;
    identifier = 1;//学生id生成标识符
    head->next = p;//头指针指向第一个节点
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
    strcpy(p->student_info,"这是一个学生");
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
    std::cout << "学生链表已销毁" << std::endl;
}


void student_LinkList::student_setinfo(int id,char info[])//学生修改个人简介
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_info,info);
    std::cout << "修改简介成功" << std::endl;
    return ;
}

void student_LinkList::student_setsex(int id,char sex[])//学生修改性别
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_Sex,sex);
    std::cout << "修改性别成功" << std::endl;
    return ;
}

void student_LinkList::student_setbrithday(int id,char brithday[])//学生修改生日(生日的输入格式为"2003-01-15",键入后以此格式调用函数)
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_brithday,brithday);
    std::cout << "修改生日成功" << std::endl;
    return ;
}

void student_LinkList::student_setqq(int id,char qq[])//学生修改QQ
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_qq,qq);
    std::cout << "修改QQ成功" << std::endl;
    return ;
}

void student_LinkList::student_setwechat(int id,char wechat[])//学生修改微信
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_wechat,wechat);
    std::cout << "修改微信成功" << std::endl;
    return ;
}

void student_LinkList::student_get(int id)//学生输出自己所有信息
{
    student_Node *p;
    p = node_get(id);
    std::cout << "-----------------------------------------------------------------"<< std::endl;
    std::cout << "学生ID:" <<"      |      "<< p->student_ID << std::endl;
    std::cout << "学生姓名:" <<"    |      "<< p->student_Name << std::endl;
    std::cout << "学生学号:" <<"    |      "<< p->student_number << std::endl;
    std::cout << "学生生日:" <<"    |      "<< p->student_brithday << std::endl;
    std::cout << "学生电话:" <<"    |      "<< p->student_phone << std::endl;
    std::cout << "学生QQ:" <<"      |      "<< p->student_qq << std::endl;
    std::cout << "学生微信:" <<"    |      "<< p->student_wechat << std::endl;
    std::cout << "学生简介:" <<"    |      "<< p->student_info << std::endl;
    if (p->student_grade == 0)
    {
        std::cout << "学生成绩:" <<"    |      "<< "暂无成绩或成绩异常" << std::endl;
    }
    else
    {
        std::cout << "学生成绩:" <<"    |      "<< p->student_grade << std::endl;
    }
    std::cout << "-----------------------------------------------------------------"<< std::endl;
}



char* student_LinkList::student_getgrade(int id)//学生获取自己的成绩
{
    student_Node *p;
    p = node_get(id);
    if (p->student_grade == 0)
    {
        std::cout << "学生成绩:" <<"    |      "<< "暂无成绩或成绩异常" << std::endl;
    }
    else
    {
        std::cout << "学生成绩:" <<"    |      "<< p->student_grade << std::endl;
    }
    return NULL;
}

int student_LinkList::student_getorder(int id)//学生获取自己的排名
{
    order();
    int i = 1;
    if (head->next == NULL)
    {
        std::cout << "链表当中还没有学生" << std::endl;
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
        std::cout << "学生不存在,请确认输入情况" << std::endl;
        return 0;
    }
    std::cout<<"该生排名为："<<i<<std::endl;
    return i;
}
