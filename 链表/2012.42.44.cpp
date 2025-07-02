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

void Create(Linklist &L,int n){
    int x;
    LNode *tail=L;
    getchar();
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        LNode *p=(LNode *) malloc(sizeof (LNode));
        p->data=x;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}

int Listlen(Linklist L){
    int count=0;
    LNode *p=L->next;
    while (p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

LNode *func(Linklist L1,Linklist L2){
    int m,n;
    LNode *p,*q;
    m= Listlen(L1);
    n= Listlen(L2);
    for (p=L1; m > n ; m--)
        p=p->next;
    for (q=L2; n > m ; n--)
        q=q->next;
    while (p->next!=NULL&&p->next!=q->next){
        p=p->next;
        q=q->next;
    }
    return p->next;
}

int main(){
    int n,m;
    Linklist L1,L2;
    InitList(L1);
    InitList(L2);
    scanf("%d",&n);
    Create(L1,n);
    scanf("%d",&m);
    Create(L2,m);
    LNode *p=L1->next;
    while (p->next!=NULL)
        p=p->next;
    p->next=L2->next->next->next->next;
    p=func(L1,L2);
    printf("%d",p->data);
    return 0;
}
//寻找公共后缀起始点,O(m+n)