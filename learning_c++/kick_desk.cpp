/*

    敲桌子游戏
    碰到7倍数，个位、十位有7的都跳过

*/







#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    for (int num = 0; num <= 100; num++)
    {
        if (num % 7 != 0 and num % 10 != 7 and (num / 10) % 10 != 7)
        {
            cout << num << endl;
        }
        else
        {
            cout << "敲桌子" << endl;
        }
        
    }

    return 0;
}
