//

#include <stdlib.h>
#include <stdio.h>

typedef struct ArcNode{
    int adjvex;// -->adjvex
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    ArcNode *firstarc;
    int indegree;
    int maxheigh;
}AdjList;

typedef struct {
    AdjList *vertices;
    int vexnum,arcnum;
}ALGraph;

void InitGraph(ALGraph *G)
{
    int n, m, i, v1, v2;
    struct ArcNode *newArc;
    
    scanf("%d %d", &n, &m);
    
    G->vexnum = n;
    G->arcnum = m;
    G->vertices = (AdjList*)malloc(sizeof(AdjList)*n);
    
    //init v
    for (i = 0; i < n; i++) {
        G->vertices[i].indegree = 0;
        G->vertices[i].maxheigh = 1;
        G->vertices[i].firstarc = NULL;
    }
    
    //init arc
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &v1, &v2);
        
        newArc = (struct ArcNode*)malloc(sizeof(struct ArcNode));
        newArc->adjvex = v2 - 1;
        newArc->nextarc= G->vertices[v1 -1].firstarc;
        
        G->vertices[v1 - 1].firstarc= newArc;
        G->vertices[v2 - 1].indegree++;
    }
    
}

void FreeGraph(ALGraph *G)
{
    int n, i;
    struct ArcNode *p, *q;
    
    n = G->vexnum;
    
    for(i = 0; i < n; i++)
    {
        p = G->vertices[i].firstarc;
        while(p)
        {
            q = p;
            p = p->nextarc;
            free(q), q = NULL;
        }
    }
    free(G->vertices), G->vertices = NULL;
    G->vexnum = 0, G->arcnum = 0;
}

void visit(ALGraph G, int i)
{
    //printf("visited: %d\n", i+1);
}

int TopologicalSort(ALGraph G)
{
    int i, max = 1;
    int *stack, top = -1;
    struct ArcNode *p;
    
    stack = (int *)malloc(sizeof(int)*(G.vexnum));
    
    for(i = 0; i < G.vexnum; i++)
    {
        if(!G.vertices[i].indegree)
            stack[++top] = i;
    }
    while(top >= 0)
    {
        i = stack[top--]; visit(G,i);
        for(p = G.vertices[i].firstarc; p; p = p->nextarc)
        {
            if(!(--G.vertices[p->adjvex].indegree) )
                stack[++top] = p->adjvex;
            
            if(G.vertices[p->adjvex].maxheigh < G.vertices[i].maxheigh + 1)
                G.vertices[p->adjvex].maxheigh =G.vertices[i].maxheigh + 1;
            if(max < G.vertices[p->adjvex].maxheigh)
                max = G.vertices[p->adjvex].maxheigh;
        }
    }
    free(stack),stack = NULL;
    
    return max;
}

int main()
{
    ALGraph G;
    InitGraph(&G);
    printf("%d\n",TopologicalSort(G));
    FreeGraph(&G);
    return 0;
}







