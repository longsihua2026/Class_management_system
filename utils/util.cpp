#include"../store/user.h"

int student_LinkList::getidentifier()
{//��ȡѧ��ID��ʶ��
    return identifier;
}
int student_LinkList::get_studentid(char name[])
{//ͨ��������ȡѧ��ID
    student_Node *p = head->next;
    while(p != NULL)
    {
        if(strcmp(p->student_Name,name) == 0)
        {
            return p->student_ID;
        }
        p = p->next;
    }
    std::cout<<"�˰༶û�д�ѧ������ȷ�Ϻ��ٵ�¼��"<<std::endl;
    // exit(0);
    return 0;
}