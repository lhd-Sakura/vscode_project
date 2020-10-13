/*
    在类中的通用函数接口设置私有变量
    并通过公有方法进行访问

    通过变量和变法的配合，设置变量的访问权限
    set
    get

*/

#include <iostream>

using namespace std;

class student
{
private:
    string name = "沈剑心";
    int score;

public:
    //名字只读

    void readName()
    {
        cout << name << endl;
    }

    //分数读写
    void readScore()
    {
        cout << score << endl;
    }

    void setScore(int sScore)
    {
        score = sScore;
    }
};

int main(int argc, char const *argv[])
{
    student s1;
    s1.readName();
    s1.setScore(100);
    s1.readScore();

    return 0;
}
