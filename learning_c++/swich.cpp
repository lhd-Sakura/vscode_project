#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int a = 0;
    cout << "请输入数字" << endl;

    cin >> a;


    switch (a)
    {
    case 1:
        cout << "您输入的数字为1" << endl;
        break;
    

    default:
        cout << "您输入的数字不为1" << endl;
        break;
    }


    return 0;
}


