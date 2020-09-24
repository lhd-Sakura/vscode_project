/*

    指针的基础语法

    &取址   *取内容

    指针在32位操作系统下：占用4个字节空间，64位占用8个字节

    空指针用于给指针变量进行初始化
    空指针是不可以进行访问的(不能使用 * 对指针所指空间进行访问，但可以改变指针所指空间)

    野指针：指针变量指向非法的内存空间
    空指针和野指针都不是我们申请的空间，因此不要访问



*/



#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 10;
    int *p;

    p = &a;

    *p = 100;

    cout << p << endl;
    cout << *p << endl;

    cout << "指针占用空间为：" << sizeof(int *) << endl;
    cout << "指针占用空间为：" << sizeof(float *) << endl;
    cout << "指针占用空间为：" << sizeof(double *) << endl;
    cout << "指针占用空间为：" << sizeof(char *) << endl;

    int *p1 = NULL;
    p1 = p;
    cout << "指针占用空间为：" << *p1 << endl;


    // //野指针
    // //在程序中，尽量避免出现野指针
    // int *P = (int *)0x1100;
    // cout << *p << endl;


    return 0;
}




