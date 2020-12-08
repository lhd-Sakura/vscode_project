/*
    01背包
    动态规划

*/

#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int DP_Solution(int Items, int MaxWeight, vector<int> weights, vector<int> values)
{
    int dp[Items + 1][MaxWeight + 1];
    int i, j;
    for (i = 0; i < Items+1; i++)
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

void read_text(vector<int> &nums, string location)
{

    ifstream ifs;

    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败：" << endl;
    }

    int num;
    while (ifs >> num)
    {
        nums.push_back(num);
    }

    ifs.close();

}

int main()
{
    vector<int> weights;
    vector<int> values;

    string weight_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/weights1.txt";
    string values_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/values1.txt";

    read_text(weights, weight_txt);
    read_text(values, values_txt);

    int Items = 5;
    int MaxWeight = 8;

    int result;

    clock_t startTime, endTime;
    startTime = clock(); //计时结束
    result = DP_Solution(Items, MaxWeight, weights, values);
    endTime = clock(); //计时结束
    cout << "运行时间是： " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    cout << result << endl;
    return 0;
}