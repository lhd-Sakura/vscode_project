/*
    01背包
    动态规划
    数据集：在每个数据集的开头定义了物品的数量和背包容量

*/

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

#define N 100000 //10万的容量

int weights[N], values[N]; // 物品的重量和价值

int Items;     // 物品数量
int MaxWeight; //背包容量

//数据集存储位置
string location = "F:/A_Project/vscode_project/project_c++/arithmetic/text/100.txt";

long int dp[N] = {0};

void read_text(string location)
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    ifs >> Items >> MaxWeight;

    for (int i = 1; i <= Items; i++)
    {

        ifs >> weights[i] >> values[i];
    }

    ifs.close();
}

void DP_Solution()
{
    for (int i = 1; i <= Items; i++)
    {
        for (int j = MaxWeight; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
}

int main()
{
    read_text(location);

    //计算算法运行时间
    clock_t startTime, endTime;
    startTime = clock();
    DP_Solution();
    endTime = clock();

    cout << "最优解：" << dp[MaxWeight] << endl;
    cout << "The run time is:" << (double)(endTime - startTime) << "ms" << endl;
}
