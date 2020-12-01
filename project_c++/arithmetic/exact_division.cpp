/*
    ������
    5.���������Ƿ���Ա� k ����
    ����һ���������� arr ��һ������ k ���������鳤����ż����ֵΪ n ��
    ������Ҫ������ǡ�÷ֳ� n / 2 �ԣ���ʹÿ�����ֵĺͶ��ܹ��� k ������
    ������������ķַ����뷵�� True �����򣬷��� False ��

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



