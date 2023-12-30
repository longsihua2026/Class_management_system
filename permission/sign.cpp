#include "iostream"
#include "ifrole.h"

void sign_menu(){
    std::cout << "---------------------------------�û���¼---------------------------------"<<std::endl;
    std::cout << "1.��ȡ�û��б�"<<std::endl;
    std::cout << "2.ע��"<<std::endl;
    std::cout << "3.��¼"<<std::endl;
    std::cout << "4.�˳�ϵͳ"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}

void admin_login(){
    std::cout << "---------------------------------���ܲ˵�---------------------------------"<<std::endl;
    std::cout << "1.�������Ա��"<<std::endl;
    std::cout << "2.��ȡ�û���"<<std::endl;
    std::cout << "3.�޸�����"<<std::endl;
    std::cout << "4.��ȡ����"<<std::endl;
    std::cout << "5.��ȡȨ��"<<std::endl;
    std::cout << "6.ע���û�"<<std::endl;
    std::cout << "7.�˳�ϵͳ"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}


int main(){
    sign_menu();
    std::cout<<"��������Ҫ���еĲ�����";
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
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 2:
                user.sign_up();
                sign_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 3:
                i = user.sign_in();
                if(i==1)
                {
                    std::cout << "��¼�ɹ�������"<<std::endl;
                    choice = 0;
                }
                else if(i==0)
                {
                    sign_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                }
                break;
            case 4:
                std::cout<<"�˳��ɹ�������"<<std::endl;
                exit(0);
        }
    }
    admin_login();
    std::cout<<"��������Ҫ���еĲ�����";
    std::cin>>choice;
    while(0<choice&&choice<=7)
    {
        switch (int(choice))
        {
            case 1:
                choice = 0;
                break;
            case 2:
                std::cout<<"�û�����"<<user.get_username()<<std::endl;
                admin_login();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 3:
                user.change_password();
                admin_login();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 4:
                std::cout<<"���룺"<<user.get_password()<<std::endl;
                admin_login();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 5:
                std::cout<<"Ȩ�ޣ�"<<((user.get_rule()==1)?"admin":"other")<<std::endl;
                admin_login();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 6:
                user.sign_out();
                main();
                break;
            case 7:
                std::cout<<"�˳��ɹ�������"<<std::endl;
                exit(0);
        }
    }
    system("pause");
    return 0;
}
