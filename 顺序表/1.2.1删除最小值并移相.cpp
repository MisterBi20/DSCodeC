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

bool Del_Min(SqList &L,int &value){
    if(L.length==0)
        return false;
    value=L.data[0];
    int pos=0;
    for (int i = 1; i <L.length; ++i)
        if(L.data[i]<value){
            value=L.data[i];
            pos=i;
        }
    L.data[pos]=L.data[L.length-1];
    L.length--;
    return true;
}

int main(){
    SqList L;
    InitList(L);
    int x,n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d",&x);
        ListInsert(L,i,x);
    }
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    printf("\n");
    Del_Min(L,x);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//最小数的查找，并且记录最小的坐标和最后的数值交换

#include "stdio.h"
#define MaxSize 500
int Dal_change(int a[],int n){
    if(n<=0) return -1;
    int x=a[0],key=0;
    for (int i = 1; i < n; ++i) {
        if(a[i]<x){
            x=a[i];
            key=i;
        }
    }
    a[key]=a[n-1];
    return x;
}
int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    for (int i = 0; i < n; ++i)
        printf("%d ",*(a+i));
    printf("\n");
    int x=Dal_change(a,n);
    for (int i = 0; i < n-1; ++i)
        printf("%d ",*(a+i));
    printf("\n");
    printf("最小数为%d",x);
    return 0;
}