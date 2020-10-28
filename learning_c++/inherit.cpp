/*
    C++继承

    继承减少重复的代码
    子类    派生类
    父类    基类

    父类中私有的内容子类无法访问


    继承方式一共有三种：
        公共继承
        保护继承
        私有继承


    公共继承后
        子类无法访问父类中 private 属性
        父类中 public 属性 仍为 public   所有权限没有变化

    保护继承
        父类中所有内容  变为    protected
    
    私有继承
        父类中所有内容  变为    private




    父类中所有非静态成员属性都会被子类继承下去
    父类中私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了


*/

#include <iostream>

using namespace std;

class BasePage
{
private:
    /* data */
public:
    BasePage(/* args */);
    ~BasePage();

    void up(){cout<<"继承实例up"<<endl;}
    void down(){cout<<"继承实例down"<<endl;}
    void left(){cout<<"继承实例left"<<endl;}
    void right(){cout<<"继承实例right"<<endl;}

};

BasePage::BasePage(/* args */)
{
}

BasePage::~BasePage()
{
}


class Java: public BasePage
{
    public:
        void java(){cout<<"继承实例java"<<endl;}

};

class Python : public BasePage
{
    void python(){cout<<"继承实例python"<<endl;}

};


int main(int argc, char const *argv[])
{
    Java j1;
    j1.up();
    j1.down();
    j1.java();
    return 0;
}




