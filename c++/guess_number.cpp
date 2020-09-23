/*

    猜测0-99中的随机数


*/





#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //添加随机数种子 利用当前系统时间 防止每次随机数相同
    srand((unsigned int)time(NULL));

    //生成0-99的随机数
    int num = rand() % 100 + 1;

    cout << "请输入数字进行猜测" << endl;
    cout << "猜对了就会退出游戏哦" << endl;

    while (1)
    {
        int val = 0;
        cin >> val;

        if (val > num)
        {
            cout << "过大" << endl;
        }
        if (val < num)
        {
            cout << "过小" << endl;
        }
        if (val == num)
        {
            cout << "您猜对了，退出游戏" << endl;
            break;
        }
    }

    return 0;
}
