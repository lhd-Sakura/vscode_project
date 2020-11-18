/*
    动态规划
    2.数字塔

    在数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。
    路径上的每一步都只能往左下或者右下走。只需要求出这个最大和即可，不必给出路径。
    三角形的行数大于1小于等于100，整数为0~99

    自下而上，一维数组滚动
    最大值为 temp[0]

    7 
    3 8
    8 1 0

    传入参数（二维数组）实现

*/

#include <iostream>

using namespace std;

void digital_tower(int len, int *arr)
{
    int temp[len];

    for (int i = 0; i < len; i++)
    {
        temp[i] = arr[(len - 1) * len + i];
    }
    //从 n-1 开始累加
    for (int i = len - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            temp[j] = max(temp[j], temp[j + 1]) + arr[i * len + j];
        }
    }

    cout << temp[0];
}

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    int arr[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    //显示输入的数塔
    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout<< arr[i][j]<<" ";
    //     }

    //     cout << endl;
    // }

    digital_tower(len, *arr);

    return 0;
}
