#include<stdio.h>
#include<stdlib.h>

#define INF 0x7fffffff
#define N   500

typedef struct{int vi,vj,len,cost;}Edge;
Edge *edge;
int D[N],C[N],P[N];

int n,m,s,d;

void bellman_ford()
{
    Edge e;
    int i, update;
    for(i = 0; i < n; i++)
        C[i] = D[i] = INF,P[i] = s;
    D[s] = 0;C[s] = 0;P[s] = -1;
    
    while(1)
    {
        update = 0;
        for(i = 0; i < m; i++)
        {
            e = edge[i];
            
            if(D[e.vi] != INF &&
               (D[e.vi] + e.len < D[e.vj] ||
               (D[e.vi] + e.len == D[e.vj]&& C[e.vi] + e.cost < C[e.vj])) )
            {
                D[e.vj] = D[e.vi] + e.len;
                C[e.vj] = C[e.vi] + e.cost;
                P[e.vj] = e.vi;
                update = 1;
            }
            
            if(D[e.vj] != INF &&
               (D[e.vj] + e.len < D[e.vi] ||
               (D[e.vj] + e.len == D[e.vi]&& C[e.vj] + e.cost < C[e.vi])) )
            {
                D[e.vi] = D[e.vj] + e.len;
                C[e.vi] = C[e.vj] + e.cost;
                P[e.vi] = e.vj;
                update = 1;
            }
        }
        
        if(!update) break;
    }
}

void slove()
{
    int k;
    scanf("%d %d %d %d", &n,&m,&s,&d);
    
    edge = (Edge*)malloc(sizeof(Edge)*m);
    for(k = 0; k < m; k++)
    {
        scanf("%d %d %d %d", &edge[k].vi,&edge[k].vj,&edge[k].len,&edge[k].cost);
    }
    
    bellman_ford();
    
    printf("%d %d\n",D[d],C[d]);
    free(edge),edge=NULL;
}



int main()
{
    slove();
    return 0;
}

