
//
//
//  Created by durians on 15/5/27.
//
//堆实现优先队列
//
//  数据类型：
//  结构(关系)：
//      顺序存储的完全二叉树
//          小堆  k[i] <= k[2*i]，k[i] <= k[2*i+1]，i = 1,2,...,n/2
//          大堆  k[i] >= k[2*i]，k[i] >= k[2*i+1]，i = 1,2,...,n/2
//  操作：
//    pushHeap(Heap *H, ElemType e)
//    ElemType popHeap(Heap *H)
//




//数据类型
typedef int ElemType;

//结构（关系）：顺序存储（动态分配数组）+ 完全二叉树
typedef struct SqList
{
    ElemType *elem;
    int size;
    int capacity;
}Heap;

//操作：
int compare(ElemType a, ElemType b)
{
#define GT(a,b)    (a) > (b) ? 1 : 0
#define LT(a,b)    (a) < (b) ? 1 : 0
//小堆 LT(less then)

    return LT(a,b);
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











