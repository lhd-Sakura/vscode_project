/*
    初始化列表
    C++提供了初始化列表语法，用来初始化属性

    C++类中成员可以是另一个类的对象，我们成该成员为对象成员
    当其他类对象作为本类成员，构造时候先构造类对象，再构造自身。 析构的顺序与构造相反

*/

#include <iostream>

using namespace std;

class Person
{
public:
    Person() : m_A(10), m_B(20), m_C(30)
    {
    }

    int m_A;
    int m_B;
    int m_C;

};

void test01()
{
    Person p;
    cout << "m_A = " << p.m_A << endl;
    cout << "m_B = " << p.m_B << endl;
    cout << "m_C = " << p.m_C << endl;
}

int main(int argc, char const *argv[])
{
    test01();

    return 0;
}
