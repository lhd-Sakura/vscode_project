/*
    静态成员变量

    所有对象都共享一份数据
    编译阶段就分配内存
    类内声明，类外初始化操作

    静态成员变量不属于某一个对象上，所有对象都共享同一份数据
    因此静态成员变量共有两种访问方式
        1.通过对象进行访问
        2.通过类名进行访问
            Person::m_A


    静态成员变量也是有访问权限的



    静态成员函数
        所有对象共享同一个函数
        静态成员函数只能访问静态成员变量
            静态成员函数可以访问 静态成员变量   
            不能访问非静态成员变量 无法区分到底是哪个对象的成员

        静态成员变量也是有访问权限的





*/

#include <iostream>

using namespace std;


class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();

    static int m_A;

    static void func()
    {
        cout<<"static void func调用"<<endl;

    }



};


Person::Person(/* args */)
{
}

Person::~Person()
{
}

//类外初始化
int Person::m_A = 100;


void test01()
{
    Person p;
    cout << p.m_A << endl;

    //对象共享同一个数据
    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;

    cout << Person::m_A << endl;


    p.func();
    Person::func();








}





int main(int argc, char const *argv[])
{
    
    test01();
    return 0;
}










