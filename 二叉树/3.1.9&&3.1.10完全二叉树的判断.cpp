#include "stdlib.h"
#include "stdio.h"

bool isComplete= true;
bool flag= false;
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

void visit(BiTNode *p){
    if(p->lchild==NULL&&p->rchild==NULL) flag= true;
    if(p->lchild==NULL&&p->rchild!=NULL) isComplete= false;
    if(p->lchild!=NULL&&p->rchild==NULL){
        if(flag) isComplete= false;
        flag = true;
    }
    if(p->lchild!=NULL&&p->rchild!=NULL)
        if(flag) isComplete= false;
}

void LevelOrder(BiTree T){//层序遍历判断完全二叉树(王道)
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    EnQueue(Q,T);
    while (!IsEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}

bool IsComplete(BiTree T){//递归调用判断完全二叉树(标准答案)
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    if(!T)
        return true;
    EnQueue(Q,T);
    while (!IsEmpty(Q)){
        DeQueue(Q,p);
        if(p){
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else
            while (!IsEmpty(Q)){
                DeQueue(Q,p);
                if(p)
                    return false;
            }
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
    if(isComplete)
        printf("二叉树L是完全二叉树\n");
    else printf("二叉树L不是完全二叉树\n");
    if(IsComplete(root))
        printf("二叉树L是完全二叉树");
    else printf("二叉树L不是完全二叉树");
    return 0;
}