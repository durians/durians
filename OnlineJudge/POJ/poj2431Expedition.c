#include <stdio.h>

//大堆
#include "heap.c"

#define N  (10000)
typedef struct
{
    int distance;
    int fuel;
}FuelStation;
FuelStation A[N];


int cmp(const void *a, const void *b)
{
    FuelStation *p = (FuelStation*)a;
    FuelStation *q = (FuelStation*)b;
    
    return q->distance - p->distance;
}
void slove()
{
    int n, L, P, i, stops = 0;
    Heap *fuels;
    
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&A[i].distance, &A[i].fuel);
    }
    scanf("%d %d", &L, &P);
    
    
    fuels = createHeap(n);
    qsort(A,n,sizeof(A[0]),cmp);
    
    i = 0;
    
    //燃料不够时
    while(P < L)
    {
        //1.耗尽燃料
        L = L - P, P = 0;
        
        //2.保存经过的加油站
        while(i < n && A[i].distance >= L)
        {
            pushHeap(fuels,A[i++].fuel);
        }
        
        //3.选最大的加油站加油：计数加油的次数
        if(fuels->size > 0)
            P = popHeap(fuels), stops++;
        else
            break;
    }
    
    if(L <= P)printf("%d\n",stops);
    else printf("-1\n");
    
    destoryHeap(fuels);
}

int main()
{
    slove();
    return 0;
}

/*
 http://poj.org/problem?id=2431
 
 while 燃料不够时
 耗尽燃料
 保存经过的加油站
 选最大的加油站加油: 计数加油的次数
 
 Sample Input
 
 4
 4 4
 5 2
 11 5
 15 10
 25 10
 
 Sample Output
 
 2
 
 */




