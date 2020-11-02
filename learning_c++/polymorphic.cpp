/*
    C++多态
    多态是C++面向对象三大特性之一
    多态分哇两类
        静态多态：函数重载和运算符重载属于静态多态，复用函数名
        动他多态：派生类和虚函数实现运行时多态

    静态多态和动态多态区别：
        静态多态的函数地址早绑定    -   编译阶段确定函数地址
        动态多态函数地址晚绑定      -   运行阶段确定函数地址

        virtual 关键字
        

    动态多态满足条件
        1.有继承关系
        2.子类重写父类的虚函数

    重写 函数返回值类型 函数名 参数列表 完全相同

    动态多态使用
        父类中引用指向子类的对象


*/

#include <iostream>

using namespace std;

class Animal
{
private:
public:
    //虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
private:
    /* data */
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
    private:
    public:
        void speak()
        {
            cout << "小狗在说话" << endl;
        }
};



//地址早绑定，在编译阶段确定地址
void doSpeak(Animal &animal)
{
    animal.speak();
}




void test01()
{
    Animal animal;
    doSpeak(animal);
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
