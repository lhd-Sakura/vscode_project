/*
    多继承
    多继承可能会引父类中有同名成员出现，需要加作用域区分

    实际开发中不建议使用多继承

        class Son : public Base1, public Base2

        class 子类: 继承方式 父类1 , 继承方式 父类2

    
    不同父类同名函数的访问
        p.Base1::m_A
        p.Base2::m_B



*/

#include <iostream>

using namespace std;

class Base1
{
private:
    /* data */
public:
    Base1(/* args */);
    ~Base1();
};



Base1::Base1(/* args */)
{
}

Base1::~Base1()
{
}








int main(int argc, char const *argv[])
{


    
    return 0;
}





