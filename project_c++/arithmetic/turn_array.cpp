/*
    算法设计与分析（分治法）
    1.
    给定一个数组 array ，如果 i < j 且 array[i] > 2*array[j] 
    我们就将 (i, j) 称作一个重要翻转对。
    你需要返回给定数组中的重要翻转对的数量

    输入为2行，第一行为数组大小，第二行为数组元素

    二维数组分治法

*/
#include <iostream>

using namespace std;

int maxSize = 1024;

void turn_array(int len, int *arr)
{
    int num = 0;
    int arr2[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i] > 2 * arr[j])
            {
                if (i < j)
                {
                    arr2[i][j] = 1;
                    //cout << arr[i] << "," << arr[j] << endl;
                    num++;
                }
                else
                {
                    arr2[i][j] = 0;
                }
            }
            else
            {
                arr2[i][j] = 0;
            }
        }
    }
    //cout << "重要翻转对的数量:" << num << endl;
    cout << num;
}

int main(int argc, char const *argv[])
{
    int len;
    //cout << "输入数组大小（最大容量1024）" << endl;
    cin >> len;
    int arr[len];

    //cout << "输入数组元素以空格为分界线" << endl;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    turn_array(len, arr);

    return 0;
}
