#include "stdlib.h"
#include "stdio.h"

int height=0;
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

void preorder(BiTree T,int n){//全局变量先根遍历求树高
    if(T==NULL) return;
    if(n>height) height=n;
    preorder(T->lchild,n+1);
    preorder(T->rchild,n+1);
}

int postorder(BiTree T){//直接后根遍历求树高
    if(T==NULL) return 0;
    int left= postorder(T->lchild);
    int right= postorder(T->rchild);
    if(left>right) return left+1;
    else return right+1;
}

int main(){
    int n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    preorder(root,1);
    printf("树高是%d\n", height);
    printf("树高是%d\n", postorder(root));
    return 0;
}