/*
    设计一个学生类，属性有姓名和学号，
    可以给姓名和学号赋值，
    可以显示学生的姓名和学号



*/

#include <iostream>

using namespace std;


class Student
{
    public:
        string name;
        int id;
        
        void showStudent()
        {
            cout<<"姓名："<<name<<"\t学号："<<id<<endl;
        }

        void setStudent(string sname,int sid)
        {
            name=sname;
            id=sid;

        }


};

int main(int argc, char const *argv[])
{
    Student s1;
    s1.name="祁进";
    s1.id=1034180113;

    s1.showStudent();

    Student s2;
    s2.setStudent("沈剑心",1034180113);
    s2.showStudent();
    
    return 0;
}










