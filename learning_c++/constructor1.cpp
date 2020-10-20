/*
    构造函数的分类和调用

    分类：
        按照参数分类    无参构造（默认构造） 和 有参构造
        按照类型分类    普通构造 和 拷贝构造

    调用构造参数
        括号法
        显示法
        隐式转化法

    注意事项
        调用默认构造函数时候，不要加（）
        因为下面这行代码，编译器会认为是一个函数的声明
        不要利用拷贝构造函数 初始化匿名对象 编译器会认为



    构造函数调用规则：
        1.创建一个类，C++编译器会给每个类都添加至少3个函数
            默认构造（空实现）
            析构函数（空实现）
            拷贝构造（值拷贝）

        如果我们写了有参构造函数，编译器就不在提供默认构造，依然提供拷贝构造

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
    Person( const Person &p );
    ~Person();
};

Person::Person(/* args */)
{
    cout<<"Person 无参构造函数的调用"<<endl;
}

Person::Person(int a)
{
    age = a;
    cout<<"Person 有参构造函数的调用"<<endl;
}

Person::~Person()
{
    cout<<"Person 析构函数的调用"<<endl;
}

Person::Person( const Person &p )
{
    age = p.age;
    cout<<"Person 拷贝构造函数的调用"<<endl;

};

void test01()
{
    Person p1;//默认构造函数的调用
    Person p2(10);//有参构造函数
    Person p3(p1);//拷贝构造函数

    Person p4 = Person(10);
    Person p5 = Person(p1);

    //隐式转换法
    Person p6 = 10; //相当于 写了 Person p6 = Person (10);
    Person p7=p6;   //拷贝构造

    Person(10);//匿名对象，当前行执行结束后，系统会立即回收掉匿名对象

    cout<<"p2:"<<p2.age<<endl;
    cout<<"p3:"<<p3.age<<endl;

}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
















