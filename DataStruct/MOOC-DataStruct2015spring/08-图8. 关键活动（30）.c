#include<stdio.h>
#include<stdlib.h>

typedef struct ArcNode
{
    int adjv;
    struct ArcNode *next;
    int w;
    int flexible;
}ArcNode;
typedef struct Vertex
{
    ArcNode *firstarc;
    int earliest, lastest;
}Vertex;

#define N  101
Vertex V[N] = {0};
int path[N], deadline;

int n, m;

int topoSort()
{
    int indeed[N] = {0}, stack[N] = {0}, top = -1;
    int i,j = 0;
    ArcNode *p;
    
    for(i = 1; i <= n; i++)
    {
        for(p = V[i].firstarc; p; p = p->next)
            indeed[p->adjv]++;
    }
    
    for(i = 1; i <= n; i++)
        if(indeed[i]==0) stack[++top] = i;
    
    while(top >= 0)
    {
        path[j++] = i = stack[top--];
        
        for(p = V[i].firstarc; p; p = p->next)
            if(--indeed[p->adjv] == 0)
                stack[++top] = p->adjv;
    }
    return j == n;
}

void earliestTime()
{
    int i, k;
    ArcNode *p;
    
    for(k = 0; k < n; k++)
    {
        for(i = path[k], p = V[i].firstarc; p; p = p->next)
            if(V[p->adjv].earliest < V[i].earliest + p->w)
                V[p->adjv].earliest = V[i].earliest + p->w;
        
        if(V[i].earliest > deadline) deadline = V[i].earliest;
    }
}

void lastestTime()
{
    int i, k;
    ArcNode *p;
    
    for(i = 1; i <= n; i++)
    {
        V[i].lastest = deadline;
    }
    
    for(k = n -1; k >= 0; k--)
    {
        for(i = path[k],p = V[i].firstarc; p!=NULL; p = p->next)
            if(V[p->adjv].lastest - p->w < V[i].lastest)
                V[i].lastest = V[p->adjv].lastest - p->w;
    }
}

void flexibleTime()
{
    int i;
    ArcNode *p;
    
    for(i = 1; i <= n; i++)
        for(p = V[i].firstarc; p!=NULL; p = p->next)
            p->flexible = V[p->adjv].lastest - V[i].earliest - p->w;
}

void criticalPath()
{
    int i;
    ArcNode *e;
    for(i = 1; i <= n; i++)
        for(e = V[i].firstarc; e!=NULL; e = e->next)
            if(e->flexible == 0)
                printf("%d->%d\n",i,e->adjv);
}

void slove()
{
    int k,i,j,w;
    ArcNode *e;
    
    scanf("%d %d", &n, &m);
    for(k = 0; k < m; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        e = (ArcNode*)malloc(sizeof(ArcNode));
        e->adjv = j,e->w = w , e->next = V[i].firstarc;
        V[i].firstarc = e;
    }
    
    if( topoSort() )
    {
        earliestTime();lastestTime();flexibleTime();
        
        printf("%d\n",deadline),criticalPath();
        
    }
    else printf("0\n");
    
    
}

int main()
{
    slove();
    return 0;
}