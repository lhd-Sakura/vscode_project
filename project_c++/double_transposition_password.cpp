/*
    仿射密码加密（双换位密码）
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string key_x, key_y, plain, back;

    cout << "请输入行方向的密钥:\n";
    cin >> key_x;
    back = key_x;

    cout << "请输入列方向的密钥:\n";
    cin >> key_y;

    cout << "请输入明文(不需要输入间隔):\n";
    cin >> plain;
    for (auto i = plain.size(); i % key_y.size() != 0; i++)
    {
        plain.push_back('x'); //通过判断在明文数组后面补齐x
    }
    cout << endl;

    cout << "分组后的原文为：" << endl;

    //行分组y，列分组x
    string str[key_x.size()][key_y.size()];

    for (int i = 0; i < key_x.size(); i++)
    {
        for (int j = 0; j < key_y.size(); j++)
        {
            str[i][j] = plain[i * key_x.size() + j];

            cout << str[i][j];
        }
        cout << endl;
    }

    cout << "*********加密中***********" << endl;
    cout << "密文为：" << endl;

    string str2[key_x.size()][key_y.size()];
    string str3[key_x.size()][key_y.size()];

    for (int i = 0; i < key_x.size(); i++)
    {
        for (int j = 0; j < key_y.size(); j++)
        {
            str2[i][j] = str[key_x[i] - 49][j];
        }
    }

    for (int i = 0; i < key_x.size(); i++)
    {
        for (int j = 0; j < key_y.size(); j++)
        {
            str3[i][j] = str2[i][key_y[j] - 49];
            cout << str3[i][j];
        }
    }
    cout << endl;
}
