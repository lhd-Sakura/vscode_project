/*
    第四章
    2.
    给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。
    一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。
    请你返回乘积为正数的最长子数组长度

    动态规划，动态转移正数和负数数组的值

*/

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
int getMaxLen(vector<int> &nums)
{
    int size = nums.size();

    vector<int> p_dp(size);
    vector<int> n_dp(size);

    p_dp[0] = nums[0] > 0 ? 1 : 0;
    n_dp[0] = nums[0] < 0 ? 1 : 0;

    int result = p_dp[0];

    for (int i = 1; i < size; i++)
    {
        if (nums[i] > 0)
        {
            p_dp[i] = p_dp[i - 1] + 1;
            n_dp[i] = n_dp[i - 1] > 0 ? n_dp[i - 1] + 1 : 0;
        }
        else if (nums[i] < 0)
        {
            p_dp[i] = n_dp[i - 1] > 0 ? n_dp[i - 1] + 1 : 0;
            n_dp[i] = p_dp[i - 1] + 1;
        }
        else
        {
            p_dp[i] = 0;
            n_dp[i] = 0;
        }

        result = max(result, p_dp[i]);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    int maxLength = getMaxLen(nums);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<" ";

    // }

    cout << maxLength << endl;

    return 0;
}
