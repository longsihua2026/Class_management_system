#include "ifrole.h"


void role::write_role(std::string username,std::string password,int rule)
{//通过文件写入角色信息
    std::ofstream outfile;
    outfile.open("test.txt",std::ios::ate);
    outfile<<username<<" "<<password<<" "<<rule<<std::endl;
    outfile.close();
}

role::role(std::string username,std::string password,int rule)
{//构建用户系统，初始用户为admin,123456。
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
//     std::cout<<"请输入些什么：";
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

/*除去段前段后空格*/
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
//     std::cout << data << std::endl; // 输出 "hello world"

//     return 0;
// }