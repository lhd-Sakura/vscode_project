/*
    在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容

    可以将虚函数改为纯虚函数

    有了纯虚函数，这个类称为抽象类

    抽象类特点：
        抽象类无法实例化对象
        子类必须重写抽象类中的纯虚函数，否则也属于抽象类


*/
#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void func() = 0;//纯虚函数

};

class Son : public Base
{
    virtual void func()
    {
        cout << "func函数调用" << endl;
    }
};

void test01()
{
    Base *base = new Son;
    base->func();
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}


