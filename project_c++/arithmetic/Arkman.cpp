/*
    阿克曼函数
    递归


*/
#include <iostream>
using namespace std;

//声明Ackerman函数
int Ackerman(int m, int n);

//主函数
void main()
{
    int m, n;
    cout << "请输入m、n的值：";
    cin >> m >> n;
    cout << "Ackerman函数的结果为：";
    cout << Ackerman(m, n) << endl;
}

//Ackerman函数
int Ackerman(int m, int n)
{
    if (0 == m)
        return n + 1; //若m=0，则返回n+1的值
    else
    {
        if (m > 0 && 0 == n)
            return Ackerman(m - 1, 1); //若m>0且n=0，则返回Ackerman（m-1，1）的值
        else if (m > 0 && n > 0)
            return Ackerman(m - 1, Ackerman(m, n - 1)); //若m>0且n>0，则返回Ackerman(m - 1,Ackerman(m, n - 1))的值
    }
}
