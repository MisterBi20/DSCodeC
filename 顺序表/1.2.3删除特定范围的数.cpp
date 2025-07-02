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

bool Del_s_t(SqList &L, int s, int t){
    int k=0;
    if(L.length==0||s>=t)
        return false;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i-k] = L.data[i];
    }
    L.length-=k;
    return true;
}

int main(){
    SqList L;
    InitList(L);
    int s,t,n;
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
    scanf("%d%d",&s,&t);
    Del_s_t(L,s,t);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//与1.2.2差不多

#include "stdio.h"
#define MaxSize 500

void Del_x(int a[],int &n,int x,int y){
    int count=0;
    for (int i = 0; i < n; ++i) {
        if(a[i]<x||a[i]>y){
            a[i-count]=a[i];
        } else count++;
    }
    n-=count;
}

int main(){
    int a[MaxSize],n,x,y;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    scanf("%d%d",&x,&y);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    Del_x(a,n,x,y);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}