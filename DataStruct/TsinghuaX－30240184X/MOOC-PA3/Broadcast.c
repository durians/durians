//http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=407
//1 ≤ n ≤ 10000  邻接矩阵存：10000*10000＊4 = 382MB
//1 ≤ m ≤ 30000
//m << n*(n-1)/2 邻接链表存
//BFS, parent
#include <stdio.h>
#include <stdlib.h>

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    ArcNode *firstarc;
    int visitparent;
}VNode, *AdjList;

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

void InitGraph(ALGraph *G)
{
    int n, m, i, vi, vj;
    struct ArcNode *arc1, *arc2;
    
    scanf("%d %d", &n, &m);
    
    //init G
    G->vexnum = n, G->arcnum = m;
    G->vertices = (struct VNode *)malloc(sizeof(struct VNode)*(n+1));
    
    //init v
    for(i = 0; i < n; i++)
    {
        G->vertices[i].firstarc = NULL;
        G->vertices[i].visitparent = 0;
    }
    
    //init arc
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &vi, &vj);
        
        //arc vi-->vj
        arc1 = (struct ArcNode *)malloc(sizeof(struct ArcNode));
        arc1->adjvex = vj;
        arc1->nextarc = G->vertices[vi].firstarc;
        G->vertices[vi].firstarc = arc1;
      
        //arc vj-->vi
        arc2 = (struct ArcNode *)malloc(sizeof(struct ArcNode));
        arc2->adjvex = vi;
        arc2->nextarc = G->vertices[vj].firstarc;
        G->vertices[vj].firstarc = arc2;
       
    }
}

void FreeGraph(ALGraph *G)
{
    int i;
    struct ArcNode *p, *q;
    
    for(i = 1; i <= G->vexnum; i++ )
    {
        //free arc
        p = G->vertices[i].firstarc;
        while(p)
        {
            q = p;
            p = p->nextarc;
            free(q), q = NULL;
        }
    }
    //free G
    free(G->vertices),G->vertices = NULL;
    G->vexnum = 0, G->arcnum = 0;
}

void visit(int vi)
{
    //printf("visited:%d\n",vi);
}

int bfs(ALGraph *G)
{
    int *q, f, r;
    int i, vi, vj;
    struct ArcNode *p;
    
    q = (int *)malloc(sizeof(int)*(G->vexnum));
    f = 0, r = 0;
    
    for( i = 1; i <= G->vexnum; i++)
    {
        if(!G->vertices[i].visitparent)
        {
            //visit(i);
            q[r] = i, r = (r+1) % G->vexnum;
            G->vertices[i].visitparent = -1;
            
            while(f != r)
            {
                vi = q[f], f = (f+1)%G->vexnum;
                
                for(p = G->vertices[vi].firstarc; p; p = p->nextarc)
                {
                    vj = p->adjvex;
                    if(!G->vertices[vj].visitparent)
                    {
                        //visite vj, parent is vi
                        //visit(vj);
                        q[r] = vj, r = (r+1) % G->vexnum;
                        G->vertices[vj].visitparent = vi;
                    }
                    else if (G->vertices[vj].visitparent == G->vertices[vi].visitparent)
                    {
                        //if vi->visitparent == vj->visitparent
                        return -1;
                    }
                    
                }
            }

        }
    }
    
    return 1;
}


int main(int argc, char *argv[])
{
    ALGraph G;
    
    InitGraph(&G);
    printf("%d\n",bfs(&G));
    FreeGraph(&G);
    return 0;
}

