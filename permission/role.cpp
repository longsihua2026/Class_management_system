#include "ifrole.h"


void role::read_role()
{//通过文件读取用户列表
    std::string line;
    std::ifstream infile;
    infile.open("user.txt");
    std::cout << "---------------------------------用户列表--------------------------------"<< std::endl;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string file_username;
        std::string password;
        int rule;
       
        if(!(iss>>file_username>>password>>rule))
            break;

        int width = 20;
        int len = file_username.length();
        int padding = width - len;
        int paddingLeft = padding / 2 + (padding % 2 != 0); // 如果padding是奇数，多一个空格放在左边
        int paddingRight = padding / 2;
        std::cout<<std::string(15,' ')<<"用户名："<<std::string(paddingLeft,' ')<<file_username<<std::string(paddingRight,' ')<<"用户类型："<<((rule == 1)?"admin":"other")<<std::endl;
    }
    std::cout << "------------------------------------------------------------------------"<< std::endl;
    infile.close();
}


role::role()
{//角色初始化,如果没有用户则创建一个admin用户
    if(!std::ifstream("user.txt"))//如果文件不存在则创建一个admin用户
        write_role("admin","123456",1);
}


void role::write_role(std::string username,std::string password,int rule)
{//通过文件写入角色信息
    std::ofstream outfile;
    outfile.open("user.txt",std::ios::app);
    outfile<<username<<" "<<password<<" "<<rule<<std::endl;
    outfile.close();
}

void role::create_user(std::string username,std::string password,int rule)
{//构建用户系统，初始用户为admin,123456。
    this->username = username;
    this->password = password;
    this->rule = rule;
    // write_role(username,password,rule);
}

int role::sign_in()
{//通过文件读取角色信息
    std::string line,username;
    std::cout<<"请输入用户名：";
    std::cin>>username;
    std::ifstream infile;
    infile.open("user.txt");
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string file_username;
        std::string input_password,flie_password;
        int rule;
       
        if(!(iss>>file_username>>flie_password>>rule))
            break;
        // iss>>file_username>>flie_password>>rule;
        if(file_username==username)
        {
            std::cout<<"请输入密码：";
            std::cin>>input_password;//输入密码
            if(input_password==flie_password)
            {
                create_user(file_username,flie_password,rule);
                // std::cout<<"登录成功"<<std::endl;
                return 1;
            }
            std::cout<<"密码错误,请重试"<<std::endl;
            return 0;
            // return (file_username+" "+password+" "+std::to_string(rule));//用户存在，返回相关信息。
        }
    }
    std::cout<<"用户不存在"<<std::endl;
    infile.close();
    return 0;
    // throw std::runtime_error("no such user");
}

void role::sign_up()
{//注册
    std::string username;
    std::string password;
    std::cout<<"请输入用户名：";
    std::cin>>username;
    std::cout<<"请输入密码：";
    std::cin>>password;
    write_role(username,password,1);
    std::cout<<"注册成功,请自行登录"<<std::endl;
}

std::string role::get_username()
{//获取用户名
    return this->username;
}

std::string role::get_password()
{//获取密码
    return this->password;
}

bool role::get_rule()
{//获取权限
    if(this->rule==1)
        return true;
    return false;
}


void role::sign_out()
{//注销
    std::string line;
    std::ifstream infile;
    infile.open("user.txt");

    std::ofstream outfile;
    outfile.open("temp.txt");

    while(std::getline(infile,line))
    {
        std::istringstream iss(line);
        std::string file_username;
        std::string password;
        int rule;

        if(!(iss>>file_username>>password>>rule))
            break;
        
        if(file_username!=this->username)
        {
            outfile<<line<<std::endl;
        }
    }

    infile.close();
    outfile.close();

    //覆盖原始文件
    std::remove("user.txt");
    std::rename("temp.txt","user.txt");
}

void role::change_password()
{//修改密码
    std::string line;
    std::ifstream infile;
    infile.open("user.txt");

    std::ofstream outfile;
    outfile.open("temp.txt");

    while(std::getline(infile,line))
    {
        std::istringstream iss(line);
        std::string file_username;
        std::string password;
        int rule;

        if(!(iss>>file_username>>password>>rule))
            break;
        
        if(file_username==this->username)
        {
            std::string new_password;
            std::cout<<"请输入新密码：";
            std::cin>>new_password;
            outfile<<file_username<<" "<<new_password<<" "<<rule<<std::endl;
        }
        else
        {
            outfile<<line<<std::endl;
        }
    }

    infile.close();
    outfile.close();

    //覆盖原始文件
    std::remove("user.txt");
    std::rename("temp.txt","user.txt");
}



// void role::test2()
// {
//     std::string line;
//     std::ifstream infile;
//     infile.open("test.txt");

//     // infile.read(data,sizeof(data));
//     // infile>>data;
//     // while(std::getline(infile,data)){
//     //     std::cout<< data << std::endl;
//     // }
//     // std::cout<<data<<std::endl;
//     while (std::getline(infile, line)) {
//         std::cout<< line <<std::endl;
//         std::istringstream iss(line);
//         std::string word;
//         while (std::getline(iss, word, ' ')) {//按空格分割字符串
//             std::cout << word << std::endl;
//         }
//     }
//     infile.close();
// }



/*除去段前段后空格*/
// #include <sstream>
// #include <string>

// std::string trim(const std::string& str)
// {
//     std::string::size_type start = str.find_first_not_of(" \t");
//     std::string::size_type end = str.find_last_not_of(" \t");

//     return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
// }
