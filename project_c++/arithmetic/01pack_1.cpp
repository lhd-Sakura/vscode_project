/*
    01背包
    动态规划

*/

#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define N 10000 //默认有十万个物品。第一个不使用
int weights[N];     //每个物品的重量
int values[N];     //每个物品的价值

string weight_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/weights100.txt";
string values_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/values100.txt";

int Items = 10000;
int MaxWeight = 500;

int DP_Solution(int Items, int MaxWeight, int* weights, int* values)
{
    int dp[Items + 1][MaxWeight + 1];
    int i, j;
    for (i = 0; i < Items + 1; i++)
    {
        dp[i][0] = 0;
        for (j = 0; j < MaxWeight + 1; j++)
        {
            dp[0][j] = 0;
            if (j < weights[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
        }
    }
    return dp[Items][MaxWeight];
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
        
        nums[i] = num;
        i++;

    }

    ifs.close();
}

int main()
{
    //vector<int> weights;
    //vector<int> values;

    read_text(weights, weight_txt);
    read_text(values, values_txt);

    int result;

    clock_t startTime, endTime;
    startTime = clock(); //计时结束
    result = DP_Solution(Items, MaxWeight, weights, values);
    cout << result << endl;
    endTime = clock(); //计时结束
    cout << "运行时间是： " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    
    return 0;
}