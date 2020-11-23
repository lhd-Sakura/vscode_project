/*
    ������
    2.
    ����һ���������� nums ����������˻�Ϊ�������������ĳ��ȡ�
    һ�����������������ԭ������������߸��������������ɵ����顣
    ���㷵�س˻�Ϊ������������鳤��

    ��̬�滮����̬ת�������͸��������ֵ

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
