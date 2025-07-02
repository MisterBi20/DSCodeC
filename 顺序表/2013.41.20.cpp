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
    int mid;
    while (left>=right) return;
    mid=Partition(a,left,right);
    QuickSort(a,left,mid-1);
    QuickSort(a,mid+1,right);
}

int func(int a[],int n){
    QuickSort(a,0,n-1);
    int x=a[n/2-1],count=0;
    for (int i = 0; i < n; ++i) {
        if(a[i]==x) count++;
    }
    if(count>n/2) return x;
    else return -1;
}

int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    printf("%d",func(a,n));
    return 0;
}
//快速排序寻找主元素,O(nlogn),O(logn)
#include "stdexcept"
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
    if(left>=right) return;
    int mid= Partition(a,left,right);
    QuickSort(a,left,mid-1);
    QuickSort(a,mid+1,right);
}

int func(int a[],int n){
    QuickSort(a,0,n-1);
    int key=a[(n-1)/2],count=0;
    for (int i = 0; i < n; ++i) {
        if (a[i]==key) count++;
    }
    if (count>n/2) return key;
    else return -1;
}

int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    if (func(a,n)!=-1)
        printf("主元素为%d", func(a,n));
    else printf("没有主元素");
    return 0;
}