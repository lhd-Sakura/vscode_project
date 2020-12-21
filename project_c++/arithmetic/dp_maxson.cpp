/*
    动态规划最长上升子序列
    
    【题目描述】

    给定N个数，求这N个数的最长上升子序列的长度。

    【样例输入】

    7

    2 5 3 4 1 7 6

    【样例输出】

    4

*/
#include <cstdio>
const int MAX = 1001;
int a[MAX];
int lis(int x)
{
    int num[MAX];
    for (int i = 0; i < x; i++)
    {
        num[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && num[j] + 1 > num[i])
                num[i] = num[j] + 1;
        }
    }
    int maxx = 0;
    for (int i = 0; i < x; i++)
        if (maxx < num[i])
            maxx = num[i];
    return maxx;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return !printf("%d\n", lis(n));
}
