#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Create(LinkList &head,int n){//尾插法
    int x;
    LNode *tail=head;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        LNode *s=(LNode*) malloc(sizeof (LNode));
        s->data=x;
        s->next=NULL;//注意
        tail->next=s;
        tail=s;
    }
    return head;
}

bool RangeDel(LinkList &L,int min,int max){
    LNode *p=L->next,*pre=L;
    while (p!=NULL){
        if(p->data<max&&p->data>min){
            pre->next=p->next;
            free(p);
            p=pre->next;
        } else{
            pre=p;
            p=p->next;
        }
    }
    return true;
}

int main(){
    int x,n,min,max;
    LNode *p;
    LinkList head=(LNode *) malloc(sizeof (LNode));
    head->next=NULL;
    scanf("%d",&n);
    head=Create(head,n);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    scanf("%d%d",&min,&max);
    RangeDel(head,min,max);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}