/*
    回溯算法

    定义问题的解空间（{x1,x2...xn}  显约束xi=1,2...m(i=1,2...n)  n个点 m 种颜色
    解空间的组织结构： 满m叉树 ---深度为 n.
    搜索解空间     
    约束条件---当前节点在第t层--
    判断第t个节点颜色与前t-1个节点中与其有边相连的节点颜色是否相同，
    若有颜色相同 则需要换下一个色号尝试，  
    限界条件----只是找可行就行了，因此不需要找最少颜色。如果需要，进一步简单优化即可。

*/

#include <iostream>
#include <string.h>

#define N 50
using namespace std;
int x[N];       //记录每个节点的颜色
int map_[N][N]; //邻接矩阵存储无向图
int sum = 0;    //存在方案数
int n, m, edge; //n个节点，m种颜色，edge个边

void CreatMap()
{
    int u, v;
    memset(map_, 0, sizeof(map_));
    for (int i = 0; i < edge; i++)
    {
        scanf("%d%d", &u, &v);
        map_[u][v] = map_[v][u] = 1;
    }
}

bool Ok(int t)
{
    for (int j = 1; j < t; j++)
    {
        if (map_[t][j]) //t与j相邻接
        {
            if (x[j] == x[t]) //t与j着色是否相同
                return false;
        }
    }
    return true;
}

void Backtrack(int t)
{
    if (t > n) //到达叶子，找到第一个着色方案
    {
        sum++;
        //printf("第%d种方案:",sum);
        cout << "第" << sum << "种方案" << endl;

        for (int i = 1; i <= n; i++)
            printf("%d ", x[i]);
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= m; i++) //每个节点尝试每个颜色
        {
            x[t] = i;
            if (Ok(t)) //深度优先，当前颜色可行，则下一个节点
                Backtrack(t + 1);
        }
    }
}
int main()
{
    cin >> n >> m >> edge;
    CreatMap();
    Backtrack(1);
}