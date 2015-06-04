//http://www.patest.cn/contests/mooc-ds/06-图8

#include<stdio.h>
#include<stdlib.h>

#define N 101
#define INF 0x7fffffff

typedef struct Edge
{
    int vi, vj, w,d;
}Edge;

Edge *edge;

int P[N];
int E[N];
int L[N];
int deadline;

int n,m;

void earliest()
{
    int i , j, v;
    
    for(i = 1; i <= n; i++) E[P[i]] = 0;
    
    for(i = 1; i <= n; i++)
    {
        for(v = P[i], j = 0; j < m; j++)
        {
            if(edge[j].vi == v && E[edge[j].vj] < E[v] + edge[j].w )
                E[edge[j].vj] = E[v] + edge[j].w;
        }
        if(E[P[i]] > deadline) deadline = E[P[i]];
    }
}

void lastest()
{
    int i,v,j;
    
    for(i = 1; i <= n; i++) L[P[i]] = deadline;
    
    for(i = n; i > 0; i--)
    {
        for(v = P[i], j = 0; j < m; j++)
        {
            if(edge[j].vj == v &&  L[v] -  edge[j].w < L[edge[j].vi])
                L[edge[j].vi] = L[v] - edge[j].w;
        }
    }
}

void flexible()
{
    int i;
    for(i = 0; i < m; i++)
    {
        edge[i].d = L[edge[i].vj] - E[edge[i].vi] - edge[i].w;
    }
}

void sortedge()
{
    int i,j,k;
    Edge e;
    
    //insert sort
    for(i = 1; i < m; i++)
    {
        j = 0;
        e = edge[i];
        while(j < i &&  edge[j].vi < edge[i].vi)
            j++;
        
        for(k = i; k > j; k--)
            edge[k] = edge[k - 1];
        
        edge[j] = e;
    }
}

int topoSort()
{
    int indeed[N] = {0} , i, v, j = 0;
    int q[N],r = 0, f = 0;
    
    for(i = 0; i < m; i++)
        indeed[edge[i].vj]++;
    
    for(v = 1; v <= n; v++)
        if(indeed[v] == 0) q[r++] = v;
    
    while(r!=f)
    {
        P[++j] = v = q[f++];
        
        for(i = 0; i < m; i++)
        {
            if(edge[i].vi == v)
            {
                if(--indeed[edge[i].vj] == 0)
                    q[r++] = edge[i].vj;
            }
            
        }
        
    }
    
    return j == n;
}

void slove()
{
    int i;
    
    scanf("%d %d", &n, &m);
    
    edge = (Edge *)malloc(sizeof(Edge)*m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d",&edge[i].vi,&edge[i].vj,&edge[i].w);
    }
    sortedge();

    if(topoSort())
    {
        earliest();lastest();flexible();
        
        printf("%d\n",deadline);
        for(i = 0; i < m; i++)
        {
            if(edge[i].d == 0)
                printf("%d->%d\n",edge[i].vi,edge[i].vj);
        }
    }
    else printf("0\n");
    
    free(edge),edge = NULL;

}

int main()
{
    slove();
    return 0;
}


