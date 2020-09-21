#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[5] = {300, 350, 200, 400, 250};
    int max = arr[0];

    for (int i = 0; i <= 5; i++)
    {
        max > arr[i] ? max : max = arr[i];
    }
    cout << max << endl;

    return 0;
}
