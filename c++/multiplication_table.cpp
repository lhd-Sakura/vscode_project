/*

    制表符\t

*/







#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c;
    for (b = 1; b < 10; b++)
    {
        for (a = 1; a <= b; a++)
        {
            cout << a << "*" << b << "=" << a * b << "\t";
        }
        cout << endl;
    }

    return 0;
}
