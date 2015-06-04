//
//  kruskal.c
//  最小生成树kruskal算法
//  假设连通网N = (V,{E})，求最小生成树边TE的集合。
//      1.初始：TE={}，Ui={vi}（i=1,2,3,...）
//      2.从E中选择一条最小的边e
//        e的两个顶点vi,vj分别在不同的集合Ui,Uj中则
//          #1 Ui += Uj
//          #2 TE += {e}
//      3.继续2，U=V时结束。
//
//  Created by durians on 15/5/31.
//
//

#include <stdio.h>
#define N   1000

int V[N];

typedef struct Edge
{
    int vi,vj,w;
}Edge;
Edge E[N],TE[N];
int count,mincost;

int kruskal()
{
    while(parent[find(1)] != N)
    {
        Edge e = pop();
        
        if(find(e.vi) != find(e.vj))
        {
            merge(e.vi,e.vj);
            TE[count++] = e;
            mincost += e.w;
        }
    }
    return mincost;
}



