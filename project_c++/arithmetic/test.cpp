#include <iostream>

using namespace std;

void test01(int a[][4])
{
    cout << a[0][3] << endl;
}


void test02(int** a )
{



}

int main(int argc, char const *argv[])
{
    int a[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

    test01(a);

   // test02(a);

    return 0;
}
