/*
    动态规划
    1.计算有多少种方法到达台阶
    有一楼梯共M级，刚开始时你在第一级，
    若每次只能跨上一级或二级，要走上第M级，共有多少种走法？

    问题划分为 斐波那契数列问题，可以用递归法和动态规划计算

*/
#include <iostream>

using namespace std;

int achieve_stair( int arr)
{
    if (arr < 1)
    {
        return 0;
    }
    if (arr == 1)
    {
        return 1;
    }
    if (arr == 2)
    {
        return 2;
    }

    int a = 1;
    int b = 2;
    int temp = 0;

    for (int i = 3; i < arr + 1; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    int len;
    
    cin >> len;
    int arr[len];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int temp;
    for (int i = 0; i < len; i++)
    {
        temp = achieve_stair(arr[i]);
        cout << temp << endl;
    }

    return 0;
}
