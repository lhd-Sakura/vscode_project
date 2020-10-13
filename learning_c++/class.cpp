/*
    访问权限
    public      成员在类内可以访问 类外也可以访问
    protected   成员 类内可以访问 类外不可以访问（父类的东西 子类也可以访问）
    private     成员 类内可以访问 类外不可以访问

    在c++中struct和class唯一的区别就在于默认的访问权限不同
    区别：
        struct默认权限为公共
        class默认权限为私有

    
    成员属性设置为私有
        可以自己i控制读写权限
        对于写可以检测数据的有效性


*/

#include <iostream>

using namespace std;

class Person
{

private:
    int password;


protected:
    string car;


public:
    void p_name()
    {
        name = "张三";
        car = "奔驰";
        password = 123456;
    }

    void p_printf()
    {
        cout<<name<<"\t"<<car<<"\t"<<password<<endl;
    }


    string name;

};




int main(int argc, char const *argv[])
{

    Person p1;
    p1.p_name();
    p1.p_printf();
    
    return 0;
}














