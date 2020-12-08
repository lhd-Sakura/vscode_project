/*
    ������
    3.�ָ�����Ϊ����������
    ����һ��������������������� num�����ܰ����ظ����֣���
    ���㽫���Ƿָ��һ�����������У�����ÿ�������ж���������������ҳ�������Ϊ 3 
    ���������������ָ�򷵻� true �����򣬷��� false ��

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
    { //��һ���������¼ÿ�������ֵĴ���
        left[num]++;
    }
    for (int num : nums)
    {                       //�ڶ��������������һ��֮��ͽ����ִ�����һ��ֱ��left�����е�ֵ��Ϊ0(��ʱ����������)
        if (left[num] == 0) //�����Ѿ���������������һ����������
            continue;
        else if (need[num] > 0)
        { //��û�У��ȼ���ܲ��ܺ�ǰ�����������
            need[num]--;
            need[num + 1]++;
        }
        else if ((left[num + 1] > 0) && (left[num + 2] > 0))
        { //Ȼ���ټ���ܲ��ܺͺ�������һ����������
            left[num + 1]--;
            left[num + 2]--;
            need[num + 3]++;
        }
        else //�����ܣ��򷵻�false
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

