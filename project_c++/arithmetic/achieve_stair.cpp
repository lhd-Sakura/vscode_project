/*
    ��̬�滮
    1.�����ж����ַ�������̨��
    ��һ¥�ݹ�M�����տ�ʼʱ���ڵ�һ����
    ��ÿ��ֻ�ܿ���һ���������Ҫ���ϵ�M�������ж������߷���

    ���⻮��Ϊ 쳲������������⣬�����õݹ鷨�Ͷ�̬�滮����

*/
#include <iostream>

using namespace std;

int achieve_stair( int arr)
{
    if (arr < 1)
    {
        return 0;
    }
    if (arr == 1)
    {
        return 1;
    }
    if (arr == 2)
    {
        return 2;
    }

    int a = 1;
    int b = 2;
    int temp = 0;

    for (int i = 3; i < arr + 1; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    int len;
    
    cin >> len;
    int arr[len];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int temp;
    for (int i = 0; i < len; i++)
    {
        temp = achieve_stair(arr[i]);
        cout << temp << endl;
    }

    return 0;
}
