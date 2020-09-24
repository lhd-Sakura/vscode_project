/*
    冒泡排序
    比较相邻的元素，如果第一个比第二个打，就交换他们两个
    找到最大值
    重复以上的步骤

    每次冒泡排序能够确定一列数字的最大值，冒泡到最后一位
    重复多次实现冒泡排序

    冒泡排序大体分为两轮，外圈循环和内圈循环

*/



#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int arr[] = {9,8,7,6,5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    //外圈循环，总共进行size-1次
    for (int i = 0; i < size-1;i++)
    {

        //内圈循环，每次进行size-i-1次
        for (int j = 0; j < size - i - 1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;

            }   

        }
    }

    for (int i = 0; i < size;i++)
    {
        cout << arr[i] << endl;

    }

        return 0;
}




