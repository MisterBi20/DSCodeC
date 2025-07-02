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

bool Del_x(LinkList &L,int x){
    LNode *p=L->next,*pre=L,*q;
    while (p!=NULL){
        if(p->data==x){
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        } else{
            pre=p;
            p=p->next;
        }
    }
}

int Del_Min(LinkList &L,int &min){
    LNode *p=L->next,*pre=L,*minp=p,*minpre=pre;
    while (p!=NULL){
        if(p->data<minp->data){
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    min=minp->data;
    minpre->next=minp->next;
    free(minp);
    return min;
}

int main(){
    int n,min;
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
    min=Del_Min(head,min);
    Del_x(head,min);
    p=head->next;//注意
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}