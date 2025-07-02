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

bool Merge(SqList &L1,int N,SqList &L2,int M,SqList &L){
    int i=0,j=0,k=0;
    while (i<N && j<M){
        if(L1.data[i]<=L2.data[j]) L.data[k++]=L1.data[i++];
        else L.data[k++]=L2.data[j++];
    }
    while (i<N) L.data[k++]=L1.data[i++];
    while (j<M) L.data[k++]=L2.data[j++];
    return true;
}

int main(){
    SqList L,L1,L2;
    InitList(L);
    InitList(L1);
    InitList(L2);
    int N,M;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d",&x);
        ListInsert(L1,i,x);
    }
    scanf("%d",&M);
    for (int i = 1; i <= M; ++i) {
        int x;
        scanf("%d",&x);
        ListInsert(L2,i,x);
    }
    for (int i = 1; i <= N+M; ++i) {
        ListInsert(L,i,0);
    }
    Merge(L1,N,L2,M,L);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    printf("\n");
    return 0;
}
//注意要申请三个数组
#include "stdio.h"
#define MaxSize 500

void merge(int a[],int n,int b[],int m,int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

int main(){
    int n,m,a[MaxSize],b[MaxSize],c[MaxSize];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    scanf("%d",&m);
    for (int i = 0; i < m; ++i)
        scanf("%d",b+i);
    merge(a,n,b,m,c);
    for (int i = 0; i < n+m; ++i) {
        printf("%d ",*(c+i));
    }
    printf("\n");
    return 0;
}