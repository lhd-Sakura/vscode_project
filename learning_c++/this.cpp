/*
    成员变量和成员函数分开存储

    空对象占用空间为：1     sizeof(p)
    C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置

    非静态成员函数 不属于类对象上
    并且每个非静态成员函数只会诞生一份函数实例，对于不同类的区分就会产生问题

    C++通过提供特殊的对象指针，this指针，解决上述问题
    this指针指向被调用的成员函数所属的对象

    this指针是隐含每一个非静态成员函数内的一种指针
    this指针不需要定义，直接使用即可


    用途：
        当形参和成员变量同名是，可以用this指针来区分
        在类的非静态成员函数中返回对象本身，可以用   return *this



    使用空指针可以访问类中的成员，但是不能访问成员变量
    对 this 指针进行判断
        if(this == NULL)
            return;

    提高代码健壮性，即使传入空指针代码也不会崩溃

    this指针本质是指针常量  指针的指向是不可以修改的


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

    Person(int age)
    {
        this->age = age;
    }

    //如果没有 &    会调用拷贝构造函数构造出一个另外的Person    并不会出现累加，输出的值为20
    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;
        return *this;

    }


    int age;    //或者将 age 换成 m_Age 好的编码习惯

};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01()
{
    Person p1(18);
    cout<<"p1的年龄为："<<p1.age<<endl;


}


void test02()
{
    Person p1(10);
    Person p2(10);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout<<"p2的年龄为："<<p2.age<<endl;

}



int main(int argc, char const *argv[])
{
    test01();
    test02();

    return 0;
}




