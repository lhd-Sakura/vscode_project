/*
    结构体数组
    定义结构体后要加 ；

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
    student stu1[3] =
        {
            {"张三", 18, 100},
            {"祁进", 18, 99},
            {"谷之岚", 18, 99}};

    student stu2[2];
    stu2[1].name = "沈剑心";
    stu2[1].age = 18;
    stu2[1].score = 100;

    for (int i = 0; i < 3; i++)
    {
        cout << stu1[i].name << " " << stu1[i].age << " " << stu1[i].score << endl;
    }
    





    return 0;
}














