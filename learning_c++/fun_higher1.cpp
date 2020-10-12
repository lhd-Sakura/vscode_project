/*
    函数高级，函数的默认参数
    如果给函数中赋值了，就按照传入的值进行计算，否则就使用默认值
    默认参数

    1.如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须由默认值
    2.如果函数声明有默认参数，函数实现就不能有默认参数
        先让编译器有这个函数，在头文件
        声明一次后，编译器就已经知道函数的默认参数
        只能一个有，不能同时拥有 


*/

#include <iostream>

using namespace std;

int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

int main(int argc, char const *argv[])
{
    int a;
    a = func(10, 30);
    cout << a << endl;
    return 0;
}
