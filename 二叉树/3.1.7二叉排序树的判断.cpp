#include "stdlib.h"
#include "stdio.h"

int temp=0;
bool isBST= true;

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

void InOrder(BiTree T){//中根遍历是否升序
    if(T==NULL) return;

    InOrder(T->lchild);
    if(T->data>=temp) temp=T->data;
    else isBST= false;
    InOrder(T->rchild);
}

int main(){
    int n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    InOrder(root);
    if(isBST)
        printf("二叉树L是二叉排序树");
    else printf("二叉树L不是二叉排序树");
    return 0;
}