#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L){
    L=(LinkList) malloc(sizeof (LNode));
    L->next=NULL;
}

void create(LinkList &L,int n){
    int x;
    LNode *tail=L;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        LNode *p=(LNode *) malloc(sizeof (LNode));
        p->data=x;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}

void func(LinkList &L){
    LNode *p,*q,*r,*s;
    p=q=L;
    while (q->next!=NULL){
        p=p->next;
        q=q->next;
        if(q->next!=NULL) q=q->next;
    }
    q=p->next;
    p->next=NULL;
    while (q!=NULL){
        r=q->next;
        q->next=p->next;
        p->next=q;
        q=r;
    }
    s=L->next;
    q=p->next;
    p->next=NULL;
    while (q!=NULL){
        r=q->next;
        q->next=s->next;
        s->next=q;
        s=q->next;
        q=r;
    }
}
int main(){
    int n;
    LNode *p;
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    create(L,n);
    func(L);
    p=L->next;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
//分组逆置组合,O(n)