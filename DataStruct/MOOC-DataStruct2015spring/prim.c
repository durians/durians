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
    
    D[0] = Infinite; D[1] = 0;
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

