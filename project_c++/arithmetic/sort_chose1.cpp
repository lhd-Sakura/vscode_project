/*
    ѡ������


*/

#include <iostream>
#define N 10
using namespace std;

int main()
{
    int arr[N] = {20, 5, 56, 89, 100, 23, 56, 45, 78, 23};
    int i, j, k, t, i1;
    cout << "����ǰ��";
    for (i1 = 0; i1 < N; i1++)
        cout << arr[i1] << " ";
    cout << endl
         << endl;
    for (i = 0; i < N - 1; i++) /*��ѭ��������������N-1��*/
    {
        k = i;
        for (j = i + 1; j < N; j++) /*��ѭ������k��ס����������С���±�*/
            if (arr[j] < arr[k])
                k = j;
        if (i != k) /*����С��������ǰ��*/
        {
            t = arr[k];
            arr[k] = arr[i];
            arr[i] = t;
        }
        cout << "��" << i + 1 << "������";
        for (i1 = 0; i1 < N; i1++)
            cout << arr[i1] << " ";
        cout << endl;
    }
    return 0;
}
