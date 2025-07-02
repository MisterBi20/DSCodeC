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

bool Del_Same(SqList &L){
    if(L.length==0)
        return false;
    for (int i = 0; i < L.length-1; ++i) {
        for (int j = i+1; j <L.length;) {
            if(L.data[i]==L.data[j]) {
                for (int k = j; k < L.length-1; k++) {
                    L.data[k]=L.data[k+1];
                }
                L.length--;
            } else{
                j++;
            }
        }
    }
}

int main(){
    SqList L;
    InitList(L);
    int n;
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
    Del_Same(L);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//循环累加新写法
#include "stdio.h"
#define MaxSize 500

void Del_Same(int a[],int &n){
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n;) {
            if(a[j]==a[i]){
                for (int k = j; k < n-1; ++k)
                    a[j]=a[j+1];
                n-=1;//注意
            }
            else ++j;//注意
        }
    }
}
int main(){
    int a[MaxSize],n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    Del_Same(a,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}