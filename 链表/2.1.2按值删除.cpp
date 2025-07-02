#include "stdio.h"
#include "stdlib.h"
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void delectX(LinkList L,int x){
    LNode *pre=L;
    LNode *p=pre->next;//双指针
    while (p!=NULL){
        if(p->data==x){
            LNode *q=p;
            p=p->next;
            pre->next=p;
            free(q);
        } else{
            pre=p;
            p=p->next;
        }
    }
}
int main(){
    int x,n,del;
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
    scanf("%d",&del);
    delectX(head,del);
    p=head->next;//注意
    while (p!=NULL){//注意n-1
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
    LNode *tail=L;//注意
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

void func(LinkList &L,int key){
    LNode *p=L->next,*pre=L;
    while (p!=NULL){
        if(p->data==key){
            p=p->next;
            pre->next=p;
        } else {
            p=p->next;
            pre=pre->next;
        }
    }
}

int main(){
    int n,key;
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    create(L,n);
    scanf("%d",&key);
    func(L,key);
    LNode *p=L->next;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}