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

LinkList Get_common(LinkList &A,LinkList &B){
    LNode *p=A->next,*q=B->next,*r,*s;
    LinkList C=(LinkList) malloc(sizeof (LNode));
    r=C;
    while (p!=NULL&&q!=NULL){
        if(p->data>q->data)
            q=q->next;
        else if(p->data<q->data)
            p=p->next;
        else{
            s=(LNode *) malloc(sizeof (LNode));
            s->data=p->data;
            r->next=s;
            r=s;
            p=p->next;
            q=q->next;
        }
    }
    r->next=NULL;
    return C;
}

int main(){
    int n,m;
    LNode *p;
    LinkList head1=(LNode *) malloc(sizeof (LNode));
    LinkList head2=(LNode *) malloc(sizeof (LNode));
    head1->next=NULL;
    head2->next=NULL;
    scanf("%d%d",&n,&m);
    head1=Create(head1,n);
    head2=Create(head2,m);
    LinkList head;
    head= Get_common(head1,head2);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;
}