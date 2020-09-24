/*

    二维数组

*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //二维数组的定义
    int arr1[2][3];//两行三列
    int arr2[2][3] = {{1, 2, 3} ,{4, 5, 6}};
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};

    int arr4[][3] = {1, 2, 3, 4, 5, 6};


    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            cout << arr2[i][j];

        }
        cout << endl;
    }



    //查看数组占用内存空间大小
    cout << "二维数组占用空间大小：" << sizeof(arr1) << endl;
    cout << "二维数组第一行占用的内存为：" << sizeof(arr1[0]) << endl;
    cout << "每个元素占用的空间为：" << sizeof(arr1[0][0]) << endl;

    cout << "二维数组行数为：" << sizeof(arr1) / sizeof(arr1[0]) << endl;
    cout << "二维数组列数为：" << sizeof(arr1[0]) / sizeof(arr1[0][0]);

    cout << "二维数组第一行首地址为：" << (long long int)arr1 << endl;
    cout << "二维数组第一行首地址为：" << (long long int)arr1[0] << endl;

    return 0;
}





