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

int partition(SqList &L,int left,int right){
    int temp=L.data[left];
    while (left<right){
        while (L.data[right]>=temp && left<right) right--;//顺序不能反
        L.data[left]=L.data[right];
        while (L.data[left]<=temp && left<right) left++;
        L.data[right]=L.data[left];

    }
    L.data[left]=temp;
    return left;
};

int func(SqList &L,int k){
    int left=0,right=L.length-1,mid;
    while (1){
        mid=partition(L,left,right);
        if(mid==k-1) break;
        else if(mid>k-1) right=mid-1;
        else if(mid<k-1) left=mid+1;
    }
    return L.data[k-1];
}
int main(){
    SqList L;
    InitList(L);
    int k,n;
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
    scanf("%d",&k);
    func(L,k);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//快排找第k小的数，注意mid值的改变
#include "stdio.h"
#define MaxSize 500

int Partition(int a[],int left,int right){
    int mid=a[left];
    while(left<right){
        while (left<right&&a[right]>=mid) right--;
        a[left]=a[right];
        while (left<right&&a[left]<=mid) left++;
        a[right]=a[left];
    }
    a[left]=mid;
    return left;
}

int func(int a[],int n,int k){
    int left=1,right=n,mid=0;
    while (1){
        mid= Partition(a,left,right);
        if(mid==k) break;
        else if(mid>k) right=mid-1;
        else if(mid<k) left=mid+1;
    }
    return a[mid];
}

int main(){
    int a[MaxSize],n,k;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",a+i);
    }
    scanf("%d",&k);
    printf("第%d小的数为%d",k,func(a,n,k));
    return 0;
}
