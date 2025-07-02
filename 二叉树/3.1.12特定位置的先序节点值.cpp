#include "stdlib.h"
#include "stdio.h"

int i=1;
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

int PreNode(BiTree T,int k){//先序排列的第k位(与顺序无关)
    int x;
    if(T==NULL)
        return -1;
    if(i==k)
        return T->data;
    i++;
    x=PreNode(T->lchild,k);
    if(x!=-1)
        return x;
    x=PreNode(T->rchild,k);
    if(x!=-1)
        return x;
}

int main(){
    int k,n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    scanf("%d",&k);
    printf("先序遍历二叉树第%d个节点的数值为%d",k,PreNode(root,k));
    return 0;
}