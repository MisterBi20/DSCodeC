#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L){
    L=(LNode *) malloc(sizeof (LNode));
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

void insert_x(LinkList &L,int key){
    LNode *p=L->next,*pre=L;
    while (p->data<key){
        p=p->next;
        pre=pre->next;
    }
    LNode *x=(LNode *) malloc(sizeof (LNode));
    x->data=key;
    x->next=p;
    pre->next=x;
}

int main(){
    int key,n;
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    create(L,n);
    scanf("%d",&key);
    insert_x(L,key);
    LNode *p=L->next;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}