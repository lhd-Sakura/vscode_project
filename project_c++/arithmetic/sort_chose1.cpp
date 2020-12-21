/*
    选择排序


*/

#include <iostream>
#define N 10
using namespace std;

int main()
{
    int arr[N] = {20, 5, 56, 89, 100, 23, 56, 45, 78, 23};
    int i, j, k, t, i1;
    cout << "排序前：";
    for (i1 = 0; i1 < N; i1++)
        cout << arr[i1] << " ";
    cout << endl
         << endl;
    for (i = 0; i < N - 1; i++) /*外循环控制趟数，找N-1趟*/
    {
        k = i;
        for (j = i + 1; j < N; j++) /*内循环，用k记住所找数中最小的下标*/
            if (arr[j] < arr[k])
                k = j;
        if (i != k) /*将最小数换至最前面*/
        {
            t = arr[k];
            arr[k] = arr[i];
            arr[i] = t;
        }
        cout << "第" << i + 1 << "趟排序：";
        for (i1 = 0; i1 < N; i1++)
            cout << arr[i1] << " ";
        cout << endl;
    }
    return 0;
}
