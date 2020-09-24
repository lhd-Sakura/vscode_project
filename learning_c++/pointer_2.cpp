/*
    const
    常量指针：常量是个指针，指针指向的值不可以修改
    指针常量：指针是个常量，指向不可以改变
    



*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 666;

    //常量指针，指针的指向可以修改，但是指针指向的值不可以修改
    const int *p1 = &a;

    //指针常量，指针的指向不可以改，指针指向的值可以改
    int *const p2 = &a;

    //指针的指向和指针指向的值都不可以改
    const int *const p3 = &a;

    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *p4 = arr1;
    cout << "利用指针访问第一个元素：" << *p4 << endl;

    //指针向后，int类型的指针，每次++向后移动四位
    p4++;
    cout << "移位试验" << *p4 << endl;













    return 0;
}
