/*

    地图着色问题

*/

#include <iostream>
using namespace std;
#define N 64
int main()
{
    int a[N][N], i, j, k, n, b, c, d, e, f, cq[N], result[N], newr[N], front, rear, group, pre;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 0;
    cout << "请输入地图区域个数" << endl;
    cin >> n;
    cout << "各区域编号分别为：" << endl;
    for (i = 0; i < n; i++)
        cout << i + 1 << ", ";
    cout << "请输入各个区域的接壤情况(结束输入请输入'0')" << endl;
    i = 0;
    while (1)
    {
        cout << "第" << i + 1 << "组相邻区域编号为:" << endl;
        cin >> b;
        if (b == 0)
            break;
        cin >> c;
        a[b - 1][c - 1] = 1;
        a[c - 1][b - 1] = 1;
        i++;
    }
    cout << "地图组成的邻接矩阵为：" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    for (i = 0; i < N; i++)
        cq[i] = i + 1;
    front = N - 1;
    rear = N - 1;
    for (i = 0; i < N; i++)
        newr[i] = 0;
    group = 1;
    pre = 0;
    f = 0;
    while (rear != front || f == 0)
    {
        f = 1;
        front = (front + 1) % N;
        i = cq[front];
        if (i < pre)
        {
            group++;
            result[i - 1] = group;
            for (j = 0; j < N; j++)
                newr[j] = a[i - 1][j];
        }
        else
        {
            if (newr[i - 1] != 0)
            {
                rear = (rear + 1) % N;
                cq[rear] = i;
            }
            else
            {
                result[i - 1] = group;
                for (j = 0; j < N; j++)
                    newr[j] = newr[j] + a[i - 1][j];
            }
        }
        pre = i;
    }
    cout << "着色结果为：" << endl;
    for (i = 0; i < n; i++)
    {
        if (result[i] == 1)
            cout << "区域" << i + 1 << "为红色" << endl;
        if (result[i] == 2)
            cout << "区域" << i + 1 << "为蓝色" << endl;
        if (result[i] == 3)
            cout << "区域" << i + 1 << "为黄色" << endl;
        if (result[i] == 4)
            cout << "区域" << i + 1 << "为绿色" << endl;
    }
    system("pause");
    return 0;
}
