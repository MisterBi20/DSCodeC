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

bool SearchExchangeInsert(SqList &L,int x){
    int low=0,mid,high=L.length;
    while (low<=high){
        mid=(low+high)/2;
        if(L.data[mid]==x) break;
        else if(L.data[mid]<x) low=mid+1;
        else high=mid-1;
    }
    if(L.data[mid]==x && mid!=L.length-1){
        int temp=L.data[mid];
        L.data[mid]=L.data[mid+1];
        L.data[mid+1]=temp;
    }
    if(low>high){
        for (int i = L.length-1; i >high ; --i)//注意折半查找失败后low,high的位置
            L.data[i+1]=L.data[i];
        L.data[high+1]=x;
        L.length++;
    }
}

int main(){
    SqList L;
    InitList(L);
    int x,n;
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
    scanf("%d",&x);
    SearchExchangeInsert(L,x);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//注意折半查找后low与high的位置
#include "stdio.h"
#define MaxSize 500

void func(int a[],int &n,int x){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==x){
            a[mid]=a[mid+1];
            a[mid+1]=x;
            return;
        }
        else if(a[mid]>x&&low<=high) high=mid-1;
        else if(a[mid]<x&&low<=high) low=mid+1;
    }
    n+=1;
    for (int i = n; i >low; --i) {
        a[i]=a[i-1];
    }
    a[low]=x;
}

int main(){
    int a[MaxSize],n,x;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    scanf("%d",&x);
    func(a,n,x);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}