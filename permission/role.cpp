#include "ifrole.h"


void role::write_role(std::string username,std::string password,int rule)
{//ͨ���ļ�д���ɫ��Ϣ
    std::ofstream outfile;
    outfile.open("test.txt",std::ios::ate);
    outfile<<username<<" "<<password<<" "<<rule<<std::endl;
    outfile.close();
}

role::role(std::string username,std::string password,int rule)
{//�����û�ϵͳ����ʼ�û�Ϊadmin,123456��
    this->username = username;
    this->password = password;
    this->rule = rule;
    write_role(username,password,rule);
}

// void role::test1()
// {
//     char data[80];
//     std::ofstream outfile;
//     outfile.open("test.txt");
    
//     strcpy(data,"hello l am lsh");
//     outfile<<data<<std::endl;
//     // std::cin.ignore();
//     std::cout<<"������Щʲô��";
//     // std::cin.ignore();
//     std::cin>>data;
//     outfile<<data<<std::endl;
//     outfile.close();
// }

void role::test2()
{
    std::string line;
    std::ifstream infile;
    infile.open("test.txt");

    // infile.read(data,sizeof(data));
    // infile>>data;
    // while(std::getline(infile,data)){
    //     std::cout<< data << std::endl;
    // }
    // std::cout<<data<<std::endl;
    while (std::getline(infile, line)) {
    std::cout<< line <<std::endl;
    std::istringstream iss(line);
    std::string word;
    while (std::getline(iss, word, ' ')) {
        std::cout << word << std::endl;
    }
}

    infile.close();
}

/*��ȥ��ǰ�κ�ո�*/
// #include <sstream>
// #include <string>

// std::string trim(const std::string& str)
// {
//     std::string::size_type start = str.find_first_not_of(" \t");
//     std::string::size_type end = str.find_last_not_of(" \t");

//     return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
// }

// int main()
// {
//     std::string data = "   hello world   ";
//     data = trim(data);
//     std::cout << data << std::endl; // ��� "hello world"

//     return 0;
// }