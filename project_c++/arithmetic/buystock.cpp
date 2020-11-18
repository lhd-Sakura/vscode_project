/*
    第四章
    1.
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void buystock(int len, int *stock)
{
    int ans = 0;
    for (int i = 0; (i+1) < len; i++)
    {
        if(stock[i]<stock[i+1])
            ans = ans + stock[i + 1] - stock[i];
    }
    cout << ans << endl;
    
}

int main(int argc, char const *argv[])
{
    //数据输入及数据转换，int 数组存放数据
    string str;
    getline(cin, str);
    int len = (str.size() / 2) + 1;
    //cout << len << endl;

    int stock[len];
    int j = 0;
    for (int i = 0; i < len; i++)
    {

        stock[i] = str[j] - 48;
        //cout << str[j] << endl;
        j = j + 2;
    }

    buystock(len, stock);

    return 0;
}