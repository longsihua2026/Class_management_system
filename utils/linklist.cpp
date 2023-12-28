#include "../store/user.h"

    student_LinkList::student_Node* student_LinkList::node_get(int id)
    {//��ȡ�ڵ�
        int i = id;
        student_Node *p = head;
        if (i > length)
        {
            std::cout << "ѧ��������,��ȷ���������" << std::endl;
            return NULL;
        }
        while (i--)
        {
            p = p->next;
        }
        return p;
    }
    void student_LinkList::node_insert(student_Node *p)
    {//��ͷ�������ڵ�(����Ϊ��㣬��װ�غô������ָ��)
        p->next = head->next;
        head->next = p;
        length++;
    }
    void student_LinkList::list_delete(int id)
    {//ɾ���ڵ�
        int i = id;
        student_Node *p = head,*q;
        while(i--)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        length--;
    }
    int student_LinkList::getlength()
    {//��ȡ������
        return length;
    }
    void student_LinkList::top_insert(student_Node *p)
    {//��ĳ���󷽽��ɾȥ������ͷ������
        student_Node *q = p->next;
        p->next = q->next;
        length--;
        node_insert(q);
    }
  
    void student_LinkList::order()
    {//�������򣨸��ݳɼ�����)
        int min = 999999;
        student_Node *p = head->next,*q,*fr,*fpnode=head;//��������������q���бȽ��ҵ���С��㣬r��¼��С��㣬fr��¼��С����ǰ����㡣
        for(int i = 1;i <= length;i++)
        {
            while(p != NULL)
            {
                q = p;
                if(q->student_grade < min)
                {
                    min = q->student_grade;
                    fr = fpnode;
                }
                p = p->next;
                fpnode = fpnode->next;
            }
            top_insert(fr);//������Ҫ��������ǰһ��λ��ָ�룬�������뵽ͷ������
            min = 999999;
            p = head->next;
            fpnode = head;
            for(int j=i;j>0;j--)
            {
                p = p->next;
                fpnode = fpnode->next;
            }
        }       
    }

    void student_LinkList::idorder()
    {//�������򣨸��ݳɼ�����)
        int max = 0;
        student_Node *p = head->next,*q,*fr,*fpnode=head;//��������������q���бȽ��ҵ���С��㣬r��¼��С��㣬fr��¼��С����ǰ����㡣
        for(int i = 1;i <= length;i++)
        {
            while(p != NULL)
            {
                q = p;
                if(q->student_ID > max)
                {
                    max = q->student_ID;
                    fr = fpnode;
                }
                p = p->next;
                fpnode = fpnode->next;
            }
            top_insert(fr);//������Ҫ��������ǰһ��λ��ָ�룬�������뵽ͷ������
            max = 0;
            p = head->next;
            fpnode = head;
            for(int j=i;j>0;j--)
            {
                p = p->next;
                fpnode = fpnode->next;
            }
        }       
    }

    int student_LinkList::list_empty()
    {//�ж������Ƿ�Ϊ��
        if(head->next == NULL)
            return 1;
        else
            return 0;
    }



