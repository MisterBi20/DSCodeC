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

int func(int a[],int n){
    QuickSort(a,0,n-1);
    int m=-1;
    for (int i = 0; i < n; ++i) {
        if(a[i]>0){
            m=i;
            break;
        }
    }
    if(m==-1) return 1;
    if(a[m]!=1) return 1;
    for (m=m+1; m < n; ++m) {
        if(a[m]-a[m-1]>1) return a[m-1]+1;
    }
    return a[n-1]+1;
}

int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    printf("%d", func(a,n));
    return 0;
}
//快排求最小正整数,O(nlogn),O(logn)
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
    if(left>=right) return;
    int mid= Partition(a,left,right);
    QuickSort(a,left,mid-1);
    QuickSort(a,mid+1,right);
}
int func(int a[],int n){
    int m=-1;
    QuickSort(a,0,n-1);
    for (int i = 0; i < n; ++i)
        if(a[i]>0){
            m=i;
            break;
        }
    if(a[m]>1) return 1;
    else if(m==-1) return 1;
    for (int i = m; i < n-1; ++i) {
        if(a[i+1]-a[i]>1) return a[i]+1;
    }
    return a[n-1]+1;
}
int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    return func(a,n);
}