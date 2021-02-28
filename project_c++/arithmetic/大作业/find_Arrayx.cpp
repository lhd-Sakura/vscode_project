#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////
/*************************************************************************/
bool findM(int xin)
{

    int Array[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}

    };

    int m = 5,
        n = 5;            //矩阵为m行，n列
    int r = 0, c = n - 1; //从右上角开始寻找目标值
    while (r <= m - 1 && c >= 0)
    {
        if (xin > Array[r][c])
            ++r;
        else if (xin < Array[r][c])
            --c;
        else if (xin == Array[r][c])
            return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
/*************************************************************************/
int main(int argc, char const *argv[])
{
    vector<vector<int>> Array;
    int xin;
    cin >> xin;

    bool result;

    result = findM(xin);

    if (result == 1)
    {
        cout << "true" << endl;
    }

    if (result == 0)
    {
        cout << "false" << endl;
    }

    return 0;
}
