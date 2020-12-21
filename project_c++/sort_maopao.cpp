/*
    冒泡排序


*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void bubble(vector<int> &nums){
    int len = nums.size();
    for(int i = 0;i<len;i++){//控制总的趟数
        for(int j =1;j<len-i;++j){//一次冒泡排序的结果
            if(nums[j-1]>nums[j]) swap(nums[j-1],nums[j]);
        }
    }
}
int main(){
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i =0;i<n;++i){
            cin>>nums[i];
        }
        bubble(nums);
        for(int i = 0;i<n;++i){
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}



