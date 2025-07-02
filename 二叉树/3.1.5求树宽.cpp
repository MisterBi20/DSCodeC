#include "stdlib.h"
#include "stdio.h"

int width[101];
typedef struct BiTNode{//定义树的节点
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTNode *newNode(int v){//生成新的树节点
    BiTNode *Node=(BiTNode *) malloc(sizeof (BiTNode));
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}

void insert(BiTree &root,int x){//递归插入构造二叉查找树
    if(root==NULL){
        root= newNode(x);
        return;
    }
    if(x<root->data){
        insert(root->lchild,x);
    } else{
        insert(root->rchild,x);
    }
}

BiTree Create(int data[],int n){
    BiTNode *root=NULL;
    for (int i = 0; i < n; ++i) {
        insert(root,data[i]);
    }
    return root;
}

void preorder(BiTree T,int level){//先根遍历求每层结点数
    if(T==NULL) return;
    width[level]++;
    preorder(T->lchild,level+1);
    preorder(T->rchild,level+1);
}

void treeWidth(BiTree T){
    for (int i = 0; i < 101; ++i)
        width[i]=0;
    preorder(T,1);
    int maxwidth=0;
    for (int i = 0; i < 101; ++i) {
        if(width[i]>maxwidth)
            maxwidth=width[i];
    }
    printf("二叉树的宽度是%d",maxwidth);
}

int main(){
    int n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    treeWidth(root);
    return 0;
}