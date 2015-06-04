#include <stdio.h>
#define    N    1000
#define    M    3*(N)
#define    Infinite    (0x7fffffff)

int arcs[N+1][N+1];
int D[N+1];
int mincost;

int n,m;

void prim()
{
    int i=1,j, v;
    
// 初始U = {1}, TE={}
//    辅助数组dis[]表示(U,V-U)的边集合
//       D[v]=0: v在U中
//       D[v]>0: v在V－U中，且U到v的最小距离为dis[v]    
//
// #1 在V-D[v]
//        即：( v = min(D[]) ) && D[v] > 0
//
// #2 把v加入到U中，更新D[]
//
// #3 重复＃1#2,直到U＝V
    
    
    
    for(v = 2; v <= n; v++)
        D[v] = arcs[1][v];
    
    while(++i <= n)
    {
        //find v：
        //    #1 v在V－U
        //    #2 (U,v)最小 
        for(v = 0,j=1; j<=n; j++)
        {
            if(D[j] > 0 && D[j] < D[v])
            {
                v = j;
            }
        }
        if(!v) return ;
        
        
        mincost += D[v];
 
        //add v to U ; update (U,V-U)
        for(D[v] = 0, j = 1; j <= n; j++)
        {
            if(arcs[v][j] < D[j])
            {
                D[j] = arcs[v][j];
            }
        }
    }
}

void slove()
{
    int i, j, k,w;
    
    // input
    scanf("%d %d", &n, &m);
    
    //initial
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            arcs[i][j] = Infinite;
        }
    }
    for(k = 0; k < m; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        arcs[i][j] = arcs[j][i] = w;
    }
    

    
    // prim
    prim();
    
    // output
    for(i = 1; i <= n; i++)
        if(D[i])
        {
            printf("-1\n");
            return ;
        }
    
    
    printf("%d\n",mincost);
    
    
}


int main(int argc, char *argv[])
{
    slove();
    return 0;
}




