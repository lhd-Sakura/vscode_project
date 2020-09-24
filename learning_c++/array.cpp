/*
    数据类型  数组名【 数组长度 】 = {值1.值2，。。。}；
    数据类型  数组名【  】 = {值1.值2，。。。}；

*/


#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    cout << "array" << endl;

    int arr2[5] = {10, 20, 30, 40, 50};
    int arr3[] = {10, 20, 30, 40, 50};

    cout << "整个数组占用内存空间为：" << sizeof(arr3) << endl;
    cout << "数组首地址为：" << arr3 << endl;
    cout << "数组首地址为：" << (long long int)arr3 << endl;
    cout << "数组第一个元素的首地址为：" << (long long int)&arr3[0] << endl;

    return 0;
}
