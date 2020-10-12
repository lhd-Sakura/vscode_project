/*
    占位参数，在函数中声明变量类型
    如下面，函数中的int

    占位参数 还可以有默认参数

*/

#include <iostream>

using namespace std;

void func(int a, int)
{
    cout << "这是一个高级函数实例" << endl;
}

int main(int argc, char const *argv[])
{
    func(10, 10);
    return 0;
}
