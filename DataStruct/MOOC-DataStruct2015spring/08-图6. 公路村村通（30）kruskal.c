#include <stdio.h>
#define    N    1000
#define    M    3*(N)

typedef struct ArcNode{
    
    int vi,vj,w;
}ArcNode;
ArcNode arcs[M+1], path[N+1];
int carc,cpath,mincost;
void push(ArcNode e);
ArcNode pop();

int parents[N+1];
void initial();
int find(int v);
void merge(int vi, int vj);

int n,m;
void kruskal()
{
    ArcNode e;
    while(cpath < n-1 && carc >0)
    {
        e = pop();
        if(find(e.vi) != find(e.vj))
        {
            merge(e.vi,e.vj);
            path[cpath++] = e;
            mincost += e.w;
        }
    }
}

void slove()
{
    int i;
    ArcNode e;
    
    // input
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d",&e.vi,&e.vj,&e.w);
        push(e);
    }
    initial();
    
    // kruskal
    kruskal();
    
    // output
    if(cpath == n-1) printf("%d\n", mincost);
    else printf("-1\n");
}


int main(int argc, char *argv[])
{
    slove();
    return 0;
}








void push(ArcNode e)
{
    int i = ++carc;
    
    for(; i/2 >= 1 && e.w < arcs[i/2].w; i /= 2 )
        arcs[i] = arcs[i/2];
    arcs[i] = e;
}


ArcNode pop()
{
    ArcNode e = arcs[1];
    ArcNode tmp = arcs[carc--];
    
    int i = 1 , j;
    
    for(j = 2*i; j <=carc; j *=2)
    {
        if(j < carc && arcs[j+1].w < arcs[j].w)
            j = j + 1;
        
        if(tmp.w < arcs[j].w) break;
        
        arcs[i] = arcs[j];
        i = j;
    }
    
    arcs[i] = tmp;
    
    return e;
}

void initial()
{
    int i;
    for(i = 1; i <= N; i++)
        parents[i] = -1;
}
int find(int v)
{
    if(parents[v] > 0)
        return parents[v] = find(parents[v]);
    else return v;
}


void merge(int vi, int vj)
{
    int s1 = find(vi);
    int s2 = find(vj);
    
    if(parents[s1] <= parents[s2])
    {
        //s1 += s2
        parents[s1] += parents[s2];
        parents[s2] = s1;
    }
    else
    {
        parents[s2] += parents[s1];
        parents[s1] = s2;
    }
}





