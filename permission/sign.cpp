#include "iostream"
#include "ifrole.h"

void sign_menu(){
    std::cout << "---------------------------------用户登录---------------------------------"<<std::endl;
    std::cout << "1.读取用户列表"<<std::endl;
    std::cout << "2.注册"<<std::endl;
    std::cout << "3.登录"<<std::endl;
    std::cout << "4.退出系统"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}

void admin_login(){
    std::cout << "---------------------------------功能菜单---------------------------------"<<std::endl;
    std::cout << "1.进入管理员端"<<std::endl;
    std::cout << "2.获取用户名"<<std::endl;
    std::cout << "3.修改密码"<<std::endl;
    std::cout << "4.获取密码"<<std::endl;
    std::cout << "5.获取权限"<<std::endl;
    std::cout << "6.注销用户"<<std::endl;
    std::cout << "7.退出系统"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}


int main(){
    sign_menu();
    std::cout<<"请输入你要进行的操作：";
    int choice,i;
    std::cin>>choice;
    role user;
    while(0<choice&&choice<=4)
    {
        switch (int(choice))
        {
            case 1:
                role::read_role();
                sign_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 2:
                user.sign_up();
                sign_menu();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 3:
                i = user.sign_in();
                if(i==1)
                {
                    std::cout << "登录成功！！！"<<std::endl;
                    choice = 0;
                }
                else if(i==0)
                {
                    sign_menu();
                    std::cout<<"请输入你要进行的操作：";
                    std::cin>>choice;
                }
                break;
            case 4:
                std::cout<<"退出成功！！！"<<std::endl;
                exit(0);
        }
    }
    admin_login();
    std::cout<<"请输入你要进行的操作：";
    std::cin>>choice;
    while(0<choice&&choice<=7)
    {
        switch (int(choice))
        {
            case 1:
                choice = 0;
                break;
            case 2:
                std::cout<<"用户名："<<user.get_username()<<std::endl;
                admin_login();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 3:
                user.change_password();
                admin_login();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 4:
                std::cout<<"密码："<<user.get_password()<<std::endl;
                admin_login();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 5:
                std::cout<<"权限："<<((user.get_rule()==1)?"admin":"other")<<std::endl;
                admin_login();
                std::cout<<"请输入你要进行的操作：";
                std::cin>>choice;
                break;
            case 6:
                user.sign_out();
                main();
                break;
            case 7:
                std::cout<<"退出成功！！！"<<std::endl;
                exit(0);
        }
    }
    system("pause");
    return 0;
}
