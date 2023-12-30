#include "ifrole.h"


void role::read_role()
{//ͨ���ļ���ȡ�û��б�
    std::string line;
    std::ifstream infile;
    infile.open("user.txt");
    std::cout << "---------------------------------�û��б�--------------------------------"<< std::endl;
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
        int paddingLeft = padding / 2 + (padding % 2 != 0); // ���padding����������һ���ո�������
        int paddingRight = padding / 2;
        std::cout<<std::string(15,' ')<<"�û�����"<<std::string(paddingLeft,' ')<<file_username<<std::string(paddingRight,' ')<<"�û����ͣ�"<<((rule == 1)?"admin":"other")<<std::endl;
    }
    std::cout << "------------------------------------------------------------------------"<< std::endl;
    infile.close();
}


role::role()
{//��ɫ��ʼ��,���û���û��򴴽�һ��admin�û�
    if(!std::ifstream("user.txt"))//����ļ��������򴴽�һ��admin�û�
        write_role("admin","123456",1);
}


void role::write_role(std::string username,std::string password,int rule)
{//ͨ���ļ�д���ɫ��Ϣ
    std::ofstream outfile;
    outfile.open("user.txt",std::ios::app);
    outfile<<username<<" "<<password<<" "<<rule<<std::endl;
    outfile.close();
}

void role::create_user(std::string username,std::string password,int rule)
{//�����û�ϵͳ����ʼ�û�Ϊadmin,123456��
    this->username = username;
    this->password = password;
    this->rule = rule;
    // write_role(username,password,rule);
}

int role::sign_in()
{//ͨ���ļ���ȡ��ɫ��Ϣ
    std::string line,username;
    std::cout<<"�������û�����";
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
            std::cout<<"���������룺";
            std::cin>>input_password;//��������
            if(input_password==flie_password)
            {
                create_user(file_username,flie_password,rule);
                // std::cout<<"��¼�ɹ�"<<std::endl;
                return 1;
            }
            std::cout<<"�������,������"<<std::endl;
            return 0;
            // return (file_username+" "+password+" "+std::to_string(rule));//�û����ڣ����������Ϣ��
        }
    }
    std::cout<<"�û�������"<<std::endl;
    infile.close();
    return 0;
    // throw std::runtime_error("no such user");
}

void role::sign_up()
{//ע��
    std::string username;
    std::string password;
    std::cout<<"�������û�����";
    std::cin>>username;
    std::cout<<"���������룺";
    std::cin>>password;
    write_role(username,password,1);
    std::cout<<"ע��ɹ�,�����е�¼"<<std::endl;
}

std::string role::get_username()
{//��ȡ�û���
    return this->username;
}

std::string role::get_password()
{//��ȡ����
    return this->password;
}

bool role::get_rule()
{//��ȡȨ��
    if(this->rule==1)
        return true;
    return false;
}


void role::sign_out()
{//ע��
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

    //����ԭʼ�ļ�
    std::remove("user.txt");
    std::rename("temp.txt","user.txt");
}

void role::change_password()
{//�޸�����
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
            std::cout<<"�����������룺";
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

    //����ԭʼ�ļ�
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
//         while (std::getline(iss, word, ' ')) {//���ո�ָ��ַ���
//             std::cout << word << std::endl;
//         }
//     }
//     infile.close();
// }



/*��ȥ��ǰ�κ�ո�*/
// #include <sstream>
// #include <string>

// std::string trim(const std::string& str)
// {
//     std::string::size_type start = str.find_first_not_of(" \t");
//     std::string::size_type end = str.find_last_not_of(" \t");

//     return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
// }
