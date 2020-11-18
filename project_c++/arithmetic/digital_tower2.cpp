/*
    ��̬�滮
    2.������

    ��������������Ѱ��һ���Ӷ������ױߵ�·����ʹ��·����������������֮�����
    ·���ϵ�ÿһ����ֻ�������»��������ߡ�ֻ��Ҫ���������ͼ��ɣ����ظ���·����
    �����ε���������1С�ڵ���100������Ϊ0~99

    ���¶��ϣ�һά�������
    ���ֵΪ temp[0]

    7 
    3 8
    8 1 0

    �����������ά���飩ʵ��

*/

#include <iostream>

using namespace std;

void digital_tower(int len, int *arr)
{
    int temp[len];

    for (int i = 0; i < len; i++)
    {
        temp[i] = arr[(len - 1) * len + i];
    }
    //�� n-1 ��ʼ�ۼ�
    for (int i = len - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            temp[j] = max(temp[j], temp[j + 1]) + arr[i * len + j];
        }
    }

    cout << temp[0];
}

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    int arr[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    //��ʾ���������
    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout<< arr[i][j]<<" ";
    //     }

    //     cout << endl;
    // }

    digital_tower(len, *arr);

    return 0;
}
