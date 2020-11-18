/*
    动态规划 
    5.找零钱
    给定不同面额的硬币（每种硬币的个数不限） 和一个总金额 。
    编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
    如果没有任何一种硬币组合能组成总金额，返回 -1。
*/
#include <iostream>

using namespace std;

int coinChange(int *coins, int coinsSize, int amount)
{
    int *dp = (int *)malloc(sizeof(int) * (amount + 1));

    for (int i = 0; i < amount + 1; i++)
    {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        //类比走楼梯，计算出每一阶楼梯所用的最少步数（如，走一阶，两阶，三阶，四阶，五阶...十一阶）
        for (int j = 0; j < coinsSize; j++)
        {
            if (i >= coins[j])
            {
                //选出opt(11) = min(opt(11 - 1), opt(11 - 2), opt(11 - 5)) + 1
                //dp[ i - coins[j] ] + 1为当前走法（走1步或者2步或者5步）与之前存储的走法（走1步或者2步或者5步）相比较
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }

    //如果dp[amount] > amount的话，说明dp[amount]=amount+1,即怎么走都不能走到最后一步，返回-1
    int ret = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return ret;
}

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    int coins[len];
    for (int i = 0; i < len; i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    int ret = coinChange(coins, len, amount);
    cout << ret;

    return 0;
}
