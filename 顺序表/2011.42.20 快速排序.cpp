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
    if(left>right) return;
    int mid= Partition(a,left,right);
    QuickSort(a,left,mid-1);
    QuickSort(a,mid+1,right);
}
int main(){
    int n,m,a[MaxSize],b[MaxSize],c[MaxSize];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",b+i);
    }
    for (int i = 0; i < n; ++i) {
        c[i]=a[i];
    }
    for (int i = 0; i < m; ++i) {
        c[n+i]=b[i];
    }
    QuickSort(c,0,n+m-1);
    return c[(n+m-1)/2];
}
//快速排序后取中间值,O((n+m)log(n+m)),O(n+m)