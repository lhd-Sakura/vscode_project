/*
    第四章
    3.分割数组为连续子序列
    给你一个按升序排序的整数数组 num（可能包含重复数字），
    请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 
    如果可以完成上述分割，则返回 true ；否则，返回 false 。

*/
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

bool isPossible(vector<int> &nums)
{
    map<int, int> left, need;
    for (int num : nums)
    { //第一遍遍历，记录每个数出现的次数
        left[num]++;
    }
    for (int num : nums)
    {                       //第二遍遍历，处理了一个之后就将出现次数减一，直到left中所有的值都为0(此时数组遍历完成)
        if (left[num] == 0) //该数已经和其他数构成了一个连续序列
            continue;
        else if (need[num] > 0)
        { //若没有，先检测能不能和前面的连接起来
            need[num]--;
            need[num + 1]++;
        }
        else if ((left[num + 1] > 0) && (left[num + 2] > 0))
        { //然后再检测能不能和后面的组成一个连续序列
            left[num + 1]--;
            left[num + 2]--;
            need[num + 3]++;
        }
        else //都不能，则返回false
            return false;
        left[num]--;
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

    int result;
    result = isPossible(nums);
    if(result == 0)
        cout << "false" << endl;

    if(result == 1)
        cout << "true" << endl;

    int size;
    size = nums.size();



        return 0;
}

