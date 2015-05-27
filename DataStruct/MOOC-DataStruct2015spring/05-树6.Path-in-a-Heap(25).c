//
//  http://www.patest.cn/contests/mooc-ds2015spring/05-树6
//  题意：给一组数，建最小堆，输出堆中从[i,1]的元素
//
//  Created by durians on 15/5/26.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _minheap
{
    int *Elements;
    int size;
    int capacity;
}*MinHeap;

MinHeap CreateMinHeap(int maxsize)
{
    MinHeap H = malloc(sizeof(struct _minheap));
    
    H->Elements = (int *)malloc(maxsize);
    H->capacity = maxsize, H->size = 0;
    H->Elements[0] = -0x7fffffff;  //哨兵
    
    return H;
}

void InsertMinHeap(MinHeap H, int e)
{
    int i = ++H->size;
    
    for(; e < H->Elements[i/2]; i = i/2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = e;
}

int DeleteMinHeap(MinHeap H)
{
    int min =H->Elements[1];
    
    int parent,child;
    int tmp = H->Elements[H->size--];
    for(parent = 1; (child = 2*parent) <= H->size; parent = child)
    {
        //child指向左右结点较小者
        if(child + 1 <= H->size &&
           H->Elements[child+1] < H->Elements[child])
        {
            child = child + 1;
        }
        
        //假设tmp为parent
        //child比tmp小，child当parent
        //否则，退出循环parent的位置为填tmp
        if(H->Elements[child] < tmp)
        {
            H->Elements[parent] = H->Elements[child];
        }
        else break;
    }
    H->Elements[parent] = tmp;
    
    return min;
}


int main()
{
    int i, n, m, e;
    scanf("%d %d", &n, &m);
    MinHeap H = CreateMinHeap(n+1);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &e);
        InsertMinHeap(H,e);
    }
    
    while(m--)
    {
        scanf("%d", &i);
        while(i>=1)
        {
            printf("%d%c",H->Elements[i],i==1?'\n':' ');
            i = i / 2;
        }
    }
    
    return 0;
}
















