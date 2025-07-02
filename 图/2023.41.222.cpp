#include "stdio.h"
#define MaxSize 500

typedef struct{
    int numVertices,numEdges;
    char verticesList[MaxSize];
    int Edge[MaxSize][MaxSize];
}MGraph;

int PrintVertices(MGraph G){
    int count=0;
    for (int i = 0; i < G.numVertices; ++i) {
        int Vout=0,Vin=0;
        for (int j = 0; j < G.numVertices; ++j) {
            Vout+=G.Edge[i][j];
            Vin+=G.Edge[j][i];
        }
        if(Vout>Vin){
            printf("%c\n",G.verticesList[i]);
            count++;
        }
    }
    return count;
}

int main(){
    int x;
    char a;
    MGraph G;
    scanf("%d",&x);
    G.numVertices=x;
    for (int i = 0; i < G.numVertices; ++i) {
        getchar();
        scanf("%c",&a);
        G.verticesList[i]=a;
    }
    for (int i = 0; i < G.numVertices; ++i) {
        for (int j = 0; j < G.numVertices; ++j) {
            scanf("%d",&x);
            G.Edge[i][j]=x;
        }
    }
    printf("K点的个数为%d", PrintVertices(G));
    return 0;
}
//遍历寻找K点