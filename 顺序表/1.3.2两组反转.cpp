#include "stdio.h"
#define MaxSize 50

typedef struct {
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    L.length=0;
}

bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for (int j = L.length; j >=i ; j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;//在位置i处放入e
    L.length++;
    return true;
}

bool Reverse(SqList &L,int left,int right){
    if(left>right) return false;
    int temp,mid=(left+right)/2;
    for (int i = 0; i <= mid-left; ++i) {//注意i的取值，length/2与(left+right)/2不同，(left+right)/2对应数组下标，length/2对应顺序表长度
        temp=L.data[left+i];
        L.data[left+i]=L.data[right-i];
        L.data[right-i]=temp;
    }
}

bool Exchange(SqList &L,int m,int n){
    Reverse(L,0,m+n-1);
    Reverse(L,0,n-1);
    Reverse(L,n,m+n-1);
}

int main(){
    SqList L;
    InitList(L);
    int n,m;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        int x;//局部变量
        scanf("%d",&x);
        ListInsert(L,i,x);
    }
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    printf("\n");
    scanf("%d%d",&m,&n);
    Exchange(L,m,n);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//给定范围的反转要注意mid值的位置和循环的关系
#include "stdio.h"
#define MaxSize 500

void Reverse(int a[],int left,int right){
    int mid=(left+right+1)/2;
    for (int i = 0; i < mid-left; ++i) {
        int temp=a[left+i];//注意
        a[left+i]=a[right-i];//注意
        a[right-i]=temp;
    }
}

void func(int a[],int m,int n){
    Reverse(a,0,m-1);
    Reverse(a,m,n+m-1);
    Reverse(a,0,n+m-1);
}

int main(){
    int a[MaxSize],n,x,y;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    scanf("%d%d",&x,&y);
    func(a,x,y);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}