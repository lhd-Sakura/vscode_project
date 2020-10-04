/*
    结构体指针
    利用操作符 -> 可以通过结构体指针访问结构体属性

*/

#include <iostream>

using namespace std;

struct student
{
    //成员列表
    string name;
    int age;
    int score;
};

int main(int argc, char const *argv[])
{
    student stu1 = {"沈剑心", 18, 100};
    student *p = &stu1;

    cout << stu1.name << " " << stu1.age << " " << stu1.score << endl;
    cout << p->name << " " << p->age << " " << p->score << endl;

    return 0;
}
