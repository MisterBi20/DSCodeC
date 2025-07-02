#include "stdio.h"
#include "stdlib.h"
#define MaxV 6

typedef struct EdgeNode{
    int index;
    struct EdgeNode *next;
    int weight;
}EdgeNode;

typedef struct VertexNode{
    char data;
    EdgeNode *first;
}VertexNode,VertexList[MaxV];

typedef struct {
    VertexList list;
    int numVertex,numEdge;
}ALGraph;

void AddEdge(ALGraph *G,int i,int j,int weight){
    EdgeNode *p=(EdgeNode *) malloc(sizeof (EdgeNode));
    p->weight=weight;
    p->index=j;
    p->next=G->list[i].first;
    G->list[i].first=p;
}

int main(){
    ALGraph *G=(ALGraph *) malloc(sizeof (ALGraph));
    for (int i = 0; i < MaxV; ++i)
        G->list[i].first=NULL;
    G->numVertex=4;
    G->numEdge=5;
    G->list[0].data='a';
    G->list[1].data='b';
    G->list[2].data='c';
    G->list[3].data='d';
    AddEdge(G,0,3,1);
    AddEdge(G,1,3,1);
    AddEdge(G,1,3,1);
    AddEdge(G,1,2,1);
    AddEdge(G,2,3,1);
    return 0;
}