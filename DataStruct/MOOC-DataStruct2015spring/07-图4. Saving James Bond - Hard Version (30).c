#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAXN    101
typedef struct Point{
    int x,y;
}Point;
Point p[MAXN]={0};

int dist[MAXN], path[MAXN]={0};

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

int bfs()
{
    int v = 0, w;
    int q[MAXN], r = 0, f = 0;
    dist[0] = 0;q[r++] = 0;
    
    while(r!=f)
    {
        v = q[f++];
        
        for(w = 1; w <= n; w++)
        {
            if(dist[w]==-1 && jump(v,w))
            {
                dist[w] = dist[v] + 1;
                path[w] = v;
                q[r++] = w;
                if(isSafe(w))
                {
                    return w;
                }
             }
        }
    }
    
    return 0;
}

int cmp(const void *p, const void *q)
{
    Point *a = (Point *)p;
    Point *b = (Point *)q;
    
    return pow(b->x,2)+pow(b->y,2) < pow(a->x,2) + pow(a->y,2);
}
int saving007()
{
    int i, j,rpath[MAXN];
    
    scanf("%d %d", &n, &d);
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
        dist[i] = -1;
    }
    
    qsort(p+1,n,sizeof(p[0]),cmp);
    
    if(isSafe(0))
    {
        printf("1\n");
        return 1;
    }
    //bfs
    i = bfs();
    if(i)
    {
        j = 1;
        while(i)
        {
            rpath[j++] = i;
            i = path[i];
        }
        printf("%d\n",j);
        while(--j)
        {
            printf("%d %d\n",p[rpath[j]].x,p[rpath[j]].y);
        }
    }
    else {
        printf("0\n");
    }
    
    
    return 0;
}


int main()
{
    saving007();

    return 0;
}