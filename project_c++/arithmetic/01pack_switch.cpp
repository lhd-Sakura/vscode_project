#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
struct Res
{
    int weight, value;
    bool used = false;
};
struct Bags
{
    vector<Res *> bags;
    int nweigt, nvalue = 0, ub;
    Bags operator+(Res *&res)
    {
        Bags bag = *this;
        bag.bags.push_back(res);
        bag.nweigt -= res->weight;
        bag.nvalue += res->value;
        return bag;
    }
};


int main()
{
    Res thing[] = {{4, 40}, {7, 42}, {5, 25}, {3, 12}};
    vector<Res *> res;
    vector<Bags> result;
    for (auto &it : thing)
        res.push_back(&it);
    int W = 13;
    sort(res.begin(), res.end(), [](Res *&a, Res *&b) { return a->value / a->weight > b->value / b->weight; }); //优先排序
    Bags start;
    int up = W * res.front()->value / res.front()->weight, down = 0;
    for (int i = 0, w = W; i < res.size(); i++)
    { //贪心获取下界
        if (res[i]->weight < w)
        {
            down += res[i]->value;
            w -= res[i]->weight;
        }
    }
    start.ub = up;
    start.nweigt = W;
    int size, count = 0;
    queue<Bags> q;
    q.push(start);
    while (!q.empty() && count < res.size())
    {
        size = q.size(); //记录每层的节点数，进行层处理
        for (int i = 0; i < size; i++)
        {
            Bags right = q.front();
            if (right.nweigt - res[count]->weight >= 0)
            {
                Bags left = right + res[count];                                                                                        //左节点
                left.ub = left.nvalue + (count + 1 < res.size() ? left.nweigt * (res[count + 1]->value / res[count + 1]->weight) : 0); //无法访问最后一层的count+1，值为0
                q.push(left);
            }
            right.ub = right.nvalue + (count + 1 < res.size() ? right.nweigt * (res[count + 1]->value / res[count + 1]->weight) : 0); //修改右结点
            if (right.ub > down)
                q.push(right);
            else
                result.push_back(right);
            q.pop();
        }
        count++;
    }
    Bags *minBag = nullptr;
    for (int i = 0; i < result.size(); i++)
    { //在表中寻找最优方案
        if (minBag == nullptr || result[i].nvalue > minBag->nvalue)
            minBag = &result[i];
    }
    for (auto &it : minBag->bags)
        it->used = true;
    cout << "分支限界法求得最大价值为：" << minBag->nvalue << endl;
    for (int i = 0; i < res.size(); i++)
        cout << "物品" << i + 1 << "是否被选：" << thing[i].used << endl;
    return 0;
}