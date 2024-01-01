#include "iostream"
#include "string.h"
#include "fstream"
#include "sstream"

void iofile_write_end(std::string filename,std::string content)
{//带回车写入文件，用于分隔不同用户
    std::ofstream outfile;
    outfile.open(filename,std::ios::app);
    outfile<<content<<std::endl;
    outfile.close();
}

void iofile_write_uend(std::string filename,std::string content)
{//带空格写入文件
    std::ofstream outfile;
    outfile.open(filename,std::ios::app);
    outfile<<content<<" ";
    outfile.close();
}

// void read_file(std::string filename)
// {
//     std::string line;
//     std::ifstream infile;
//     infile.open(filename);
//     while (std::getline(infile, line)) {
//         std::istringstream iss(line);
//         std::string file_username;
//         std::string password;
//         int rule;
       
//         if(!(iss>>file_username>>password>>rule))
//             break;
//         std::cout<<file_username<<" "<<password<<" "<<rule<<std::endl;
//     }
//     infile.close();
// }

void file_insert(std::string filename,int id,std::string content,std::string content_type)
{//传入要修改参数，修改文件中内容
    std::string line;
    std::ifstream infile;
    infile.open(filename);

    std::ofstream outfile;
    outfile.open("temp.txt");

    while (std::getline(infile, line)) 
    {
        std::istringstream iss(line);
        int file_id;
        std::string sex;
        std::string name;
        std::string number;
        std::string phone;
        std::string brithday;
        std::string qq;
        std::string wechat;
        std::string info;
        int grade;

        if(!(iss>>file_id>>sex>>name>>number>>phone>>brithday>>qq>>wechat>>info>>grade))
            break;

        if(file_id == id)
        {
            if(content_type == "sex")
            outfile<<file_id<<" "<<content<<" "<<name<<" "<<number<<" "<<phone<<" "<<brithday<<" "<<qq<<" "<<wechat<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "name")
            outfile<<file_id<<" "<<sex<<" "<<content<<" "<<number<<" "<<phone<<" "<<brithday<<" "<<qq<<" "<<wechat<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "number")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<content<<" "<<phone<<" "<<brithday<<" "<<qq<<" "<<wechat<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "phone")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<number<<" "<<content<<" "<<brithday<<" "<<qq<<" "<<wechat<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "brithday")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<number<<" "<<phone<<" "<<content<<" "<<qq<<" "<<wechat<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "qq")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<number<<" "<<phone<<" "<<brithday<<" "<<content<<" "<<wechat<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "wechat")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<number<<" "<<phone<<" "<<brithday<<" "<<qq<<" "<<content<<" "<<info<<" "<<grade<<std::endl;
            else if(content_type == "info")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<number<<" "<<phone<<" "<<brithday<<" "<<qq<<" "<<wechat<<" "<<content<<" "<<grade<<std::endl;
            else if(content_type == "grade")
            outfile<<file_id<<" "<<sex<<" "<<name<<" "<<number<<" "<<phone<<" "<<brithday<<" "<<qq<<" "<<wechat<<" "<<info<<" "<<content<<std::endl;
        }
        else
        {
            outfile<<line<<std::endl;
        }
    }
    infile.close();
    outfile.close();

    //覆盖原始文件
    std::remove(filename.c_str());
    std::rename("temp.txt",filename.c_str());
}


void file_delete(std::string filename,int id)
{//传入要删除的id，删除文件中内容
    std::string line;
    std::ifstream infile;
    infile.open(filename);

    std::ofstream outfile;
    outfile.open("temp.txt");

    while (std::getline(infile,line))
    {
        std::istringstream iss(line);
        int file_id;
        std::string sex;
        std::string name;
        std::string number;
        std::string phone;
        std::string brithday;
        std::string qq;
        std::string wechat;
        std::string info;
        int grade;

        if(!(iss>>file_id>>sex>>name>>number>>phone>>brithday>>qq>>wechat>>info>>grade))
            break;
        
        if(file_id!=id)
        {
            outfile<<line<<std::endl;
        }
    }

    infile.close();
    outfile.close();

    //覆盖原始文件
    std::remove(filename.c_str());
    std::rename("temp.txt",filename.c_str());
}


// int main()
// {
//     std::string filename = "abc.txt";
//     std::string content = "admin";
//     char content1[] = "123456";
//     char content2[] = "1";
//     iofile_write_uend(filename,content);
//     iofile_write_uend(filename,content1);
//     iofile_write_end(filename,content2);
//     return 0;
// }


/*cbv文件读取操作*/

// void read_file(std::string filename)