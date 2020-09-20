#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 100;
    do
    {
        int num1 = num % 10;
        int num2 = (num / 10) % 10;
        int num3 = num / 100;

        if (num == (num1 * num1 * num1 + num2 * num2 * num2 + num3 * num3 * num3))
        {
            cout << "水仙花数：" << num << endl;
            num++;
        }
        else
        {
            num++;
        }

    } while (num < 1000);

    return 0;
}
