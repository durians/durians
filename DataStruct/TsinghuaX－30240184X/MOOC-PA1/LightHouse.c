/*

2015-5-15
http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=402
题意：s[]中有多少对 a < b (a.x < b.x && a.y < b.y )

Solution

#1暴力  必然会Exceed time limit	
for(i = 0; i < n; i++)
{   
    for(j = 0; j < n; j++)
    {
        if(s[i] < s[j]) c++;
    }
}

#2

*/

#include <stdio.h>
#include <stdlib.h>

#define     N  (4000000)
//1 ≤ n ≤ 4×10^6

typedef struct _point
{
    int x, y;
}Point;

Point s[N];
int y[N];

int cmp(const void *p, const void *q)
{
    Point *a = (Point *)p;
    Point *b = (Point *)q;
    
    return a->x - b->x;
}


long long invBetween(int y[], int lo, int mi, int hi)
{
    int i, j, k;
    int *temp = (int *)malloc(sizeof(int)*(hi-lo));
    long long inv = 0;
    
    i = lo, j = mi, k = 0;
    while(i < mi && j < hi)
    {
        if(y[i] < y[j])
        {
            temp[k++] = y[i++];
        }
        else {
            temp[k++] = y[j++];
            inv += mi - i;
        }
    }
    
    while(i < mi) temp[k++] = y[i++];
    while(j < hi) temp[k++] = y[j++];
    
    for(i = 0; i < k; i++)
    {
        y[lo+i] = temp[i];
    }
    
    return inv;
}


long long invInside(int y[], int lo, int hi)
{
    long long inv = 0;
    int i;
    
    if( hi - lo < 2) return 0;
    
    inv += invInside(y,lo, (hi + lo)/2);
    inv += invInside(y,(hi+lo)/2, hi);
    inv += invBetween(y,lo,(hi+lo)/2,hi);
    
    return inv;
}


int main()
{
    
    const int SZ = 1<<20;
    char inbuf[SZ];
    char outbuf[SZ];
    setvbuf(stdin,inbuf,_IOFBF,SZ);
    setvbuf(stdout,outbuf,_IOFBF,SZ);
        
    int n, i;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&s[i].x, &s[i].y);
    }
    
    qsort(s,n,sizeof(s[0]),cmp);
    
    for (i = 0; i < n; i++) {
        y[i] = s[i].y;
    }
    
    long long inv = invInside(y,0,n);
    long long slove = (long long)n * (n - 1) / 2 - inv;
    
    printf("%lld\n", slove);
    
    
    return 0;
}