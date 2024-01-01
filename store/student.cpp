#include "user.h"

student_LinkList::student_LinkList()
{
    head = new student_Node;//头结点
    head->next = NULL;
    length = 0;
    identifier = 1;//学生id生成标识符
    std::ifstream file("student.txt");
    if(!file)
        std::cout<<"该班级学生为空！,请先创建！"<<std::endl;
    else
        file_create_student();
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
    /*将信息写入文件*/
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
{//根据文件中读取的信息创建链表
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
        //读取完成添加结点信息创建学生链表
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
    std::cout << "学生链表已销毁" << std::endl;
}

void student_LinkList::student_setinfo(int id,char info[])//学生修改个人简介
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_info,info);
    file_insert("student.txt",id,info,"info");
    std::cout << "修改简介成功" << std::endl;
    return ;
}

void student_LinkList::student_setsex(int id,char sex[])//学生修改性别
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_Sex,sex);
    file_insert("student.txt",id,sex,"sex");
    std::cout << "修改性别成功" << std::endl;
    return ;
}

void student_LinkList::student_setbrithday(int id,char brithday[])//学生修改生日(生日的输入格式为"2003-01-15",键入后以此格式调用函数)
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_brithday,brithday);
    file_insert("student.txt",id,brithday,"brithday");
    std::cout << "修改生日成功" << std::endl;
    return ;
}

void student_LinkList::student_setqq(int id,char qq[])//学生修改QQ
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_qq,qq);
    file_insert("student.txt",id,qq,"qq");
    std::cout << "修改QQ成功" << std::endl;
    return ;
}

void student_LinkList::student_setwechat(int id,char wechat[])//学生修改微信
{
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_wechat,wechat);
    file_insert("student.txt",id,wechat,"wechat");
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
        std::cout << "你的成绩:" <<"    |      "<< "暂无成绩或成绩异常" << std::endl;
    }
    else
    {
        std::cout << "你的成绩:" <<"    |      "<< p->student_grade << std::endl;
    }
    return NULL;
}

int student_LinkList::student_getorder(int id)//学生获取自己的排名
{
    order();
    int i = 1;
    if (head->next == NULL)
    {
        std::cout << "班级当中还没有学生" << std::endl;
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
    std::cout<<"你的排名为："<<i<<std::endl;
    return i;
}
