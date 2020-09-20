#include <iostream>
//#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "判断哪只猪最重" << endl;

    int a = 0;
    int b = 0;
    int c = 0;

    cout << "输入三只猪的重量" << endl;
    cout << "第一只" << endl;
    cin >> a;
    cout << "第二只" << endl;
    cin >> b;
    cout << "第三只" << endl;
    cin >> c;

    if (a > b)
    {
       if (a > c)
       {
           cout << "第一只最重" << endl;
       }
       if (c > a)
       {
           cout << "第三只最重" << endl;
       }
       
       
    }

    if (b > a)
    {
       if (b > c)
       {
           cout << "第二只最重" << endl;
       }
       if (c > b)
       {
           cout << "第三只最重" << endl;
       }
    }   
    




    return 0;
}







