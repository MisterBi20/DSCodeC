#include "stdlib.h"
#include "stdio.h"

typedef struct BiTNode{//定义树的节点
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LinkNode{//定义队列节点
    BiTNode* data;//注意
    struct LinkNode *next;
}LinkNode;

typedef struct {//定义队列
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){//带头节点的队列初始化
    Q.front=Q.rear=(LinkNode *) malloc(sizeof (LinkNode));
    Q.front->next=NULL;
}

bool DeQueue(LinkQueue &Q,BiTNode *&x){//出队
    if(Q.front==Q.rear)
        return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return true;
}

void  EnQueue(LinkQueue &Q,BiTNode *&x){//入队
    LinkNode *S=(LinkNode *) malloc(sizeof (LinkNode));
    S->data=x;
    S->next=NULL;
    Q.rear->next=S;
    Q.rear=S;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

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

void LevelOrder(BiTree T){//层序遍历
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while (!IsEmpty(Q)){
        DeQueue(Q,p);
        printf("%d ",p->data);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}

int main(){
    int n,a[101];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
    }
    BiTNode *root;
    root=Create(a,n);
    LevelOrder(root);
    return 0;
}