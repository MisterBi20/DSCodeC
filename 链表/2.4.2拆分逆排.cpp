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

LinkList DisCreate(LinkList &head1){
    LinkList head2=(LinkList) malloc(sizeof (LNode));
    head2->next=NULL;
    LNode *p=head1->next,*q;
    LNode *ra=head1;
    while (p!=NULL){
        ra->next=p;
        ra=p;
        p=p->next;
        if(p!=NULL){
            q=p->next;
            p->next=head2->next;
            head2->next=p;
            p=q;
        }
    }
    ra->next=NULL;
    return head2;
}

int main(){
    int n;
    LNode *p;
    LinkList head1=(LNode *) malloc(sizeof (LNode));
    head1->next=NULL;
    LinkList head2=(LNode *) malloc(sizeof (LNode));
    head2->next=NULL;
    scanf("%d",&n);
    head1=Create(head1,n);
    head2=DisCreate(head1);
    p=head1->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    p=head2->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}