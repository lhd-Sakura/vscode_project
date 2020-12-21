/*
    快速排序

    算法复杂度
    最好    O(nlogn)
    最坏    O(n*n)


*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int parti(vector<int> &nums, int low, in high)
{
    int temp = nums[low];
    while (low < high)
    {
        while (low < high && nums[high] >= temp)
            high--;
        if (low < high)
            nums[low++] = nums[high];
        while (low < high && nums[low] <= temp)
            low++;
        if (low < high)
            nums[high--] = nums[low];
    }
    nums[low] = temp;
    return low;
}

void quicksort(vector<int> &nums, int low, in high)
{
    if (low < high)
    {
        int mid = parti(nums, low, high);
        quicksort(nums, low, mid - 1);
        quicksort(nums, mid + 1, high);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        quicksort(nums, 0, n - 1);
        for (int i = 0; i < n; ++i)
        {
            cout << nums[i] << " ";
        }
    }
    return 0;
}
