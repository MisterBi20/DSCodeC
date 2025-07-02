#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Reverse(LinkList L){
    LNode *p,*r;
    p=L->next;
    L->next=NULL;
    while (p!=NULL){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}

int main(){
    int x,n;
    LNode *p;
    LinkList head=(LNode *) malloc(sizeof (LNode));
    head->next=NULL;
    LNode *tail=head;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        LNode *s=(LNode*) malloc(sizeof (LNode));
        s->data=x;
        s->next=NULL;//注意
        tail->next=s;
        tail=s;
    }
    Reverse(head);
    p=head->next;//注意
    while (p!=NULL){//注意n-1
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}