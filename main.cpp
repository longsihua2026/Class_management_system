#include "./store/user.h"
#include "iostream"
#include "string.h"

#include "./permission/sign.cpp"

void student_menu(){
    std::cout << "---------------------------------功能菜单---------------------------------"<<std::endl;
    std::cout << "1.修改个人简介"<<std::endl;
    std::cout << "2.修改性别"<<std::endl;
    std::cout << "3.修改生日"<<std::endl;
    std::cout << "4.修改QQ"<<std::endl;
    std::cout << "5.修改微信"<<std::endl;
    std::cout << "6.获取个人信息"<<std::endl;
    std::cout << "7.获取成绩"<<std::endl;
    std::cout << "8.获取排名"<<std::endl;
    std::cout << "9.退出系统"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}

void admin_menu()
{
    std::cout << "---------------------------------功能菜单---------------------------------"<<std::endl;
    std::cout << "1.添加学生"<<std::endl;
    std::cout << "2.添加学生(csv)"<<std::endl;
    std::cout << "3.删除学生"<<std::endl;
    std::cout << "4.修改学生手机号"<<std::endl;
    std::cout << "5.修改学生成绩"<<std::endl;
    std::cout << "6.获取学生列表"<<std::endl;
    std::cout << "7.获取学生排名列表"<<std::endl;
    std::cout << "8.通过id获取学生信息"<<std::endl;
    std::cout << "9.通过姓名获取学生信息"<<std::endl;
    std::cout << "10.退出系统"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}


int main(){
    int id = 1,status;
    status = sign();
    student_LinkList Aclass;
    if(status == 2)
    {//进入学生端
        if (Aclass.list_empty())
        {
            std::cout << "此班级没有学生，请通过管理员端创建：" << std::endl;
            main();
            return 0;
        }
        else
        {
            std::cout << "请输入自己的姓名" << std::endl;
            char name[20];
            std::cin >> name;
            id = Aclass.get_studentid(name);
            if(id==0)
            {
                std::cout << "此班级没有此学生，请确认后再登录。" << std::endl;
                main();
                return 0;
            }
            student_menu();
            std::cout<<"请输入你要进行的操作：";
            int choice;
            std::cin>>choice;
            while (1)
            {
                switch (choice)
                {
                case 1:
                    std::cout << "请输入你要修改的个人简介：";
                    char info[100];
                    std::cin >> info;
                    Aclass.student_setinfo(id,info);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;
                case 2:
                    std::cout << "请输入你要修改的性别：";
                    char sex[20];
                    std::cin >> sex;
                    Aclass.student_setsex(id,sex);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;
                case 3:
                    std::cout << "请输入你要修改的生日：";
                    char brithday[20];
                    std::cin >> brithday;
                    Aclass.student_setbrithday(id,brithday);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;
                case 4:
                    std::cout << "请输入你要修改的QQ：";
                    char qq[20];
                    std::cin >> qq;
                    Aclass.student_setqq(id,qq);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;
                case 5:
                    std::cout << "请输入你要修改的微信：";
                    char wechat[20];
                    std::cin >> wechat;
                    Aclass.student_setwechat(id,wechat);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;
                case 6:
                    Aclass.student_get(id);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;       
                case 7:
                    Aclass.student_getgrade(id);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                    break;
                case 8:
                    Aclass.student_getorder(id);
                    student_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                case 9:
                    std::cout << "退出成功！！！" << std::endl;
                    exit(0);
                default:
                    std::cout<<"输入错误，请重新输入：";
                    std::cin>>choice;
                    break;
                }
            }
        }
    }
    else if(status == 1)
    {//进入管理员端
        admin_menu();
        std::cout<<"请输入你要进行的操作：";
        int choice;
        std::string filename;
        std::cin>>choice;
        while(1)
        {
            switch (choice)
            {
            case 1:
                char sex[20],name[20],phone[20];
                std::cout<<"请输入学生姓名：";
                std::cin>>name;
                std::cout<<"请输入学生性别：";
                std::cin>>sex;
                std::cout<<"请输入学生手机号：";
                std::cin>>phone;
                Aclass.admin_addstudent(sex,name,phone);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 2:
                std::cout<<"请输入学生信息文件名：";
                std::cin>>filename;
                Aclass.admin_addstudent_csv(filename);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 3:
                std::cout<<"请输入要删除的学生ID：";
                // int id;
                std::cin>>id;
                Aclass.admin_deletestudent(id);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 4:
                std::cout<<"请输入要修改的学生ID：";
                // int id;
                std::cin>>id;
                std::cout<<"请输入要修改的手机号：";
                // char phone[20];
                std::cin>>phone;
                Aclass.admin_setphone(id,phone);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 5:
                std::cout<<"请输入要修改的学生ID：";
                // int id;
                std::cin>>id;
                std::cout<<"请输入要修改的成绩：";
                int grade;
                std::cin>>grade;
                Aclass.admin_setgrade(id,grade);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 6:
                Aclass.admin_getstudentlist();
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 7:
                Aclass.admin_orderstudentlist();
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 8:
                std::cout<<"请输入要查询的学生ID：";
                // int id;
                std::cin>>id;
                Aclass.admin_getstudentinfo(id);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 9:
                std::cout<<"请输入要查询的学生姓名：";
                // char name[20];
                std::cin>>name;
                Aclass.admin_getstudentinfo(name);
                admin_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 10:
                std::cout << "退出成功！！！" << std::endl;
                exit(0);
            default:
                std::cout<<"输入错误，请重新输入：";
                std::cin>>choice;
                break;
            }
        }
    }
    // student_LinkList Aclass("男","张三","19047914071");
    // Aclass.student_get(1);
    // Aclass.student_getorder(1);
    // Aclass.admin_addstudent("男","李四","19047914072");
    // Aclass.admin_addstudent("男","王五","19047914073");
    // Aclass.admin_setgrade(1,80);
    // Aclass.admin_setgrade(2,90);
    // Aclass.admin_setgrade(3,60);
    // Aclass.admin_getstudentlist();
    // Aclass.admin_orderstudentlist();


    // char number_frint[]="2022211003000x";
    // const char* number_after = std::to_string(1).c_str();
    // // char* number_frint = c;
    // char number[20];
    // strcpy(number,strcat(number_frint,number_after));
    // std::cout << number << std::endl;
    system("pause");
    return 0;
}