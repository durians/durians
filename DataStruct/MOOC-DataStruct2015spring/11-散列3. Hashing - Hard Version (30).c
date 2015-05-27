//
//  11-散列3. Hashing - Hard Version (30)
//  http://www.patest.cn/contests/mooc-ds2015spring/11-散列3
//
//  Created by durians on 15/5/25.
//
//

/*
 根据给出的hash表，求表的原始输入顺序
 H(x) = x%N ，linear probing to solve collisions
 
 Sample Input:
 11
 33 1 13 12 34 38 27 22 32 -1 21
 
 Sample Output:
 1 13 12 21 33 34 38 27 22 32
 
 拓扑排序
 
 如果 H(v[i])!= i
 则，[H(v[i]), i)都是v[i]的前驱
 用图来表达前驱后继，拓扑排序（多个取最小的）
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _arc
{
    int adjv;
    struct _arc *next;
}Arc;

typedef struct _vnode
{
    int data;
    int indeed;
    Arc *firstarc;
}VNode;

typedef struct _graphic
{
    VNode *v;
    int vnum;
}Graphic;

void Destory(Graphic *G)
{
    int i;
    Arc *p, *q;
    
    //free arc
    for(i = 0; i < G->vnum; i++)
    {
        p = G->v[i].firstarc;
        while(p){
            q = p, p = p->next;
            free(q),q = NULL;
        }
    }
    //free v
    free(G->v),G->v = NULL;
}

void Create(Graphic *G)
{
    int i, hash;
    Arc *newarc;
    
    //get input
    scanf("%d",&G->vnum);
    G->v = (VNode *)malloc(sizeof(VNode)*G->vnum);
    for(i = 0; i < G->vnum; i++)
    {
        scanf("%d",&(G->v[i].data));
        G->v[i].indeed = (G->v[i].data >= 0) ? 0 : -1;
        G->v[i].firstarc = NULL;
    }
    
    //create arc [hash, i): v[hash]-->v[i],
    for(i = 0; i < G->vnum; i++)
    {
        if(G->v[i].data < 0) continue;
        
        for(hash = G->v[i].data % G->vnum;
            hash != i;
            hash = (hash + 1) % G->vnum)
        {
            //newarc: v[hash]-->v[i]
            newarc = (Arc *)malloc(sizeof(Arc));
            newarc->adjv = i, newarc->next = G->v[hash].firstarc;
            G->v[hash].firstarc = newarc;
            
            G->v[i].indeed++;
        }
    }
}

void InsertHeap(VNode heap[], int n, VNode e)
{
    int i;
    for(i = n; i/2 >= 1 && e.data < heap[i/2].data; i = i / 2)
        heap[i] = heap[i/2];
    heap[i] = e;
}

VNode RemoveHeap(VNode heap[], int n)
{
    int i = 1;
    VNode e,t;
    
    e = heap[1], heap[1] = heap[n--];
    
    while( i < n)
    {
        if(2*i + 1 <= n &&
           heap[2*i+1].data < heap[2*i].data &&
           heap[2*i+1].data < heap[i].data)
        {
            t = heap[i],heap[i] = heap[2*i+1], heap[2*i+1] = t;
            i = 2*i + 1;
        }
        else if(2*i <= n && heap[2*i].data < heap[i].data)
        {
            t = heap[i],heap[i] = heap[2*i], heap[2*i] = t;
            i = 2*i;
        }
        else break;
    }
    
    return e;
}
void SloveByTopoSort(Graphic *G)
{
    int i, n = 0;
    VNode e, *heap = (VNode *)malloc(sizeof(VNode)*G->vnum);
    Arc *arc;
    
    for(i = 0; i < G->vnum; i++)
    {
        if(0 == G->v[i].indeed)
        {
            InsertHeap(heap,++n,G->v[i]);
        }
    }
    
    while(n > 0)
    {
        e = RemoveHeap(heap,n--);
        printf("%d",e.data);
        for(arc = e.firstarc; arc!=NULL; arc = arc->next)
        {
            if(0 == (--G->v[arc->adjv].indeed))
                InsertHeap(heap, ++n, G->v[arc->adjv]);
        }
        if(n > 0) printf(" ");
    }
    
    free(heap),heap = NULL;
}
int main()
{
    Graphic G;
    
    Create(&G);
    SloveByTopoSort(&G);
    Destory(&G);
    
    return 0;
}









