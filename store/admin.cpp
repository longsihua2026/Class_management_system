#include "user.h"

void student_LinkList::admin_addstudent(char sex[],char name[],char phone[])
{//管理员添加学生
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
    strcpy(p->student_info,"这是一个学生");
    p->student_grade = 0;
    node_insert(p);
    // std::cout << "添加学生成功" << std::endl;
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
void student_LinkList::admin_addstudent_csv(std::string filename)
{
    std::string line;
    std::ifstream infile;
    infile.open(filename);
    if(!infile)
    {
        std::cout << "文件打开失败" << std::endl;
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
        
        
        //读取完成添加结点信息创建学生链表
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
    infile.close();
}
void student_LinkList::admin_deletestudent(int id)
{//管理员删除学生
    list_delete(id);
    file_delete("student.txt",id);
    std::cout << "删除学生成功" << std::endl;
}
void student_LinkList::admin_setphone(int id,char phone[])
{//管理员修改学生手机号
    student_Node *p;
    p = node_get(id);
    strcpy(p->student_phone,phone);
    file_insert("student.txt",id,phone,"phone");
    std::cout << "修改手机号成功" << std::endl;
}
void student_LinkList::admin_setgrade(int id,int grade)
{//管理员修改学生成绩
    student_Node *p;
    p = node_get(id);
    p->student_grade = grade;
    file_insert("student.txt",id,std::to_string(grade),"grade");
    std::cout << "修改成绩成功" << std::endl;
}

void student_LinkList::admin_getstudentlist()
{//管理员获取学生列表
    idorder();
    student_Node *p = head->next;
    std::cout << "---------------------------------学生列表--------------------------------"<< std::endl;
    while(p!=NULL)
    {
        std::cout << "学生ID："<<p->student_ID<<"     学生姓名："<<p->student_Name<<"     |      "<<"学生性别："<<p->student_Sex<<"     学生成绩："<<p->student_grade<< std::endl;
        p = p->next;
    }
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}
void student_LinkList::admin_orderstudentlist()
{//管理员获取学生排名列表
    order();
    student_Node *p = head->next;
    int i=1;
    std::cout << "---------------------------------学生列表--------------------------------"<< std::endl;
    while(p!=NULL)
    {
        std::cout <<"第"<<i<<"名："<< "学生ID："<<p->student_ID<<"     学生姓名："<<p->student_Name<<"     |      "<<"学生性别："<<p->student_Sex<<"     学生成绩："<<p->student_grade<< std::endl;
        p = p->next;
        i++;
    }
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}
void student_LinkList::admin_getstudentinfo(int id)
{//管理员通过id获取学生信息
    student_Node *p;
    p = node_get(id);
    std::cout << "---------------------------------详细信息---------------------------------"<<std::endl;
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
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}
void student_LinkList::admin_getstudentinfo(char name[])
{//管理员通过姓名获取学生信息
    int id = get_studentid(name);
    student_Node *p;
    p = node_get(id);
    std::cout << "---------------------------------详细信息---------------------------------"<<std::endl;
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
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}