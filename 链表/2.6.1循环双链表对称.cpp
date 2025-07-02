#include "stdio.h"
#include "stdlib.h"
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;
int Symmetry(DLinkList L){
    DNode *p=L->next,*q=L->prior;
    while (p!=q&&q->next!=p)
        if(p->data==q->data){
            p=p->next;
            q=q->prior;
        } else
            return 0;
    return 1;
}
int main(){
    int x,n;
    DNode *p;
    DLinkList head=(DNode *) malloc(sizeof (DNode));
    head->prior=NULL;
    head->next=NULL;
    DNode *tail=head;
    scanf("%d",&n);//构建循环双链表
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        DNode *s=(DNode*) malloc(sizeof (DNode));
        s->data=x;
        s->next=NULL;//注意
        tail->next=s;
        s->prior=tail;
        tail=s;
    }
    tail->next=head;
    head->prior=tail;//循环双链表构建完成
    p=head->next;//注意
    do{//注意n-1
        printf("%d ",p->data);
        p=p->next;
    } while (p!=head);
    if(Symmetry(head)==1)
        printf("对称");
    else
        printf("不对称");
    return 0;
}