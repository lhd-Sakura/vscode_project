/*
    分治法
    5.
    【问题描述】给定一个整数数组 nums，按要求返回一个新数组 counts。
    数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

*/

#include <iostream>

using namespace std;

void right_compare(int len, int *arr)
{
    int arr2[len];
    int num;

    for (int i = 0; i < len; i++)
    {
        num = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
                num++;
        }
        arr2[i] = num;
    }

    for (int i = 0; i < len; i++)
    {
        cout << arr2[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    //输入数组长度和数组
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    right_compare(len, arr);

    return 0;
}
