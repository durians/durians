//

#include <stdlib.h>
#include <stdio.h>

typedef struct ArcNode{
    int adjvex;             // -->adjvex
    int price;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    ArcNode *firstarc;
    int indegree;
    int maxprice;
    ArcNode *priceway;
}AdjList;

typedef struct {
    AdjList *vertices;
    int vexnum,arcnum;
}ALGraph;

void InitGraph(ALGraph *G)
{
    int n, m;
    scanf("%d %d", &n, &m);
}

void FreeGraph(ALGraph *G)
{
   }

void visit(int i)
{
    //printf("visited: %d\n", i+1);
}

void TopologicalSort(ALGraph G)
{
    
}

int main()
{
    return 0;
}







