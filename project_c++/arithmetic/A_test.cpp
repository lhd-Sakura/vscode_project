#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i]<<" ";

    }

    return 0;
}
