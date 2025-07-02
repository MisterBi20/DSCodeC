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

int main(){
    int a[MaxSize],n,mid=-1;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    while (mid!=n/2){
        if(mid>n/2)
            mid= Partition(a,0,mid-1);
        else mid= Partition(a,mid+1,n-1);
    }
    for (int i = 0; i < n; ++i)
        printf("%d ",a[i]);
    return 0;
}
//划分划分两个相近部分的差值最大,O(nlogn),O(logn)
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

void func(int a[],int n){
    int mid=0;
    while (1){
        if(mid>n/2) mid= Partition(a,0,mid-1);
        else if(mid<n/2) mid= Partition(a,mid+1,n-1);
        else return;
    }
}

int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    func(a,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}