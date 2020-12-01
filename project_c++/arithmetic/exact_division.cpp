/*
    第四章
    5.检查数组对是否可以被 k 整除
    给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。
    现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。
    如果存在这样的分法，请返回 True ；否则，返回 False 。

*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


bool canArrange(vector<int>& arr, int k) {
        vector<int> groups(k, 0);
        for (auto val: arr) {
            groups[(k + (val % k)) % k]++;
        }
 
        if (groups[0] % 2 != 0)
            return false;
        for (int i = 1; i <= k / 2; ++i) {
            if (groups[i] !=  groups[k - i])
                return false;
        }
        return true;
}


int main(int argc, char const *argv[])
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    int k;
    k = nums.back();
    nums.pop_back();
    bool test;
    test = canArrange(nums, k);
    if(test==1)
        cout << "true" << endl;
    if(test==0)
        cout << "false" << endl;

    return 0;
}



