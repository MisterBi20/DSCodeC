#include "stdio.h"
#define MaxSize 500

int Partition(int a[],int left,int right){
    int mid=a[left];
    while (left<right){
        while (left<right&&a[right]>=mid) right--;
        a[left]=a[right];
        while (left<right&&a[left]<=mid) left++;
        a[right]=a[left];
    }
    a[left]=mid;
    return left;
}

void QuickSort(int a[],int left,int right){
    while (left>=right) return;
    int mid= Partition(a,left,right);
    QuickSort(a,left,mid-1);
    QuickSort(a,mid+1,right);
}

int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    QuickSort(a,0,n-1);
    for (int i = 0; i < n; ++i)
        printf("%d ",a[i]);
    return 0;
}
//快排划分两个相近部分的差值最大,O(nlogn),O(logn)