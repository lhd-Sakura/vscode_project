/*
    ������
    4.�����
    �����Ϸ�����һЩ���룬ÿ�������λ�ô������� chips ���С�
    ����Զ� �κγ��� ִ���������ֲ���֮һ�����޲���������0 ��Ҳ���ԣ���
    ���� i ����������������ƶ� 2 ����λ������Ϊ 0��
    ���� i ����������������ƶ� 1 ����λ������Ϊ 1��
    �ʼ��ʱ��ͬһλ����Ҳ���ܷ����������߸���ĳ��롣
    ���ؽ����г����ƶ���ͬһλ�ã�����λ�ã�������Ҫ����С����

    ʵ���Ͼ������������������ż���ĸ���
    ������С���Ǹ�

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
