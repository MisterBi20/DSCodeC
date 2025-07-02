#include "stdlib.h"
#include "stdio.h"
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
        root = newNode(x);
        return;
    }
    if(x<root->data){
        insert(root->lchild,x);
    } else{
        insert(root->rchild,x);
    }
}

BiTree Create(int data[],int n){//构造查找二叉树
    BiTNode *root=NULL;
    for (int i = 0; i < n; ++i) {
        insert(root,data[i]);
    }
    return root;
}

void preorder(BiTNode *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(BiTNode *root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
}

void postorder(BiTNode *root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    inorder(root->rchild);
    printf("%d ",root->data);
}

int main(){
    int n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    printf("树的先根遍历是：");
    preorder(root);
    printf("\n");
    printf("树的中根遍历是：");
    inorder(root);
    printf("\n");
    printf("树的后根遍历是：");
    postorder(root);
    printf("\n");
    return 0;
}