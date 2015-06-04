#include<stdio.h>

#define INF 1000
#define N   500

typedef struct{int len,cost;}ArcNode;
ArcNode arcs[N][N];

int S[N],D[N],C[N],P[N];

int n,m,s,d;

void djklstra()
{
    int i, v;
    
    // init
    for(i = 0; i < n; i++)
    {
        S[i] = 0;
        D[i] = arcs[s][i].len;
        C[i] = arcs[s][i].cost;
        P[i] = s;
    }
    S[s] = 1,D[s] = 0,C[s] = 0,P[s] = -1;
    
    while(1)
    {
        // min D[v] cost[v]
        for(v = -1, i = 0; i < n; i++)
        {
            if(!S[i] &&
               (v==-1 || D[i] < D[v] ||
               (D[i] == D[v] && C[i] < C[v])))
                v = i;
        }
        
        if(v == -1 || D[v] == INF)
            break;
        
        S[v] = 1;
        
        for(i = 0; i < n; i++)
        {
            if(D[v] + arcs[v][i].len < D[i] ||
               (D[v] + arcs[v][i].len == D[i] &&
                C[v] + arcs[v][i].cost < C[i]))
            {
                D[i] = D[v] + arcs[v][i].len;
                C[i] = C[v] + arcs[v][i].cost;
                P[i] = v;
            }
        }
    }
    
}

void slove()
{
    int i,j,len,cost,k;
    scanf("%d %d %d %d", &n,&m,&s,&d);
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            arcs[i][j].len = INF;
            arcs[i][j].cost = INF;
        }
    }
    
    for(k = 1; k <= m; k++)
    {
        scanf("%d %d %d %d", &i,&j,&len,&cost);
        arcs[i][j].len = len, arcs[i][j].cost = cost;
        arcs[j][i].len = len, arcs[j][i].cost = cost;
    }
    
    djklstra();
    
    printf("%d %d\n",D[d],C[d]);
}



int main()
{
    slove();
    return 0;
}

