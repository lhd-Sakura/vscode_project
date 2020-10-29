/*
    菱形继承问题

    Animal  基类
    Sheep   继承基类
    Tuo     继承基类
    SheepTuo    同时继承上面两个类



    利用虚继承 解决菱形继承的问题
    继承之前 加上关键字 virtual 变为虚继承
    Animal  称为虚基类

        class Sheep : virtual public Animal{}


    虚继承 继承了一个指针 指针通过偏移量 指向唯一的数据
    解决数据重名的冲突


*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    return 0;
}



