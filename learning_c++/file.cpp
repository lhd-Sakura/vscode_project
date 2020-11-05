/*
    文件操作
    写文件 读文件

*/

#include <fstream>
#include <iostream>

using namespace std;

//写文件
void test01()
{
    ofstream ofs;

    ofs.open("test.txt", ios::out);
    ofs << "姓名：张三" << endl;
    ofs << "test" << endl;
    ofs.close();
}
//读文件
void test02()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //读文件
    //1.
    // char buf[1024] = {0};
    // while(ifs>>buf)
    // {
    //     cout << buf << endl;
    // }

    //2.
    // char buf[1024] = {0};
    // while(ifs.getline(buf,sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    //3.
    string buf;
    while(getline(ifs,buf))
    {
        cout << buf << endl;
    }


    //4.
    // char c;
    // while (( c = ifs.get()) != EOF)
    // {
    //     cout << c;
    // }
    

    ifs.close();

}

int main(int argc, char const *argv[])
{
    //test01();
    test02();
    return 0;
}
