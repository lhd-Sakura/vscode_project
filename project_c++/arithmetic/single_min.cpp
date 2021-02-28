/*
    单源最短路径
    Dijkstra(优先队列的优化)



*/
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
 
using namespace std;
 
struct edge{
	int to, cost;
};
 
typedef pair<int, int> P;
const int MAX = 10001;
const int INF = 0x3f3f3f3f; // 假设这是无法到达某一点的距离
 
vector<edge> G[MAX]; // 图
int d[MAX];
int used[MAX];
int V; // 顶点数
int E; // 边数
int s; // 出发的点
 
void creat(){
	// 因为只是支持顶点 0 ~ n， 如果顶点是 1 ~ n, 自行更改 只要把顶点的值减 1 就行了
	// 这里假设是 0 ~ n
	cin >> V >> E >> s;
	for(int i = 0; i < E; ++i){
	    int from, to, cost;
	    cin >> from >> to >> cost;
	    edge e;
	    e.to = to;
	    e.cost = cost;
	    G[from].push_back(e);
	}
}
 
void Dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que; // 要空一个格
    fill(d, d + V, INF);
    que.push(P(0, s));
    d[s] = 0;
 
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second; // first 储存最短距离 second 储存的是顶点的坐标
        if(d[v] < p.first) continue; // 一直寻找，直到找到符合最短距离的 v 点
        for(int i = 0; i < (int)G[v].size(); ++i){
            edge e = G[v][i]; // v -> e.to 的边
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
 
void solve(){
	creat();
	Dijkstra(s);
	for(int i = 0; i < V; ++i) cout << d[i] << ' '; // 输出到达各个顶点的最短距离， 如果无法到达结果为 INF
}
int main(){
	solve();
	return 0;
}


