#include "./store/user.h"
#include "iostream"
#include "string.h"

#include "./permission/sign.cpp"

void student_menu(){
    std::cout << "---------------------------------���ܲ˵�---------------------------------"<<std::endl;
    std::cout << "1.�޸ĸ��˼��"<<std::endl;
    std::cout << "2.�޸��Ա�"<<std::endl;
    std::cout << "3.�޸�����"<<std::endl;
    std::cout << "4.�޸�QQ"<<std::endl;
    std::cout << "5.�޸�΢��"<<std::endl;
    std::cout << "6.��ȡ������Ϣ"<<std::endl;
    std::cout << "7.��ȡ�ɼ�"<<std::endl;
    std::cout << "8.��ȡ����"<<std::endl;
    std::cout << "9.�˳�ϵͳ"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}

void admin_menu()
{
    std::cout << "---------------------------------���ܲ˵�---------------------------------"<<std::endl;
    std::cout << "1.���ѧ��"<<std::endl;
    std::cout << "2.���ѧ��(csv)"<<std::endl;
    std::cout << "3.ɾ��ѧ��"<<std::endl;
    std::cout << "4.�޸�ѧ���ֻ���"<<std::endl;
    std::cout << "5.�޸�ѧ���ɼ�"<<std::endl;
    std::cout << "6.��ȡѧ���б�"<<std::endl;
    std::cout << "7.��ȡѧ�������б�"<<std::endl;
    std::cout << "8.ͨ��id��ȡѧ����Ϣ"<<std::endl;
    std::cout << "9.ͨ��������ȡѧ����Ϣ"<<std::endl;
    std::cout << "10.�˳�ϵͳ"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}


int main(){
    int id = 1,status;
    status = sign();
    student_LinkList Aclass;
    if(status == 2)
    {//����ѧ����
        if (Aclass.list_empty())
        {
            std::cout << "�˰༶û��ѧ������ͨ������Ա�˴�����" << std::endl;
            main();
            return 0;
        }
        else
        {
            std::cout << "�������Լ�������" << std::endl;
            char name[20];
            std::cin >> name;
            id = Aclass.get_studentid(name);
            if(id==0)
            {
                std::cout << "�˰༶û�д�ѧ������ȷ�Ϻ��ٵ�¼��" << std::endl;
                main();
                return 0;
            }
            student_menu();
            std::cout<<"��������Ҫ���еĲ�����";
            int choice;
            std::cin>>choice;
            while (1)
            {
                switch (choice)
                {
                case 1:
                    std::cout << "��������Ҫ�޸ĵĸ��˼�飺";
                    char info[100];
                    std::cin >> info;
                    Aclass.student_setinfo(id,info);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;
                case 2:
                    std::cout << "��������Ҫ�޸ĵ��Ա�";
                    char sex[20];
                    std::cin >> sex;
                    Aclass.student_setsex(id,sex);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;
                case 3:
                    std::cout << "��������Ҫ�޸ĵ����գ�";
                    char brithday[20];
                    std::cin >> brithday;
                    Aclass.student_setbrithday(id,brithday);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;
                case 4:
                    std::cout << "��������Ҫ�޸ĵ�QQ��";
                    char qq[20];
                    std::cin >> qq;
                    Aclass.student_setqq(id,qq);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;
                case 5:
                    std::cout << "��������Ҫ�޸ĵ�΢�ţ�";
                    char wechat[20];
                    std::cin >> wechat;
                    Aclass.student_setwechat(id,wechat);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;
                case 6:
                    Aclass.student_get(id);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;       
                case 7:
                    Aclass.student_getgrade(id);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                    break;
                case 8:
                    Aclass.student_getorder(id);
                    student_menu();
                    std::cout<<"��������Ҫ���еĲ�����";
                    std::cin>>choice;
                case 9:
                    std::cout << "�˳��ɹ�������" << std::endl;
                    exit(0);
                default:
                    std::cout<<"����������������룺";
                    std::cin>>choice;
                    break;
                }
            }
        }
    }
    else if(status == 1)
    {//�������Ա��
        admin_menu();
        std::cout<<"��������Ҫ���еĲ�����";
        int choice;
        std::string filename;
        std::cin>>choice;
        while(1)
        {
            switch (choice)
            {
            case 1:
                char sex[20],name[20],phone[20];
                std::cout<<"������ѧ��������";
                std::cin>>name;
                std::cout<<"������ѧ���Ա�";
                std::cin>>sex;
                std::cout<<"������ѧ���ֻ��ţ�";
                std::cin>>phone;
                Aclass.admin_addstudent(sex,name,phone);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 2:
                std::cout<<"������ѧ����Ϣ�ļ�����";
                std::cin>>filename;
                Aclass.admin_addstudent_csv(filename);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 3:
                std::cout<<"������Ҫɾ����ѧ��ID��";
                // int id;
                std::cin>>id;
                Aclass.admin_deletestudent(id);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 4:
                std::cout<<"������Ҫ�޸ĵ�ѧ��ID��";
                // int id;
                std::cin>>id;
                std::cout<<"������Ҫ�޸ĵ��ֻ��ţ�";
                // char phone[20];
                std::cin>>phone;
                Aclass.admin_setphone(id,phone);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 5:
                std::cout<<"������Ҫ�޸ĵ�ѧ��ID��";
                // int id;
                std::cin>>id;
                std::cout<<"������Ҫ�޸ĵĳɼ���";
                int grade;
                std::cin>>grade;
                Aclass.admin_setgrade(id,grade);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 6:
                Aclass.admin_getstudentlist();
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 7:
                Aclass.admin_orderstudentlist();
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 8:
                std::cout<<"������Ҫ��ѯ��ѧ��ID��";
                // int id;
                std::cin>>id;
                Aclass.admin_getstudentinfo(id);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 9:
                std::cout<<"������Ҫ��ѯ��ѧ��������";
                // char name[20];
                std::cin>>name;
                Aclass.admin_getstudentinfo(name);
                admin_menu();
                std::cout<<"��������Ҫ���еĲ�����";
                std::cin>>choice;
                break;
            case 10:
                std::cout << "�˳��ɹ�������" << std::endl;
                exit(0);
            default:
                std::cout<<"����������������룺";
                std::cin>>choice;
                break;
            }
        }
    }
    // student_LinkList Aclass("��","����","19047914071");
    // Aclass.student_get(1);
    // Aclass.student_getorder(1);
    // Aclass.admin_addstudent("��","����","19047914072");
    // Aclass.admin_addstudent("��","����","19047914073");
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