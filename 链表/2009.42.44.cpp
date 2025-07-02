#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *link;
}LNode,*LinkList;

bool InitList(LinkList &L){
    L= (LinkList) malloc(sizeof (LNode));
    L->link=NULL;
    return true;
}

bool create(LinkList &L,int n){
    int x;
    LNode *p,*tail=L;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        p=(LNode *) malloc(sizeof (LNode));
        p->data=x;
        p->link=NULL;
        tail->link=p;
        tail=p;
    }
    return true;
}

bool func(LinkList L,int k,int &data){
    int count=0;
    LNode *p=L->link;
    while (p!=NULL){
        p=p->link;
        count++;
    }
    if(k<1||k>count)
        return false;
    p=L->link;
    for (int i = 0; i < count-k; ++i) {
        p=p->link;
    }
    data=p->data;
    return true;
}

int main(){
    int k,n,data;
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    create(L,n);
    scanf("%d",&k);
    if(func(L,k,data)){
        printf("%d",data);
        return 1;
    } else return 0;
}
//链表倒数k位数数值,O(n),O(1)
#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Linklist;

void InitList(Linklist &L){
    L=(Linklist) malloc(sizeof (LNode));
    L->next=NULL;
}

void create(Linklist &L,int n){
    LNode *tail=L;
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        LNode *p=(LNode *) malloc(sizeof (LNode));
        p->data=x;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}

int func(Linklist L,int k){
    int count=0;
    LNode *p=(LNode *) malloc(sizeof (LNode));
    p=L->next;
    while (p!=NULL){
        count++;
        p=p->next;
    }
    if(k<1||k>count) return 0;
    p=L->next;
    for (int i = 0; i < count-k; ++i) {
        p=p->next;
    }
    printf("倒数第%d个数的值为%d",k,p->data);
    return 1;
}

int main(){
    int n,k;
    Linklist p;
    InitList(p);
    scanf("%d",&n);
    create(p,n);
    scanf("%d",&k);
    return func(p,k);
}