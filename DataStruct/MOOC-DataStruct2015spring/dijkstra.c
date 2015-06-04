//
//  dijkstra.c
//
//  Created by durians on 15/6/2.
//  Copyright (c) 2015年 Cask. All rights reserved.
//

#define INF 0x7fffffff
#define N   500
int arcs[N][N];

int S[N];  //最短路径集合,1在S集合，0不在S集合
int D[N];  //(S,U-S)最短路长
int P[N];  //路径

int n,m,s,d;// n 个顶点，m条边，s出发，目标d

void djklstra()
{
    int i, v;
    
    // init
    for(i = 0; i < n; i++)
    {
        S[i] = 0;D[i] = arcs[s][i];P[i] = s;
    }
    S[s] = 1,D[s] = 0,P[s] = -1;
    
    while(1)
    {
        // min D[v]
        for(v = -1, i = 0; i < n; i++)
        {
            if(!S[i] && (v==-1 || D[i] < D[v]))
                v = i;
        }
        
        if(v == -1 || D[v] == INF)
            break;
        
        S[v] = 1;
        
        for(i = 0; i < n; i++)
        {
            if(D[v] + arcs[v][i] < D[i])
            {
                D[i] = D[v] + arcs[v][i];
                P[i] = v;
            }
        }
    }
    
}

