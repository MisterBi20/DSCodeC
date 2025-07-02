#include "stdio.h"
#define MaxSize 500

typedef struct {
    int SqBiTNode[MaxSize];
    int ElemNum;
}SqBiTree;

bool func(SqBiTree T){
    for (int i = 0; i < T.ElemNum/2; ++i) {
        if(T.SqBiTNode[i]==-1) continue;
        if(T.SqBiTNode[2*i+1]!=-1)
        {
            if(T.SqBiTNode[i]<T.SqBiTNode[2*i+1])
                return false;
        }
        if(T.SqBiTNode[2*i+2]!=-1)
        {
            if(T.SqBiTNode[i]>T.SqBiTNode[2*i+2])
                return false;
        }
    }
    return true;
}

int main(){
    int n,count=0;
    SqBiTree T;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&T.SqBiTNode[i]);
    }
    for (int i = 0; i < n; ++i) {
        if(T.SqBiTNode[i]!=-1)
            count++;
    }
    T.ElemNum=count;
    if(func(T))
        printf("是一颗二叉搜索树");
    else
        printf("不是一颗二叉搜索树");
    return 0;
}
//顺序储存树判断二叉排序树