#include "stdio.h"
#define MaxSize 500

void merge(int a[],int n,int b[],int m,int c[]){
    int i=0,j=0,k=0;
    while (i<n&&j<m){
        if(a[i]<=b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while (i<n) c[k++]=a[i++];
    while (j<m) c[k++]=b[j++];
}

int main(){
    int n,m,a[MaxSize],b[MaxSize],c[MaxSize];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",b+i);
    }
    for (int i = 0; i < n; ++i) {
        c[i]=a[i];
    }
    for (int i = 0; i < m; ++i) {
        c[n+i]=b[i];
    }
    merge(a,n,b,m,c);
    return c[(n+m-1)/2];
}
//归并排序求中间值,O(m+n),O(m+n)1
#include "stdio.h"
#define MaxSize 500
void merge(int a[],int n,int b[],int m,int c[]){
    int x=0,y=0,z=0;
    while (x<n&&y<m){
        if (a[x]<b[y]) c[z++]=a[x++];
        else c[z++]=b[y++];
    }
    while (x<n) c[z++]=a[x++];
    while (y<m) c[z++]=b[y++];
}
int func(int a[],int b[],int n,int m){
    int c[MaxSize];
    merge(a,n,b,m,c);
    for (int i = 0; i < n+m; ++i) {
        printf("%d ",*(c+i));
    }
    printf("\n");
    return c[(n+m-1)/2];
}
int main(){
    int a[MaxSize],b[MaxSize],n,m;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    scanf("%d",&m);
    for (int i = 0; i < m; ++i)
        scanf("%d",b+i);
    printf("中间数为%d",func(a,b,n,m));
    return 0;
}