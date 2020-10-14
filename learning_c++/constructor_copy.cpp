/*
    拷贝构造函数调用实际
        使用一个已经创建完毕的对象来初始化一个新对象
        值传递的方式给函数参数传值
        值方式返回局部对象



*/

#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int age;
    Person(/* args */);
    Person(int a);
    Person(const Person &p);
    ~Person();
};

Person::Person(/* args */)
{
    cout << "Person 无参构造函数的调用" << endl;
}

Person::Person(int a)
{
    age = a;
    cout << "Person 有参构造函数的调用" << endl;
}

Person::~Person()
{
    cout << "Person 析构函数的调用" << endl;
}

Person::Person(const Person &p)
{
    age = p.age;
    cout << "Person 拷贝构造函数的调用" << endl;
};

void test01()
{
}

// doWork 函数和 test02 函数相结合可以看到在函数值传递中，利用拷贝构造函数复刻一份 person 到 doWork 函数中
void doWork(Person p)
{
}

void test02()
{
    Person p;
    doWork(p);
}

Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}

void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}

int main(int argc, char const *argv[])
{
    //test01;
    test02();
    test03();

    return 0;
}
