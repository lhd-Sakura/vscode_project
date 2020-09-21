#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int end = sizeof(arr1) / sizeof(arr1[0]);

    //输出数组1
    for (int i = 0; i < end; i++)
    {
        cout << arr1[i];
    }
    cout << endl;

    int arr2[end];

    for (int i = 0; i < end; i++)
    {
        arr2[i] = arr1[end - 1 - i];
    }

    //输出置换后的数组2
    for (int i = 0; i < end; i++)
    {
        cout << arr2[i];
    }
    cout << endl;

    return 0;
}
