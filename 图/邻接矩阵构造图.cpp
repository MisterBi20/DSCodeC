#include "stdio.h"
#define MaxSize 500

typedef struct{
    int numVertices,numEdges;
    char verticesList[MaxSize];
    int Edge[MaxSize][MaxSize];
}MGraph;

int main(){
    int x;
    MGraph G;
    scanf("%d",&x);
    G.numVertices=x;
    for (int i = 0; i < G.numVertices; ++i) {
        for (int j = 0; j < G.numVertices; ++j) {
            scanf("%d",&x);
            G.Edge[i][j]=x;
        }
    }
    for (int i = 0; i < G.numVertices; ++i) {
        for (int j = 0; j < G.numVertices; ++j) {
            printf("%d ",G.Edge[i][j]);
        }
        printf("\n");
    }
    return 0;
}