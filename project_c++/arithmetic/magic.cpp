/*
    分治法
    4.
     在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。
     给定一个有序整数数组，编写一种方法找出魔术索引，
     若有的话，在数组A中找出一个魔术索引，
     如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。

*/
#include <iostream>

using namespace std;


void magic(int len,int *arr)
{
    int num;
    for (int i = 0; i < len; i++)
    {
        if(arr[i] == i)
        {
            cout << arr[i];
            num++;
            break;
        }
            

    }
    
    if(num == 0)
        cout << -1 << endl;

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

    magic(len, arr);

    return 0;
}
