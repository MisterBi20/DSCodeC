#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int listLen(LinkList L){
    int length=0;
    LNode *p=L->next;
    while (p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}

LNode *findMidNode(LinkList L){
    int length;
    length=listLen(L);
    int count=0;
    LNode  *p=L->next;
    while (p!=NULL){
        count++;
        if(count==length/2)
            break;
        p=p->next;
    }
    return p;
}

int main(){
    int x,n,length;
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
    length=listLen(head);
    printf("链表的长度为%d\n",length);
    p= findMidNode(head);
    printf("链表的中间值为%d\n",p->data);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}

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

int find_mid(LinkList L){
    int count=0;
    LNode *p=L->next;
    while (p!=NULL){
        count++;
        p=p->next;
    }
    p=L->next;
    for (int i = 0; i < (count-1)/2; ++i)
        p=p->next;
    return p->data;
}

int main(){
    int n;
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    create(L,n);
    printf("中间数为%d\n", find_mid(L));
    LNode *p=L->next;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}