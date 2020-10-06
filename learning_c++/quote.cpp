/*
    引用，取别名 typedef
    1.引用必须要初始化
    2.引用一旦初始化后，就不可以更改了

    引用做函数参数
    引用传递（值传递，地址传递）
    引用传递和地址传递类似，同样能改变实参中的值
    引用对实参取别名，在外部函数中，相当于对实参进行操作
    简化指针修改实参

    引用做函数返回值
    不要返回局部变量的引用
    函数的调用可以作为左值


    引用的本质是指针
    当使用引用时自动转换为 int * const ref = &a;
    指针常量，指针指向不可以修改，内容可改

    ref = 20
    内部发现ref为引用，自动转换为 *ref = 20

    c++推荐引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了




*/

#include <iostream>
using namespace std;

void mySwap03(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    // //引用 basic
    // int a = 10;
    // int &b = a;

    // cout << a << endl;
    // cout << b << endl;

    // b = 20;
    // cout << a << endl;
    // cout << b << endl;

    //引用传递
    int a = 10;
    int b = 20;

    mySwap03(a, b);
    cout << a << endl;
    cout << b << endl;


    //引用做函数的返回值



    return 0;
}
