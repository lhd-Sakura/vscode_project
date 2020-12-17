/*
    01背包
    回溯法

*/
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stack>

//#include <conio.h>
using namespace std;

#define N 100000   //10万

string location = "F:/A_Project/vscode_project/project_c++/arithmetic/text/60000.txt";

int Items;              //物品数量
double MaxWeight;           //背包容量
double values[N];        //各个物品的价值　value
double weights[N];        //各个物品的重量　weight
double cw = 0.0;    //当前背包重量　current weight
double cp = 0.0;    //当前背包中物品总价值　current value
double bestp = 0.0; //当前最优价值best price
double perp[N];     //单位物品价值(排序后) per price
int order[N];       //物品编号
int put[N];         //设置是否装入，为1的时候表示选择该组数据装入，为0的表示不选择该组数据

//按单位价值排序
void knapsack()
{
    int i, j;
    int temporder = 0;
    double temp = 0.0;

    for (i = 1; i <= Items; i++)
        perp[i] = values[i] / weights[i]; 
    for (i = 1; i <= Items - 1; i++)
    {
        for (j = i + 1; j <= Items; j++)
            if (perp[i] < perp[j]) //冒泡排序perp[],order[],sortv[],sortw[]
            {
                temp = perp[i]; //冒泡对perp[]排序
                perp[i] = perp[j];
                perp[j] = temp;

                temporder = order[i]; //冒泡对order[]排序
                order[i] = order[j];
                order[j] = temporder;

                temp = values[i]; //冒泡对v[]排序
                values[i] = values[j];
                values[j] = temp;

                temp = weights[i]; //冒泡对w[]排序
                weights[i] = weights[j];
                weights[j] = temp;
            }
    }
}

//回溯函数
void backtrack(int i)
{ 
    double bound(int i);
    if (i > Items) //递归结束的判定条件
    {
        bestp = cp;
        return;
    }
   
    if (cw + weights[i] <= MaxWeight) //将物品i放入背包,搜索左子树
    {
        cw += weights[i]; //同步更新当前背包的重量
        cp += values[i]; //同步更新当前背包的总价值
        put[i] = 1;
        backtrack(i + 1); //深度搜索进入下一层
        cw -= weights[i];       //回溯复原
        cp -= values[i];       //回溯复原
    }
    if (bound(i + 1) > bestp) //如若符合条件则搜索右子树
        backtrack(i + 1);
}

//剪枝
double bound(int i)
{                          
    double leftw = MaxWeight - cw;
    double b = cp;         //记录当前背包的总价值cp,最后求上界
    //以物品单位重量价值递减次序装入物品
    while (i <= Items && weights[i] <= leftw)
    {
        leftw -= weights[i];
        b += values[i];
        i++;
    }
    //装满背包
    if (i <= Items)
        b += values[i] / weights[i] * leftw;
    return b; 
}

void read_text(string location)
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败：" << endl;
    }

    ifs >> Items >> MaxWeight;

    for (int i = 1; i <= Items; i++)
    {
        //cout << "第" << i + 1 << "件物品的重量和价值：";
        ifs >> weights[i] >> values[i];
    }

    ifs.close();
}

int main()
{
    read_text(location);

    clock_t startTime, endTime;
    startTime = clock(); //计时结束
    knapsack();
    backtrack(1);
    endTime = clock(); //计时结束
    cout << bestp << endl;
    cout << "The run time is:" << (double)(endTime - startTime) << "ms" << endl;

    return 0;
}