/*
    学校做毕设项目，老师带5个学生
    设计学生老师的结构体，在老师结构体，有老师姓名和存放5学生的数组作为生源
    
    通过函数给每个老师及所带学生赋值
    最终打印出老师数据以及老师所带学生数据


*/

#include <iostream>

using namespace std;

struct Student
{
    string sName;
    int score;
};

struct Teacher
{
    string tName;
    struct Student sArray[3];
};

void allocateSpace(Teacher *tArray, int sLen)
{

    // //for循环赋值teacher
    // // += 运算符  好！很有精神
    // string nameSeed = "ABCDE";

    // for (int i = 0; i < len; i++)
    // {
    //     tArray[i].tName = "Teacher_";
    //     tArray[i].tName += nameSeed[i];
    // }

    cout << "老师姓名" << endl;
    cin >> tArray->tName;

    for (int i = 0; i < sLen; i++)
    {
        cout << "学生" << i + 1 << "的信息：" << endl;
        cout << "姓名" << endl;
        cin >> tArray->sArray[i].sName;
        cout << "分数" << endl;
        cin >> tArray->sArray[i].score;
    }
}

void printInf(Teacher *tArray, int tLen, int sLen)
{
    for (int i = 0; i < tLen; i++)
    {
        cout << "老师" << i + 1 << "的姓名为：";
        cout << tArray[i].tName << endl;

        cout << "所带学生姓名及分数:" << endl;
        for (int j = 0; j < sLen; j++)
        {
            cout << tArray[i].sArray[j].sName << " " << tArray[i].sArray[j].score << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    Teacher tArray[2];
    int tLen = sizeof(tArray) / sizeof(tArray[0]);
    int sLen = sizeof(tArray->sArray) / sizeof(tArray->sArray[0]);

    for (int i = 0; i < tLen; i++)
    {
        cout << "老师" << i + 1 << "的信息：" << endl;
        allocateSpace(&tArray[i], sLen);
    }

    printInf(tArray, tLen, sLen);

    return 0;
}
