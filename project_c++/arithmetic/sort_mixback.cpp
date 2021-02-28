/*
    合并排序
    递归

*/

#include <malloc.h>
#include <stdlib.h>



void mergesort(int A[],int n)  //合并排序的递归主体
{
    void merge(int A[], int L[], int R[], int l, int r);  //声明merge函数
    if(n>1)    //多于一个元素才需要排序
    {
        int mid=n/2;
        int *left=(int*)malloc(sizeof(int)*mid);
        int *right=(int*)malloc(sizeof(int)*(n-mid));
        for(int i=0;i<mid;i++)
            left[i]=A[i];       //建立临时数组存储左半部分序列
        for(int j=mid;j<n;j++)
            right[j-mid]=A[j];  //建立临时数组存储右半部分序列
 
        mergesort(left,mid);    //调用自身对左半部分进行合并排序
        mergesort(right,n-mid); //调用自身对右半部分进行合并排序
        merge(A,left,right,mid,n-mid);   //两个有序序列的合并操作，封装为函数
        free(left);
        free(right);
    }
}
 
void merge(int A[],int L[],int R[],int l,int r)  //两个有序序列L、R合并为A，l,r分别为L,R的长度
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)  //两个子序列首元素做比较，小者取出置入父序列
    {
        if(L[i]<=R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<l)       //将左半部分剩余元素置入父序列
    {
        A[k++]=L[i++];
    }
    while(j<r)       //将右半部分剩余元素置入父序列
    {
        A[k++]=R[j++];
    }


