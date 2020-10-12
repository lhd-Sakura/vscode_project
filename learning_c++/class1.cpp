/*
    面向对象：封装、继承、多态
    c++认为万事万物都皆为对象，对象上有其属性和行为

    封装：
        将属性和行为作为一个整体，表现生活中的事物
        将属性和行为加以权限控制
        在设计类时，将属性和行为写在一起，表现事物

    类中的属性和行为 统称为成员
    属性 成员属性 成员变量
    行为 成员函数 成员方法


*/

#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle
{
public:
    int r;
    double calculateZC()
    {
        return 2 * PI * r;
    }
};

int main(int argc, char const *argv[])
{
    Circle c1;
    c1.r = 10;
    cout << "圆的周长为：" << c1.calculateZC() << endl;

    return 0;
}
