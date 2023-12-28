#include"../store/user.h"

int student_LinkList::getidentifier()
{//获取学生ID标识符
    return identifier;
}
int student_LinkList::get_studentid(char name[])
{//通过姓名获取学生ID
    student_Node *p = head->next;
    while(p != NULL)
    {
        if(strcmp(p->student_Name,name) == 0)
        {
            return p->student_ID;
        }
        p = p->next;
    }
    return 0;
}