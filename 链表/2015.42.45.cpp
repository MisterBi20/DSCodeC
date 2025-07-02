#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode* link;
}LNode,*LinkList;

LinkList InitList(LinkList &L){
    L=(LinkList) malloc(sizeof (LNode));
    L->link=NULL;
    return L;
};

void Create(LinkList &L,int n){
    int x;
    LNode *p,*tail=L;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        p=(LNode*) malloc(sizeof (LNode));
        p->link=NULL;
        p->data=x;
        tail->link=p;
        tail=p;
    }
};

void Del_Same(LinkList &L){
    LNode *q=L->link;
    while (q!=NULL){
        LNode *p=q->link,*pre=q;
        while (p!=NULL)
            if(p->data==q->data||p->data==-q->data){
                pre->link=p->link;
                free(p);
                p=pre->link;//注意
            } else{
                p=p->link;
                pre=pre->link;
            }
        q=q->link;//注意
    }
}

int main(){
    int n;
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    Create(L,n);
    Del_Same(L);
    LNode *p=L->link;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->link;//注意
    }
    return 0;
}
//删除链表绝对值相同的节点,O(n^2),O(1)