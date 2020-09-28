/*

    basic struct practise


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
    cout << s2.name << endl;
    cout << s2.age << endl;
    cout << s2.score << endl;


    return 0;
}
