/*
    斐波那契    分治法

    从n(>2)开始计算，用F(n-1)和F(n-2)两个数相加求出结果，
    这样就避免了大量的重复计算，它的效率比递归算法快得多，
    算法的时间复杂度与n成正比，即算法的时间复杂度为O(n).

*/

#include <iostream>
#include <stdio.h>

//Fibonacci数列非递归 C++ 实现
using namespace std;

void fib(int n)
{
	if (n == 0)
		cout << "0" << endl;
	if (n == 1)
		cout << "1" << endl;
	int f1 = 1;
	int f2 = 0;
	int fn = 0;
	cout << "0 1"
		 << " ";
	for (int i = 2; i < n; i++)
	{
		fn = f2 + f1;
		f2 = f1;
		f1 = fn;
		cout << fn << " ";
	}
}

int main()
{
	int num;
	cout << "请输入一个整数：" << endl; //表示要求的是数列中的第几个数。

	cin >> num;
	//cout << fib(num) << endl;
	fib(num);
	return 0;
}
