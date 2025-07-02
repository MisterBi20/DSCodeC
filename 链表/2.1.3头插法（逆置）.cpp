#include "stdio.h"
#include "stdlib.h"
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void ListReserve(LinkList L){
    LinkList head=(LNode *) malloc(sizeof (LNode));
    head->next=NULL;
    while (L->next!=NULL){
        LNode *p=L->next;
        L->next=L->next->next;
        p->next=head->next;
        head->next=p;
    }
    L->next=head->next;
    free(head);
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
    ListReserve(head);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}

//头插法
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

LinkList Create(LinkList &head,int n){//尾插法
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        LNode *p=(LNode *) malloc(sizeof (LNode));
        p->data=x;
        p->next=head->next;
        head->next=p;
    }
    return head;
}

int main(){
    int n;
    LNode *p;
    LinkList head;
    InitList(head);
    scanf("%d",&n);
    head=Create(head,n);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}