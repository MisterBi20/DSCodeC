#include "stdio.h"
#define MaxSize 500

int abs_(int a){
    if(a<0) return -a;
    else return a;
}

int func(int a[],int b[],int c[],int n,int m,int s){
    int min=0x7fffffff;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < s; ++k) {
                if(abs_(a[i]-b[j])+ abs_(a[i]-c[k])+ abs_(b[j]-c[k])<min)
                    min=abs_(a[i]-b[j])+ abs_(a[i]-c[k])+ abs_(b[j]-c[k]);
            }
        }
    }
    printf("最小距离为%d\n",min);
    printf("所有可能的三元组为：\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < s; ++k) {
                if(abs_(a[i]-b[j])+ abs_(a[i]-c[k])+ abs_(b[j]-c[k])==min)
                    printf("(%d,%d,%d)\n",a[i],b[j],c[k]);
            }
        }
    }
}
int main(){
    int a[MaxSize],b[MaxSize],c[MaxSize],n,m,s;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",b+i);
    }
    scanf("%d",&s);
    for (int i = 0; i < s; ++i) {
        scanf("%d",c+i);
    }
    func(a,b,c,n,m,s);
    return 0;
}
//三重循环求距离最小元,O(n*m*s),O(1)