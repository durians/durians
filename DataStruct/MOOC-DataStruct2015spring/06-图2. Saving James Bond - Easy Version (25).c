#include<stdio.h>
#include<math.h>

#define MAXN    101
typedef struct Point{
    int x,y;
}Point;
Point p[MAXN]={0};
int visited[MAXN] = {0};
int n, d;

int jump(int i, int j)
{
    if(i == 0)
        return d + 7.5 >= sqrt(pow(p[i].x-p[j].x,2) + pow(p[i].y-p[j].y,2));
    return pow(d,2) >= pow(p[i].x-p[j].x,2) + pow(p[i].y-p[j].y,2);
}

int isSafe(int i)
{
    if(i == 0)
        return ( (d -7.5 <= -50) ||
                 (d +7.5 >= 50 ) ||
                 (d -7.5 <= -50) ||
                 (d +7.5 >= 50 ) );
    else            
        return ( (p[i].x - d <= -50) ||
                 (p[i].x + d >= 50 ) ||
                 (p[i].y - d <= -50) ||
                 (p[i].y + d >= 50 ) );
}
int dfs(int i)
{
    int j;
    
    visited[i] = 1;
    if(isSafe(i)) return 1;
    
    for(j = 1; j <= n; j++)
    {
        if(!visited[j] && jump(i,j))
            if(dfs(j)) return 1;
    }
    
    return 0;
}

int saving007()
{
    int i;
    scanf("%d %d", &n, &d);
    p[0].x = 0, p[0].y = 0;
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    
    if(isSafe(0))return 1;
    
    for(i = 1; i <= n; i++)
    {
        if(!visited[i] && jump(0,i))
        {
            if(dfs(i)) return 1;
        }
    }
    
    return 0;
}


int main()
{
    saving007() ? printf("Yes\n"): printf("No\n");
    return 0;
}