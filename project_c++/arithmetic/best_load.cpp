/*
    最优装载

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//将集装箱重量从小到大排序，t存入的是排序后的集装箱的原有索引。
void Sort(int w[],int t[],int n)
{
    for(int i = 1;i < n;i++)
    {
        for(int j = 1;j < n - i;j++)
        {
            if(w[i] > w[j])
            {
                swap(w[i],w[j]);
                swap(t[i],t[j]);
            }
        }
    }
}
void Loading(int x[],int w[],int t[],int n,int c)
{
    int *t = new int[n + 1];
    Sort(w,t,n);
    for(int i = 1;i <= n;i++)
        x[i] = 0;//表示没有装载任何一个集装箱
    for(int i = 1;i <= n && w[t[i]] <= c;i++)
    {
        x[t[i]] = 1;//搬上船的集装箱在其对应位置标记为1
        c -= w[t[i]];
    }
}

