#include<stdio.h>
void merge(int a[],int l1,int r1,int l2,int r2){
    int i=l1,j=l2;
    int b[1001],k=0;
    while(i<=r1&&j<=r2){
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=r1)
        b[k++]=a[i++];
    while(j<=r2)
        b[k++]=a[j++];
    for(i=0;i<k;i++)
        a[l1+i]=b[i];
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,m+1,r);
    }
}
int main(){
    int i,n,a[1001];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    mergesort(a,0,n-1);
    for(i=0;i<n-1;i++)
        printf("%d ",*(a+i));
    printf("%d",*(a+i));
    return 0;
}
//注意排序递归顺序
#include "stdio.h"
#define MaxSize 500
void merge(int a[],int l1,int r1,int l2,int r2){
    int i=l1,j=l2;
    int b[MaxSize],k=0;
    while (i<=r1&&j<=r2){
        if(a[i]<a[j]) b[k++]=a[i++];//注意
        else b[k++]=a[j++];
    }
    while (i<=r1)
        b[k++]=a[i++];
    while (j<=r2)
        b[k++]=a[j++];
    for (int l = 0; l < k; ++l)
        a[l1+l]=b[l];
}
void mergesort(int a[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,mid+1,right);
    }
}
int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    mergesort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}
