#include "./store/user.h"
#include "iostream"
#include "string.h"

void student_menu(){
    std::cout << "---------------------------------功能菜单---------------------------------"<<std::endl;
    std::cout << "1.修改个人简介"<<std::endl;
    std::cout << "2.修改性别"<<std::endl;
    std::cout << "3.修改手机号"<<std::endl;
    std::cout << "4.修改生日"<<std::endl;
    std::cout << "5.修改QQ"<<std::endl;
    std::cout << "6.修改微信"<<std::endl;
    std::cout << "7.获取个人信息"<<std::endl;
    std::cout << "8.获取成绩"<<std::endl;
    std::cout << "9.获取排名"<<std::endl;
    std::cout << "10.退出系统"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}

void admin_menu()
{
    std::cout << "---------------------------------功能菜单---------------------------------"<<std::endl;
    std::cout << "1.添加学生"<<std::endl;
    std::cout << "2.删除学生"<<std::endl;
    std::cout << "3.修改学生手机号"<<std::endl;
    std::cout << "4.修改学生成绩"<<std::endl;
    std::cout << "5.获取学生列表"<<std::endl;
    std::cout << "6.获取学生排名列表"<<std::endl;
    std::cout << "7.通过id获取学生信息"<<std::endl;
    std::cout << "8.通过姓名获取学生信息"<<std::endl;
    std::cout << "9.退出系统"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}



int main(){
    student_LinkList Aclass("男","张三","19047914071");
    Aclass.student_get(1);
    Aclass.student_getorder(1);
    Aclass.admin_addstudent("男","李四","19047914072");
    Aclass.admin_addstudent("男","王五","19047914073");
    Aclass.admin_setgrade(1,80);
    Aclass.admin_setgrade(2,90);
    Aclass.admin_setgrade(3,60);
    Aclass.admin_getstudentlist();
    Aclass.admin_orderstudentlist();


    // char number_frint[]="2022211003000x";
    // const char* number_after = std::to_string(1).c_str();
    // // char* number_frint = c;
    // char number[20];
    // strcpy(number,strcat(number_frint,number_after));
    // std::cout << number << std::endl;
    system("pause");
    return 0;
}