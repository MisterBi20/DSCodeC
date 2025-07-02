#include "stdlib.h"
#include "stdio.h"

int WPL=0;
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

void preorder(BiTree T,int level){//先根遍历求WPL
    if(T==NULL) return;
    if(T->lchild==NULL&&T->rchild==NULL)
        WPL+=level*T->data;
    preorder(T->lchild,level+1);
    preorder(T->rchild,level+1);
}

int main(){
    int n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    preorder(root,0);
    printf("树的WPL是%d",WPL);
    return 0;
}