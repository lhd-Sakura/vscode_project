
#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////
/*************************************************************************/
string rk(string num, int k)
{
    vector<char> stk;
    for (auto &dig : num)
    {
        while (stk.size() > 0 && stk.back() > dig && k)
        {
            stk.pop_back();
            k -= 1;
        }
        stk.push_back(dig);
    }

    for (; k > 0; --k)
    {
        stk.pop_back();
    }

    string result = "";
    bool zerom = true;
    for (auto &dig : stk)
    {
        if (zerom && dig == '0')
        {
            continue;
        }
        zerom = false;
        result += dig;
    }
    return result == "" ? "0" : result;
}
/////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/////////////////////////////////////////////////////////////////////////
/*************************************************************************/

int main(int argc, char const *argv[])
{
    string num;
    cin >> num;

    int k;
    cin >> k;

    string result;

    result = rk(num, k);
    cout << result << endl;

    return 0;
}
