#include <ctime>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;
#define N 100000

int weights[N], values[N]; // 把物品重量和价值定义为双精度浮点数
int cw, cp;
int MaxWeight = 15; //cw 为当前重量， cp 为当前价值，定义背包容量为 30
int Items = 6;      // 货物数量为 3

string weight_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/weights2.txt";
string values_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/values2.txt";

class HeapNode // 定义 HeapNode 结点类
{
public:
    double
        upper,
        price, weight; //upper 为结点的价值上界， price 是结点所对应的价值， weight 为结点所相应的重量
    int level, x[N];   // 活节点在子集树中所处的层序号
};

stack<HeapNode> High; // 最大队 High

double MaxBound(int j) //MaxBound 函数求最大上界
{
    double
        left = MaxWeight - cw,
        b = cp;                              // 剩余容量和价值上界
    while (j <= Items && weights[j] <= left) // 以物品单位重量价值递减装填剩余容量
    {
        left -= weights[j];
        b += values[j];
        j++;
    }
    if (j <= Items)
        b += values[j] / weights[j] * left; // 装填剩余容量装满背包
    return b;
}

void AddLiveNode(double up, double cp, double cw, bool ch, int lev)
//将一个新的活结点插入到子集数和最大堆 High 中
{
    HeapNode be;
    be.upper = up;
    be.price = cp;
    be.weight = cw;
    be.level = lev;
    if (lev <= Items)
        High.push(be); // 调用 stack 头文件的 push 函数
}

double Knap() // 优先队列分支限界法，返回最大价值， bestx 返回最优解
{
    int i = 1;
    cw = cp = 0;
    double
        bestp = 0,
        up = MaxBound(1); // 调用 MaxBound 求出价值上界， best 为最优值
    while (1)             // 非叶子结点
    {
        double wt = cw + weights[i];
        if (wt <= MaxWeight) // 左儿子结点为可行结点
        {
            if (cp + values[i] > bestp)
                bestp = cp + values[i];
            AddLiveNode(up, cp + values[i], cw + weights[i], true, i + 1);
        }
        up = MaxBound(i + 1);
        if (up >= bestp) // 右子数可能含最优解
            AddLiveNode(up, cp, cw, false, i + 1);
        if (High.empty())
            return bestp;
        HeapNode node = High.top(); // 取下一扩展结点
        High.pop();
        cw = node.weight;
        cp = node.price;
        up = node.upper;
        i = node.level;
    }
}

void read_text(int *nums, string location)
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败：" << endl;
    }

    int num;
    int i = 0;
    while (ifs >> num)
    {
        i++;
        nums[i] = num;
    }

    ifs.close();
}

int main()
{
    read_text(weights, weight_txt);
    read_text(values, values_txt);

    clock_t startTime, endTime;
    startTime = clock();    //计时结束
    cout << Knap() << endl; // 调用 knap 函数 输出最大价值
    endTime = clock();      //计时结束
    cout << "The run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}