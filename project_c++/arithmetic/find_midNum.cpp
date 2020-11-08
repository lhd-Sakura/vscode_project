/*
    分治法
    【问题描述】给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
    【输入形式】三行，第一行是两个数组的大小，第二行是第一个数组元素，第二行是第二个数组元素
    【输出形式】两个正序数组的中位数，两个数组如果是都是偶数，则返回位置元素，元素下标从0开始，[]表示向下取整
    【样例输入】

     2 2

     1 2

      3 4

   【样例输出】

    2
    【样例说明】 中位数为2

*/
#include <iostream>

using namespace std;

void bubble_sort(int len_x, int len_y, int *arr_x, int *arr_y)
{

    //cout << "bubble_sort" << endl;
    //数组连接
    int len = len_x + len_y;
    int arr[len];
    for (int i = 0; i < len_x; i++)
    {
        arr[i] = arr_x[i];
    }

    for (int i = len_x; i < len; i++)
    {
        arr[i] = arr_y[i - len_x];
    }

    //外圈循环，总共进行size-1次
    for (int i = 0; i < len - 1; i++)
    {

        //内圈循环，每次进行size-i-1次
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr[i];
    // }

    if (len % 2 == 1)
    {
        cout << arr[(int)(len / 2)];
    }

    if (len % 2 == 0)
    {
        cout << arr[(int)(len / 2) - 1];
    }
}

int main(int argc, char const *argv[])
{
    int len_x, len_y;

    //cout << "len_x,len_y" << endl;
    cin >> len_x;
    cin >> len_y;

    int arr_x[len_x], arr_y[len_y];

    //cout << "arr_x,arr_y" << endl;
    for (int i = 0; i < len_x; i++)
    {
        cin >> arr_x[i];
    }

    for (int i = 0; i < len_y; i++)
    {
        cin >> arr_y[i];
    }

    bubble_sort(len_x, len_y, arr_x, arr_y);

    return 0;
}
