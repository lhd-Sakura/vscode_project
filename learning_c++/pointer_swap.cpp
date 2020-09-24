/*
    本教程旨在说明修改实参的方法
    在swap01中仅对传入的形参进行交换，实际上并不改变实参a，b的值
    但在swap02中，传入的变量为指针，可以修改实参的值


*/



#include <iostream>

using namespace std;

void swap01(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;

}

void swap02(int *p1,int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;

    swap01(a, b);

    cout << "a的值：" << a << endl;
    cout << "b的值：" << b << endl;

    swap02(&a, &b);
    cout << "a的值：" << a << endl;
    cout << "b的值：" << b << endl;


    return 0;
}









