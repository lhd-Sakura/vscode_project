/*
    函数基础
    num1和num2并没有真实数据
    只是一个形式上的参数，简称形参

    a，b称为实参

    如果函数放在main函数后面，需要在文件开头提前声明函数
    声明函数加 ; 否则编译器会报错

    或者添加头文件，在相应的头文件中进行声明


    

*/

#include <iostream>

#include "fun_add.h"


using namespace std;





int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 10;

    int c = add(a, b);

    cout << c << endl;
    return 0;
}


int add(int num1,int num2)
{
    int sum = num1 + num2;
    return sum;
}










