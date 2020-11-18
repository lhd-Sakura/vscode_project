/*
    ��̬�滮 
    5.����Ǯ
    ������ͬ����Ӳ�ң�ÿ��Ӳ�ҵĸ������ޣ� ��һ���ܽ�� ��
    ��дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ�����
    ���û���κ�һ��Ӳ�����������ܽ����� -1��
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
        //�����¥�ݣ������ÿһ��¥�����õ����ٲ������磬��һ�ף����ף����ף��Ľף����...ʮһ�ף�
        for (int j = 0; j < coinsSize; j++)
        {
            if (i >= coins[j])
            {
                //ѡ��opt(11) = min(opt(11 - 1), opt(11 - 2), opt(11 - 5)) + 1
                //dp[ i - coins[j] ] + 1Ϊ��ǰ�߷�����1������2������5������֮ǰ�洢���߷�����1������2������5������Ƚ�
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }

    //���dp[amount] > amount�Ļ���˵��dp[amount]=amount+1,����ô�߶������ߵ����һ��������-1
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
