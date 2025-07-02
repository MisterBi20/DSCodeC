#include "stdio.h"
#define MaxSize 1000
void Reverse(int a[],int left,int right){
    int temp;
    for (int i = 0; i < (right-left+1)/2; ++i) {
        temp=a[left+i];
        a[left+i]=a[right-i];
        a[right-i]=temp;
    }
}

void exchange(int a[],int n,int p){
    Reverse(a,0,n-1);
    Reverse(a,0,n-p-1);
    Reverse(a,n-p,n-1);
}

int main(){
    int n,mid,a[MaxSize];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    scanf("%d",&mid);
    exchange(a,n,mid);
    for (int i = 0; i < n; ++i) {
        printf("%d ",a[i]);
    }
}
//循环左移p位数,O(n),O(1)
#include "stdio.h"
#define MaxSize 500

void Reverse(int a[],int left,int right){
    int mid=(right-left+1)/2;//注意
    for (int i = 0; i < mid; ++i) {
        int temp=a[left+i];
        a[left+i]=a[right-i];//注意
        a[right-i]=temp;
    }
}
void exchange(int a[],int t,int n){
    Reverse(a,0,t-1);
    Reverse(a,t,n-1);
    Reverse(a,0,n-1);
}
int main(){
    int a[MaxSize],n,t;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    scanf("%d",&t);
    exchange(a,t,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    return 0;
}