/*
    简单替换密码c实现



*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str_in;
    int mode;
    int size;

    cout << "输入字符串" << endl;
    cin >> str_in;

    cout << str_in << endl;
    cout << sizeof(str_in) << endl;
    cout << sizeof(str_in[0]) << endl;

    size = sizeof(str_in) / sizeof(str_in[0]);
    cout << "字符长度为：" << size << endl;

    cout << "程序解密中......" << endl;



    return 0;
}
