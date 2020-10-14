/*

    对象的初始化和清理
        1.构造函数 进行初始化操作
            没有返回值 不用写void 
            函数名 与类名相同
            构造函数可以有参数，可以发生重载
            创建对象的时候，构造函数会自动调用，而且只调用一次

        2.析构函数 进行清理的操作
            没有返回值 不写void
            函数名和类名相同 在名称前面加 ~
            析构函数不可以有参数，不可以发生重载
            对象在销毁前 会自动调用析构函数，而且只会调用一次



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
};

Person::Person(/* args */)
{
    cout<<"Person 构造函数的调用"<<endl;
}

Person::~Person()
{
    cout<<"Person 析构函数的调用"<<endl;
}


void test01()
{
    Person p1;

}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}




















