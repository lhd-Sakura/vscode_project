/*
    分治法
    3.
    在未排序的N个整数中找到第 k个最大的元素。请注意，你需要找的是排序后的第 k 个最大的元素，而不是第 k 个不同的元素

    采用冒泡排序

*/
#include <iostream>

using namespace std;

void bubble_sort(int len, int *arr, int k)
{

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

    cout << arr[len - k];
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
    int k;
    cin >> k;

    bubble_sort(len, arr, k);

    return 0;
}
