/*
    第四章
    4.玩筹码
    数轴上放置了一些筹码，每个筹码的位置存在数组 chips 当中。
    你可以对 任何筹码 执行下面两种操作之一（不限操作次数，0 次也可以）：
    将第 i 个筹码向左或者右移动 2 个单位，代价为 0。
    将第 i 个筹码向左或者右移动 1 个单位，代价为 1。
    最开始的时候，同一位置上也可能放着两个或者更多的筹码。
    返回将所有筹码移动到同一位置（任意位置）上所需要的最小代价

    实际上就是求解数组中奇数和偶数的个数
    返回最小的那个

*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int moveChip(vector<int> &nums)
{
    int size;
    size = nums.size();

    int sinNum = 0;
    int douNum = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] % 2 == 0)
            douNum++;
        if (nums[i] % 2 == 1)
            sinNum++;
    }

    if (douNum > sinNum)
        return sinNum;
    if (douNum < sinNum)
        return douNum;
    else
        return douNum;
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    int result;
    result = moveChip(nums);
    cout << result << endl;

    return 0;
}
