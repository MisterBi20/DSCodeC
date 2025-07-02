#include "stdio.h"
#include "stdlib.h"

typedef struct BiTNode{
    int weight;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;

BiTNode *nowNode(int x){
    BiTNode *p=(BiTNode *) malloc((sizeof (BiTNode)));
    p->weight=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void insert(BiTree &root,int x){
    if(root==NULL){
        root= nowNode(x);
        return;
    }
    if(root->weight>x){
        insert(root->left,x);
    } else insert(root->right,x);
}

int WPL=0;
void func(BiTree root,int level){
    if(root==NULL) return;
    if(root->right==NULL&&root->left==NULL)
        WPL+=root->weight*level;
    func(root->left,level+1);
    func(root->right,level+1);
}

int main(){
    int x,n;
    BiTree root=NULL;//注意
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        insert(root,x);
    }
    func(root,0);
    printf("二叉树的WPL为%d",WPL);
    return 0;
}
//计算二叉树的WPL