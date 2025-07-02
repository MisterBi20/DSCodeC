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

bool Pattern(LinkList &A,LinkList &B){
    LNode *p=A->next;//注意
    LNode *pre=p;
    LNode *q=B->next;
    while (p&&q)
        if(p->data==q->data){
            p=p->next;
            q=q->next;
        } else{
            pre=pre->next;
            p=pre;
            q=B->next;
        }
    if(q==NULL)
        return true;
    else return false;
}

int main(){
    int n,m;
    LinkList head1=(LNode *) malloc(sizeof (LNode));
    LinkList head2=(LNode *) malloc(sizeof (LNode));
    head1->next=NULL;
    head2->next=NULL;
    scanf("%d",&n);
    head1=Create(head1,n);
    scanf("%d",&m);
    head2=Create(head2,m);
    if(Pattern(head1,head2))
        printf("B是A的连续子序列");
    else printf("B不是A的连续子序列");
    return 0;
}