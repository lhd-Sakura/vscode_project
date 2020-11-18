#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

    string s1;
    getline(cin, s1);
    istringstream str(s1);
    string out;

    vector<string> result;
    while (str >> out)
    {
        result.push_back(out);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
        cout << result[i].size() << endl;
    }
}