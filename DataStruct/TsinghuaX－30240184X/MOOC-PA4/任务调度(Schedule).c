//http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=409
/*
Input

3 3
1 hello
2 world
10 test
Output

hello
hello
world
*/
#include<stdio.h>
#include<string.h>

typedef struct
{
    unsigned int priority;
    char name[9];
}Task;
typedef Task ElemType;
int compare(ElemType a, ElemType b)
{
    if(a.priority == b.priority)
    {
        return (strcmp(a.name,b.name) < 0) ;
    }
    return a.priority < b.priority;
}
typedef struct Heap
{
    ElemType *elem;
    int size;
    int capacity;
}Heap;


#include<stdlib.h>
Heap* createHeap(int maxsize)
{
    Heap* H = (Heap *)malloc(sizeof(Heap));
    H->elem = (ElemType *)malloc(sizeof(ElemType)*(maxsize+1));
    H->capacity = maxsize+1;
    H->size = 0;

    return H;
}

void destoryHeap(Heap *H)
{
    free(H->elem);
    H->elem = NULL, H->size = 0, H->capacity = 0;
    free(H);
}


void pushHeap(Heap *H, ElemType e)
{
    int i = ++H->size;
    
    //插入与上滤
    for(; i/2 >= 1 && compare(e,H->elem[i/2]); i /= 2)
        H->elem[i] = H->elem[i/2];
    
    H->elem[i] = e;
}


ElemType popHeap(Heap *H)
{
    ElemType e = H->elem[1];
    ElemType tmp = H->elem[H->size--];
    
    int i = 1, j;
    
    //删除与下滤
    //H[i] = compare(tmp, H[2*i], H[2*i +1])
    for(j = 2*i; j <= H->size; i = j, j *= 2)
    {
        if(j < H->size && compare(H->elem[j+1],H->elem[j]) )
            j = j + 1;
            
        if(!compare(H->elem[j], tmp))
            break;
        
        H->elem[i] = H->elem[j];
    }
    H->elem[i] = tmp;
    
    return e;
}


int main()
{
    int n,m;
    Task e;
    
#ifdef _OJ_
    const int SZ = 1<<20;
    char inbuf[SZ];
    char outbuf[SZ];
    setvbuf(stdin,inbuf,_IOFBF,SZ);
    setvbuf(stdout,outbuf,_IOFBF,SZ);
#endif
    
    scanf("%d %d", &n, &m);
    
    Heap *h = createHeap(n);
    while(n--)
    {
        scanf("%d %s", &e.priority, e.name);
        pushHeap(h,e);
    }
    while(m-- && h->size > 0)
    {
        e = popHeap(h);
        printf("%s\n",e.name);
        if(e.priority < 0x80000000)
        {
            e.priority  *= 2;
            pushHeap(h,e);
        }
    }   
    destoryHeap(h);    
    
    return 0;
}



