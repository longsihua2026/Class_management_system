#include "../store/user.h"

    student_LinkList::student_Node* student_LinkList::node_get(int id)
    {//获取节点
        int i = id;
        student_Node *p = head;
        if (i > length)
        {
            std::cout << "学生不存在,请确认输入情况" << std::endl;
            return NULL;
        }
        while (i--)
        {
            p = p->next;
        }
        return p;
    }
    void student_LinkList::node_insert(student_Node *p)
    {//在头结点后插入节点(参数为结点，需装载好传入参数指针)
        p->next = head->next;
        head->next = p;
        length++;
    }
    void student_LinkList::list_delete(int id)
    {//删除节点
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
    {//获取链表长度
        return length;
    }
    void student_LinkList::top_insert(student_Node *p)
    {//将某结点后方结点删去插入在头结点后面
        student_Node *q = p->next;
        p->next = q->next;
        length--;
        node_insert(q);
    }
  
    void student_LinkList::order()
    {//链表排序（根据成绩排序)
        int min = 999999;
        student_Node *p = head->next,*q,*fr,*fpnode=head;//用来计数结束，q进行比较找到最小结点，r记录最小结点，fr记录最小结点的前驱结点。
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
            top_insert(fr);//传入需要交换结点的前一个位置指针，将结点插入到头结点后面
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
    {//链表排序（根据成绩排序)
        int max = 0;
        student_Node *p = head->next,*q,*fr,*fpnode=head;//用来计数结束，q进行比较找到最小结点，r记录最小结点，fr记录最小结点的前驱结点。
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
            top_insert(fr);//传入需要交换结点的前一个位置指针，将结点插入到头结点后面
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
    {//判断链表是否为空
        if(head->next == NULL)
            return 1;
        else
            return 0;
    }



