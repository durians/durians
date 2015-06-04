
#include <stdio.h>
#include <string.h>

int N; //vertices
int E; //edges
int a[10][10] = {0};
int visitd[10] = {0};

void dfs(int i)
{
    int j;
    
    visitd[i] = 1, printf("%d ", i);
    for(j = 0; j < N; j++)
    {
        if( a[i][j] && !visitd[j])
            dfs(j);
    }
}

void bfs(int i)
{
    int q[10] = {0}, r = 0, f = 0, j;
    
    visitd[i] = 1,printf("%d ", i);
    
    q[r++] = i;
    while(r!=f)
    {
        i = q[f++];
        for(j = 0; j < N; j++)
        {
            if(a[i][j] && !visitd[j])
            {
                visitd[j] = 1,printf("%d ",j);
                q[r++] = j;
            }
        }
    }
    
}


int main(int argc, char *argv[])
{
    
    int i = 0, j = 0, k = 0;
    
    scanf("%d %d", &N, &E);
    for(k = 0; k < E; k++)
    {
        scanf("%d %d", &i,&j);
        a[i][j] = a[j][i] = 1;
    }

    
    //dfs
    for(i = 0; i < N; i++)
    {
        if(!visitd[i])
        {
            printf("{ "), dfs(i), printf("}\n");
        }
        
    }
    
    //bfs
    memset(visitd,0,sizeof(visitd));
    for(i = 0; i < N; i++)
    {
        if(!visitd[i])
        {
            printf("{ "), bfs(i), printf("}\n");
        }
    }
    
}