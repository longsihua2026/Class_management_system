#include "user.h"

student_LinkList::student_LinkList()
{
    head = new student_Node;//ͷ���
    head->next = NULL;
    length = 0;
    identifier = 1;//ѧ��id���ɱ�ʶ��
    std::ifstream file("student.txt");
    if(!file)
        std::cout<<"�ð༶ѧ��Ϊ�գ�,���ȴ�����"<<std::endl;
    else
        file_create_student();
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
    /*����Ϣд���ļ�*/
    iofile_write_uend("student.txt",std::to_string(p->student_ID));
    iofile_write_uend("student.txt",p->student_Sex);
    iofile_write_uend("student.txt",p->student_Name);
    iofile_write_uend("student.txt",p->student_number);
    iofile_write_uend("student.txt",p->student_phone);
    iofile_write_uend("student.txt",p->student_brithday);
    iofile_write_uend("student.txt",p->student_qq);
    iofile_write_uend("student.txt",p->student_wechat);
    iofile_write_uend("student.txt",p->student_info);
    iofile_write_end("student.txt",std::to_string(p->student_grade));
}

void student_LinkList::file_create_student()
{//�����ļ��ж�ȡ����Ϣ��������
    std::string line;
    std::ifstream infile;
    infile.open("student.txt");
    while (std::getline(infile,line))           
    {
        std::istringstream iss(line);
        int file_id;
        std::string sex;
        std::string name;
        std::string number;
        std::string phone;
        std::string brithday;
        std::string qq;
        std::string wechat;
        std::string info;
        int grade;

        if(!(iss>>file_id>>sex>>name>>number>>phone>>brithday>>qq>>wechat>>info>>grade))
            break;
        //��ȡ�����ӽ����Ϣ����ѧ������
        student_Node *p;
        p = new student_Node;
        p->next = NULL;
        p->student_ID = file_id;
        identifier++;
        strcpy(p->student_Name,name.c_str());
        strcpy(p->student_number,number.c_str());
        strcpy(p->student_phone,phone.c_str());
        strcpy(p->student_Sex,sex.c_str());
        strcpy(p->student_brithday,brithday.c_str());
        strcpy(p->student_qq,qq.c_str());
        strcpy(p->student_wechat,wechat.c_str());
        strcpy(p->student_info,info.c_str());
        p->student_grade = grade;
        node_insert(p);
    }
    infile.close();
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
    file_insert("student.txt",id,info,"info");
    std::cout << "�޸ļ��ɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setsex(int id,char sex[])//ѧ���޸��Ա�
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_Sex,sex);
    file_insert("student.txt",id,sex,"sex");
    std::cout << "�޸��Ա�ɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setbrithday(int id,char brithday[])//ѧ���޸�����(���յ������ʽΪ"2003-01-15",������Դ˸�ʽ���ú���)
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_brithday,brithday);
    file_insert("student.txt",id,brithday,"brithday");
    std::cout << "�޸����ճɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setqq(int id,char qq[])//ѧ���޸�QQ
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_qq,qq);
    file_insert("student.txt",id,qq,"qq");
    std::cout << "�޸�QQ�ɹ�" << std::endl;
    return ;
}

void student_LinkList::student_setwechat(int id,char wechat[])//ѧ���޸�΢��
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_wechat,wechat);
    file_insert("student.txt",id,wechat,"wechat");
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
        std::cout << "��ĳɼ�:" <<"    |      "<< "���޳ɼ���ɼ��쳣" << std::endl;
    }
    else
    {
        std::cout << "��ĳɼ�:" <<"    |      "<< p->student_grade << std::endl;
    }
    return NULL;
}

int student_LinkList::student_getorder(int id)//ѧ����ȡ�Լ�������
{
    order();
    int i = 1;
    if (head->next == NULL)
    {
        std::cout << "�༶���л�û��ѧ��" << std::endl;
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
    std::cout<<"�������Ϊ��"<<i<<std::endl;
    return i;
}
