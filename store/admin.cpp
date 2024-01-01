#include "user.h"

void student_LinkList::admin_addstudent(char sex[],char name[],char phone[])
{//����Ա���ѧ��
    student_Node *p;
    p = new student_Node;
    p->next = NULL;
    p->student_ID = identifier;
    identifier++;
    strcpy(p->student_Name,name);
    const char* number_after = std::to_string(p->student_ID).c_str();
    char number_frint[]="2022211003000x";
    strcpy(p->student_number,strcat(number_frint,number_after));
    strcpy(p->student_phone,phone);
    strcpy(p->student_Sex,sex);
    strcpy(p->student_brithday,"2003-01-15");
    strcpy(p->student_qq,"123456789");
    strcpy(p->student_wechat,"123456789");
    strcpy(p->student_info,"����һ��ѧ��");
    p->student_grade = 0;
    node_insert(p);
    // std::cout << "���ѧ���ɹ�" << std::endl;
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
void student_LinkList::admin_addstudent_csv(std::string filename)
{
    std::string line;
    std::ifstream infile;
    infile.open(filename);
    if(!infile)
    {
        std::cout << "�ļ���ʧ��" << std::endl;
        exit(0);
    }
    while (std::getline(infile,line))           
    {
        std::istringstream iss(line);
        std::string sex;
        std::string name;
        std::string number;
        std::string phone;
        std::string brithday;
        std::string qq;
        std::string wechat;
        std::string info;
        std::string grade_str;
        int grade;

        std::getline(iss,name,',');
        std::getline(iss,sex,',');
        std::getline(iss,number,',');
        std::getline(iss,phone,',');
        std::getline(iss,brithday,',');
        std::getline(iss,qq,',');
        std::getline(iss,wechat,',');
        std::getline(iss,info,',');
        std::getline(iss,grade_str,',');
        grade = std::stoi(grade_str);
        
        
        //��ȡ�����ӽ����Ϣ����ѧ������
        student_Node *p;
        p = new student_Node;
        p->next = NULL;
        p->student_ID = identifier;
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
    infile.close();
}
void student_LinkList::admin_deletestudent(int id)
{//����Աɾ��ѧ��
    list_delete(id);
    file_delete("student.txt",id);
    std::cout << "ɾ��ѧ���ɹ�" << std::endl;
}
void student_LinkList::admin_setphone(int id,char phone[])
{//����Ա�޸�ѧ���ֻ���
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_phone,phone);
    file_insert("student.txt",id,phone,"phone");
    std::cout << "�޸��ֻ��ųɹ�" << std::endl;
}
void student_LinkList::admin_setgrade(int id,int grade)
{//����Ա�޸�ѧ���ɼ�
    student_Node *p;
    p = node_get(id);
    p->student_grade = grade;
    file_insert("student.txt",id,std::to_string(grade),"grade");
    std::cout << "�޸ĳɼ��ɹ�" << std::endl;
}

void student_LinkList::admin_getstudentlist()
{//����Ա��ȡѧ���б�
    idorder();
    student_Node *p = head->next;
    std::cout << "---------------------------------ѧ���б�--------------------------------"<< std::endl;
    while(p!=NULL)
    {
        std::cout << "ѧ��ID��"<<p->student_ID<<"     ѧ��������"<<p->student_Name<<"     |      "<<"ѧ���Ա�"<<p->student_Sex<<"     ѧ���ɼ���"<<p->student_grade<< std::endl;
        p = p->next;
    }
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}
void student_LinkList::admin_orderstudentlist()
{//����Ա��ȡѧ�������б�
    order();
    student_Node *p = head->next;
    int i=1;
    std::cout << "---------------------------------ѧ���б�--------------------------------"<< std::endl;
    while(p!=NULL)
    {
        std::cout <<"��"<<i<<"����"<< "ѧ��ID��"<<p->student_ID<<"     ѧ��������"<<p->student_Name<<"     |      "<<"ѧ���Ա�"<<p->student_Sex<<"     ѧ���ɼ���"<<p->student_grade<< std::endl;
        p = p->next;
        i++;
    }
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}
void student_LinkList::admin_getstudentinfo(int id)
{//����Աͨ��id��ȡѧ����Ϣ
    student_Node *p;
    p = node_get(id);
    std::cout << "---------------------------------��ϸ��Ϣ---------------------------------"<<std::endl;
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
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}
void student_LinkList::admin_getstudentinfo(char name[])
{//����Աͨ��������ȡѧ����Ϣ
    int id = get_studentid(name);
    student_Node *p;
    p = node_get(id);
    std::cout << "---------------------------------��ϸ��Ϣ---------------------------------"<<std::endl;
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
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}