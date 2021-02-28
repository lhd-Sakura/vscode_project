/*
    单源最短路径
    图的构造

*/

#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int to, cost;
};

const int MAX = 1000;

vector<edge> G[MAX]; // 图
int V;               // 顶点数
int E;               // 边数

void creat()
{
    // 因为只是支持顶点 0 ~ n， 如果顶点是 1 ~ n, 自行更改 只要把顶点的值减 1 就行了
    // 这里假设是 0 ~ n
    cin >> V >> E;
    for (int i = 0; i < E; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge e;
        e.to = to;
        e.cost = cost;
        G[from].push_back(e);
    }
}

int main()
{
    creat();
    return 0;
}
