#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

#define N 100000   //10万

int weights[N], values[N]; // 把物品重量和价值定义为双精度浮点数

int MaxWeight; //cw 为当前重量， cp 为当前价值，定义背包容量为 30
int Items;     // 货物数量为 3

string location = "F:/A_Project/vscode_project/project_c++/arithmetic/text/20000.txt";

int dp[N] = {0};

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
    clock_t startTime, endTime;
    startTime = clock(); //计时结束
    DP_Solution();
    endTime = clock(); //计时结束
    cout << dp[MaxWeight] << endl;
    cout << "The run time is:" << (double)(endTime - startTime)  << "ms" << endl;
}
