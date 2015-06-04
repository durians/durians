//
//  poj3723.c
//  
//
//  Created by durians on 15/6/1.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{int vi,vj,w;}Edge;
#define M    10000

Edge edge[2*M+50000];

int ecount;
int parents[2*M];

int n, m, r;

int cmp(const void *p, const void *q)
{
    Edge *e1 = (Edge *)p;
    Edge *e2 = (Edge *)q;
    
    return e1->w - e2->w;
}

int find(int vi)
{
    if(parents[vi] >= 0)
        return parents[vi] = find(parents[vi]);
    else return vi;
}

void merge(int vi, int vj)
{
    int s1 , s2;
    
    s1 = find(vi);
    s2 = find(vj);
    
    if(parents[s1] <= parents[s2])
    {
        parents[s1] += parents[s2];
        parents[s2] = s1;
    }
    else
    {
        parents[s2] += parents[s1];
        parents[s1] = s2;
    }
}
int kruskal()
{
    Edge e;
    int mincost = 10000, i;
    
    for(i = 0; i < ecount; i++)
    {
        e = edge[i];
        if(find(e.vi) != find(e.vj))
        {
            merge(e.vi,e.vj);
            mincost += e.w;
            
            if(parents[find(e.vi)] == - (n+m) )
            {
                return mincost;
            }
        }
    }
    
    return 0;//Inf Error
}

void slove()
{
    int i, j, d;
    
    scanf("%d %d %d", &n, &m, &r);
    ecount = 0;
    
    while(r--)
    {
        scanf("%d %d %d",&i,&j,&d);
        edge[ecount].w = 10000 - d;
        edge[ecount].vi = i;
        edge[ecount].vj = n+j;
        ecount++;
    }
    qsort(edge,ecount,sizeof(edge[0]),cmp);
    
    for(parents[0] = -1,i = 1; i < n+m; i++)
    {
        parents[i] = -1;
        
        edge[ecount].w = 10000;
        edge[ecount].vi = 0;
        edge[ecount].vj = i;
        ecount++;
    }    
    

    printf("%d\n", kruskal());
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--)slove();
    
    return 0;
}