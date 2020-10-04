/*

    basic struct practise

    结构体同时也可以嵌套结构体
    通过两次 . 进行赋值和访问

    将函数中的形参改为指针，可以减少内存空间，而且不会赋值新的副本出来
    但是函数能对形参中的内容进行修改
    可以通过 const 防止误操作的出现
    例：
        void printStudents(const student *p)
    如此就可以防止传入参数中的内容被修改

    



*/

#include <iostream>

using namespace std;

struct Student
{

    string name;
    int age;
    int score;
};

int main(int argc, char const *argv[])
{
    struct Student s1;
    struct Student s2 = {"张三", 18, 100};
    Student s4;

    cout << s2.name << endl;
    cout << s2.age << endl;
    cout << s2.score << endl;


    return 0;
}
