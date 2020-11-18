/*
    ��̬�滮
    4.����ȡ��
    һ��N*N�������в�ͬ��������������������ӣ�
    ���ܻ����Ӧ��ֵ�Ľ�����
    �������ߵ����£�ֻ�����������ߣ�
    ���ܹ���õ�����ֵ

    in:
    3
    5 6 8
    7 4 2
    1 4 3
    out:
    24

*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    int arr[len+1][len+1];
    for (int i = 0; i < len+1; i++)
    {
        arr[0][i] = 0;
        arr[i][0] = 0;
    }
    
    for (int i = 1; i < len+1; i++)
    {
        for (int j = 1; j <len+1; j++)
        {
            cin >> arr[i][j];
        }
    }

    // �������
    // for (int i = 0; i < len+1; i++)
    // {
    //     for (int j = 0; j <len+1; j++)
    //     {
    //         cout << arr[i][j]<<" ";
    //     }
    //     cout << endl;
    // }


    for (int i = 1; i < len+1; i++)
    {
        for (int j = 1; j < len+1; j++)
        {
            arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + arr[i][j];
        }
        
    }

    cout << arr[len][len];

    return 0;
}


