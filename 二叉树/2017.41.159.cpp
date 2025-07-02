#include "stdio.h"
#include "stdlib.h"

typedef struct BiTNode{
    char data;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;

BiTNode *newNode(char v){
    BiTNode *p=(BiTNode *) malloc(sizeof (BiTNode));
    p->data=v;
    p->left=p->right=NULL;
    return p;
}

void BtreeToExp(BiTree root,int deep){
    if(root==NULL) return;
    else if(root->left==NULL&&root->right==NULL)
        printf("%c",root->data);
    else{
        if(deep>1) printf("(");
        BtreeToExp(root->left,deep+1);
        printf("%c",root->data);
        BtreeToExp(root->right,deep+1);
        if(deep>1) printf(")");
    }
}

void BtreeToE(BiTree root){
    BtreeToExp(root,1);
}

int main(){
    BiTree root=NULL;
    root= newNode('*');
    root->left=newNode('+');
    root->right= newNode('*');
    root->left->left= newNode('a');
    root->left->right= newNode('b');
    root->right->left= newNode('c');
    root->right->right= newNode('-');
    root->right->right->right= newNode('d');
    BtreeToE(root);
    return 0;
}
//中序遍历输出表达式