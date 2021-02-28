#include <algorithm>
#include <iostream>
#include <vector>
//#include<limits.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////
/*************************************************************************/
int profit(int k, vector<int> &prices)
{
    vector<int> s(k + 1, 0);
    vector<int> b(k + 1, -2147483648);

    for (auto &ele : prices)
    {
        for (int i = 1; i < k + 1; ++i)
        {
            b[i] = max(b[i], s[i - 1] - ele);
            s[i] = max(s[i], b[i] + ele);
        }
    }
    return s[k];
}

/////////////////////////////////////////////////////////////////////////
/*************************************************************************/
int main(int argc, char const *argv[])
{
    vector<int> prices;
    //= [ 2, 1, 4, 3, 6, 9, 8 ];

    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(9);
    prices.push_back(8);

    int k;
    cin >> k;

    cout << profit(k, prices) << endl;

    return 0;
}

/*

#include <iostream>

using namespace std;

void bubble_sort(int len, int *arr, int k)
{

    //外圈循环，总共进行size-1次
    for (int i = 0; i < len - 1; i++)
    {

        //内圈循环，每次进行size-i-1次
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << arr[len - k];
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
    int k;
    cin >> k;

    bubble_sort(len, arr, k);

    return 0;
}


*/