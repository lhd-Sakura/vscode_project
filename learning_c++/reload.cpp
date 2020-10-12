/*
    函数重载
    提高函数复用性

    条件：
        1.同一个作用域下
        2.函数名称相同
        3.函数参数类型不同 或者 个数不同 或者 顺序不同


    函数的返回值不能作为函数重载的条件


    引用作为重载的条件
        1.



*/
#include <iostream>

using namespace std;

void func()
{
    cout << "func的调用" << endl;
}

void func(int &a)
{
    cout << "func (int) 的调用" << endl;
}

void func(const int &a)
{
    cout<<"func(const int &a)"<<endl;

}


int main(int argc, char const *argv[])
{
    int a=10;
    func();
    func(12);
    func(a);

    return 0;
}
