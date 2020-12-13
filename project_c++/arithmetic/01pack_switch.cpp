/*
    01背包
    分支界限法

*/

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

string location = "F:/A_Project/vscode_project/project_c++/arithmetic/text/60000.txt";

class AnswerWay
{
public:
    AnswerWay *parent; //指向父亲结点
    bool way;          //是左边进入还是右边进入
};

class Node
{

public:
    //比较优先级
    operator float() const
    {
        return priority;
    }
    float priority;    //结点的优先级
    int nowValue;      //当前结点的价值
    int nowWeight;     //当前重量
    int level;         //当前的层数
    AnswerWay *answer; //结点路径
};

class Package
{

public:
    void getMaxValue(); //获取最大值
private:
    void addPriorityQueue(float, int, int, int, bool); //加入优先队列
    float bound(int);                                  //求出价值上界
    int maxValue();                                    //背包的可容纳最大价值
    void sort();                                       //对物品单位价值进行排序
    void init();                                       //对package的各个属性进行初始化
    void destructor();                                 //清理new产生的空间
    void getError()                                    //测试错误,可删除
    {
        // for (int i = 0; i <= n; i++)
        //     cout << "value = " << value[i] << " weight = " << weight[i] << endl;
    }

private:
    int packageWeight;            //背包的重量
    int n;                        //物品的总数
    int *weight;                  //每个物品的重量
    int *value;                   //每个物品的价值
    int nowWeight;                //背包的当前重量
    int nowValue;                 //背包的当前价值
    int level;                    //当前层次
    priority_queue<Node> prQueue; //优先队列
    AnswerWay *answer;            //结点路径
    bool *bestWay;                //最优解
};

/*清除new产生的空间*/
void Package::destructor()
{
    delete[] weight;
    delete[] value;
    delete[] bestWay;
}

//对外函数，获取到背包的最优值
void Package::getMaxValue()
{
    init();
    sort();
    //获取最优值
    cout << "背包可容纳的最优值为: " << maxValue() << endl;
    //获取最优解
    // cout << "最优解为: " << endl;
    // for (int i = 1; i <= n; i++)
    //     if (bestWay[i])
    //         cout << "weight = " << weight[i] << " value = " << value[i] << endl;
    destructor();
}

/*计算背包的最优值*/
int Package::maxValue()
{
    /*不需要定义书中wt变量*/
    int bestValue = 0;         //当前最优值
    float priority = bound(1); //价值上界，也就是将要加入优先队列中的优先级
    Node node = Node();        //结点应放在外面定义

    while (level != (n + 1))
    {
        if ((nowWeight + weight[level]) <= packageWeight)
        {
            if ((nowValue + value[level]) > bestValue)
                bestValue = nowValue + value[level];
            //左儿子的价值上界是包括了该结点的
            addPriorityQueue(priority, nowValue + value[level], nowWeight + weight[level], level + 1, true);
        }
        //level+1是因为这一层的物品没有放进背包，对右儿子来说，剩余价值就是从level+1开始
        priority = bound(level + 1);
        if (priority >= bestValue)
            addPriorityQueue(priority, nowValue, nowWeight, level + 1, false);

        /*从优先队列中获取到优先级最高的元素*/
        node = prQueue.top();
        prQueue.pop();
        /*更新当前各个属性值*/
        nowWeight = node.nowWeight;
        nowValue = node.nowValue;
        priority = node.priority;
        answer = node.answer;
        level = node.level;
    }

    for (int i = n; i > 0; i--)
    {
        bestWay[i] = answer->way;
        answer = answer->parent;
    }

    return bestValue;
}

/*对物品单位价值进行排序*/
void Package::sort()
{
    float tempUnitValue; //临时单位价值
    int tempValue;       //临时价值
    int tempWeight;      //临时重量

    float *unitValue = new float[n + 1]; //物品的单位价值
    unitValue[0] = 0;
    for (int i = 1; i <= n; i++)
        unitValue[i] = float(value[i]) / float(weight[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (unitValue[i] < unitValue[j])
            {
                tempUnitValue = unitValue[i];
                unitValue[i] = unitValue[j];
                unitValue[j] = tempUnitValue;

                tempValue = value[i];
                value[i] = value[j];
                value[j] = tempValue;

                tempWeight = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWeight;
            }
        }
    }
    delete[] unitValue;
}

/*对package的各个属性进行初始化*/
void Package::init()
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "txt open fail！Please cheack" << endl;
    }

    ifs >> n >> packageWeight;

    weight = new int[n + 1];
    weight[0] = 0;

    value = new int[n + 1];
    value[0] = 0;

    for (int i = 1; i <= n; i++)
    {

        ifs >> weight[i] >> value[i];
    }

    ifs.close();
    nowValue = 0;
    nowWeight = 0;
    level = 1;
    answer = 0;
    bestWay = new bool[n + 1];
    for (int i = 0; i <= n; i++)
        bestWay[i] = false;
}

/*加入优先队列，参数priority,nowValue,nowWeight,level不同于Package类中的属性*/
void Package::addPriorityQueue(float priority, int nowValue, int nowWeight, int level, bool ch)
{
    AnswerWay *answerTemp = new AnswerWay;
    answerTemp->parent = answer;
    answerTemp->way = ch;

    Node node = Node();
    node.priority = priority;
    node.nowValue = nowValue;
    node.nowWeight = nowWeight;
    node.level = level;
    node.answer = answerTemp;
    prQueue.push(node);
}

/*求价值上界（从根节点的价值到当前结点的价值再加上剩余价值）函数，必须先对物品的单位价值从大到小排序*/
float Package::bound(int tempLevel)
{
    int leftPackageWeight = packageWeight - nowWeight;
    float priority = nowValue;
    while (tempLevel <= n && weight[tempLevel] <= leftPackageWeight)
    {
        leftPackageWeight -= weight[tempLevel];
        priority += value[tempLevel];
        tempLevel++;
    }
    if (tempLevel <= n)
        priority += (value[tempLevel] * 0.1) / (weight[tempLevel] * 0.1) * leftPackageWeight;
    return priority;
}

int main()
{
    Package package = Package();

    clock_t startTime, endTime;
    startTime = clock();
    package.getMaxValue();
    endTime = clock();

    cout << "The run time is:" << (double)(endTime - startTime) << "ms" << endl;

    return 0;
}