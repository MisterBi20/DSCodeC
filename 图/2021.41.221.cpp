#include "stdio.h"
#define MaxSize 500

typedef struct{
    int numVertices,numEdges;
    char verticesList[MaxSize];
    int Edge[MaxSize][MaxSize];
}MGraph;

int IsExisEL(MGraph G){
    int count=0;
    for (int i = 0; i < G.numVertices; ++i) {
        int degree=0;
        for (int j = 0; j < G.numVertices; ++j)
            degree+=G.Edge[i][j];
        if(degree%2==1)
            count++;
    }
    if(count==0||count==2)
        return 1;
    else return 0;
}

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
    if(IsExisEL(G)==1)
        printf("G存在EL路径");
    else printf("G不存在EL路径");
    return 0;
}
//遍历判断是否存在EL路径,O(n^2),O(1)