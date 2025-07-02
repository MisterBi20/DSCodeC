/*题目描述
输入
 n个正整数，使用快速排序算法将它们按从小到大的顺序进行排序。
输入描述
 第一行一个整数0<n<1001），表示需要输入的正整数的个数；
 第二行为用空格隔开的n个正整数（每个正整数均不超过1000）。
输出描述
输出一行，表示输入的n个正整数。整数间用一个空格隔开，行末不允许有多余的空格。
*/
/*数组版
#include <stdio.h>
int partition(int a[],int left,int right){
    int temp=a[left];
    while (left<right){
        while (left<right&&a[right]>=temp) right--;
        a[left]=a[right];
        while (left<right&&a[left]<=temp) left++;
        a[right]=a[left];
    }
    a[left]=temp;
    return left;
}
void quicksort(int a[],int left,int right){
    if(left<right){
        int pos= partition(a,left,right);
        quicksort(a,left,pos-1);
        quicksort(a,pos+1,right);
    }
}
int main(){
    int i,n,a[1001];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    quicksort(a,0,n-1);
    for (i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d",a[i]);
    return 0;
}
 */顺序表版
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

bool QuickSort(SqList &L,int left,int right){
    if(left>=right) return false;
    int mid= partition(L,left,right);
    QuickSort(L,left,mid-1);
    QuickSort(L,mid+1,right);
}

int main(){
    SqList L;
    InitList(L);
    int n;
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
    QuickSort(L,0,L.length-1);
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.data[i]);
    }
    return 0;
}
//数组快排，注意快排函数的判断返回
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
void QuickSort(int a[],int left,int right){
    if(left>=right) return;
    int mid= Partition(a,left,right);
    QuickSort(a,left,mid-1);
    QuickSort(a,mid+1,right);
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
    QuickSort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return 0;
}