#include "./store/user.h"
#include "iostream"
#include "string.h"

void student_menu(){
    std::cout << "---------------------------------���ܲ˵�---------------------------------"<<std::endl;
    std::cout << "1.�޸ĸ��˼��"<<std::endl;
    std::cout << "2.�޸��Ա�"<<std::endl;
    std::cout << "3.�޸��ֻ���"<<std::endl;
    std::cout << "4.�޸�����"<<std::endl;
    std::cout << "5.�޸�QQ"<<std::endl;
    std::cout << "6.�޸�΢��"<<std::endl;
    std::cout << "7.��ȡ������Ϣ"<<std::endl;
    std::cout << "8.��ȡ�ɼ�"<<std::endl;
    std::cout << "9.��ȡ����"<<std::endl;
    std::cout << "10.�˳�ϵͳ"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}

void admin_menu()
{
    std::cout << "---------------------------------���ܲ˵�---------------------------------"<<std::endl;
    std::cout << "1.���ѧ��"<<std::endl;
    std::cout << "2.ɾ��ѧ��"<<std::endl;
    std::cout << "3.�޸�ѧ���ֻ���"<<std::endl;
    std::cout << "4.�޸�ѧ���ɼ�"<<std::endl;
    std::cout << "5.��ȡѧ���б�"<<std::endl;
    std::cout << "6.��ȡѧ�������б�"<<std::endl;
    std::cout << "7.ͨ��id��ȡѧ����Ϣ"<<std::endl;
    std::cout << "8.ͨ��������ȡѧ����Ϣ"<<std::endl;
    std::cout << "9.�˳�ϵͳ"<<std::endl;
    std::cout << "------------------------------------------------------------------------"<< std::endl;
}



int main(){
    student_LinkList Aclass("��","����","19047914071");
    Aclass.student_get(1);
    Aclass.student_getorder(1);
    Aclass.admin_addstudent("��","����","19047914072");
    Aclass.admin_addstudent("��","����","19047914073");
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