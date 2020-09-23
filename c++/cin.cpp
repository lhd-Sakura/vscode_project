/*

    cin函数
    从键盘获取数值输入

*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    //数据输入
    //1.整型
    int a = 0;
    cin >> a;
    cout << "整型变量" << a << endl;

    //2.浮点型
    float f = 3.14f;
    cin >> f;
    cout << "浮点型变量" << f << endl;

    //3.字符型
    char ch = 'a';
    cin >> ch;
    cout << "字符型变量" << ch << endl;
    

    //4.字符串
    string str = "hello";
    cin >> str;
    cout << "字符串" << str << endl;

    return 0;
}
