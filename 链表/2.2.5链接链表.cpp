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
        s->next=head;//注意
        tail->next=s;
        tail=s;
    }
    return head;
}

LinkList Link(LinkList &head1,LinkList &head2){
    LNode *p=head1,*q=head2;
    while (p->next!=head1)
        p=p->next;
    while (q->next!=head2)
        q=q->next;
    p->next=head2->next;
    q->next=head1;
    return head1;
}

int main(){
    int n,m;
    LNode *p;
    LinkList head1=(LNode *) malloc(sizeof (LNode));
    head1->next=head1;
    LinkList head2=(LNode *) malloc(sizeof (LNode));
    head2->next=head2;
    scanf("%d%d",&n,&m);
    head1=Create(head1,n);
    head2=Create(head2,m);
    Link(head1,head2);
    p=head1->next;//注意
    while (p!=head1) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}