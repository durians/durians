//
//  http://www.patest.cn/contests/mooc-ds2015spring/05-树6
//  题意：给一组数，建最小堆，输出堆中从[i,1]的元素
//
//  Created by durians on 15/5/26.
//
//

#include <stdio.h>

//小堆
#include "heap.c"

int main()
{
    int i, n, m, e;
    scanf("%d %d", &n, &m);
    
    Heap *H = createHeap(n+1);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &e);
        pushHeap(H,e);
    }
    
    while(m--)
    {
        scanf("%d", &i);
        while(i>=1)
        {
            printf("%d%c",H->elem[i],i==1?'\n':' ');
            i = i / 2;
        }
    }
    
    return 0;
}
















