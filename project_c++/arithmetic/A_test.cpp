#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    string str;
    getline(cin, str);
    int len = (str.size() / 2) + 1;
    cout << len << endl;

    int num[len];
    int j = 0;
    for (int i = 0; i < len; i++)
    {

        num[i] = str[j] - 48;
        cout << str[j] << endl;
        j = j + 2;
    }

    for (int i = 0; i < len; i++)
    {
        cout << num[i];
    }
}