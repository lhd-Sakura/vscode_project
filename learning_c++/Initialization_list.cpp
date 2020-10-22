/*
    初始化列表
    C++提供了初始化列表语法，用来初始化属性

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
