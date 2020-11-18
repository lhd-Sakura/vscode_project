/*
    TCP/IP实验1练习
*/
#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
int main()
{
    char user[10] = "小猫叫", pwd[10], all[98];
    const char *wel = "欢迎您，尊敬的", local[] = "江苏";
    while (1)
    {
        cout << "请输入您的姓名\n";
        cin >> user;
        cout << "请输入您的密码\n";
        cin >> pwd;
        cout << sizeof(pwd) << "     " << strlen(pwd) << "\n";
        if (strlen(pwd) >= 6)
        {
            if (strcmp(pwd, "111111") == 0)
            {
                sprintf(all, "%s%s,您来自%s", wel, user, local);
                cout << all << "\n";
                break;
            }
            else
                cout << "非法用户，拒绝登录\n";
        }
        else
            cout << "密码不小于六个字符\n";
    }
    return 0;
}
