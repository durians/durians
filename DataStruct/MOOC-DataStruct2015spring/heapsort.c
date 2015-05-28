//
//  heapsort.c
//
//  Created by durians on 15/5/28.
//
/**************************************  
  堆排序算法  
    #1.create a[1~n] to heap
    #2.swap(a[1] a[n--])
    #3.ajust a[1~n] to heap

  用优先队列来描述123
    #1
    for(i = 1; i <= n; i++)
        push(&H,a[i]);
    #2#3
    for(i = n; i > 0; --i)
        a[i] = pop(&H);
  
 
 
#1.create a[1~n] to heap
   ＃方法1
    for(i = n/2; i > 0; --i)
        ajust(a,i,n)  
   #方法2
    for(i = 2; i <= n; i++)
        insert(a,i-1,a[i]); 
        
#2#3.ajust a[1~n] to heap
    i = 1;e = a[1];
    for(j = 2*i; j <= n; i = j,j *= 2)
    {
        //compare(e, a[2*i], a[2*i+1])
        // 1. a[j] = compare(a[2*i+1],a[2*i])
        // 2. compare(a[j], e)
 
        //1.
        if(j < n && compare(a[j+1], a[j]))
            j = j+1;
        //2.
        if(!compare(a[j],e)) break;
 
        a[i] = a[j];
    }
    a[i] = e;

  大堆－升序  小堆－降序
    MaxHeap  GT: greater than
    MinHeap  LT: less then
**************************************/

typedef int ElemType;



#define  LT(a,b)    ((a) < (b) ? 1 : 0)
#define  GT(a,b)    ((a) > (b) ? 1 : 0)
#define  compare(a,b)   GT(a,b)
//#define  compare(a,b)   LT(a,b)



void toheap(ElemType a[], int n);
void adjustheap(ElemType a[], int n);


//sort a[1~n]
void heapsort(ElemType a[], int n)
{
    ElemType e;

    //1.create a[1~n] to heap  O(nlogn)
    toheap(a,n);
    
    while(n > 0)
    {
        //2.swap(a[1] a[n--])
        e = a[n], a[n] = a[1],a[1] = e,n--;
        
        //3.ajust a[1~n] to heap
        adjustheap(a,n);
    }
}

void toheap(ElemType a[], int n)
{
    int i, j;
    ElemType e;

    for(i = 2; i <= n; i++)
    {
        e = a[i];
        
        //insert a[i] to heap a[1~i-1]
        for(j = i; j/2 >= 1 && compare(e,a[j/2]); j /= 2)
            a[j] = a[j/2];
        a[j] = e;
    }
}

void adjustheap(ElemType a[], int n)
{
    int i;
    ElemType e;
    
    i = 1, e = a[1];
    while( i <= n)
    {
        //a[i] = compare(e,a[2*i], a[2*i+1])
        if(2*i+1 <= n && compare(a[2*i+1],a[2*i])&&
           compare(a[2*i+1],e))
        {
            a[i] = a[2*i+1];
            i = 2*i+1;
        }
        
        else if(2*i <=n && compare(a[2*i],e))
        {
            a[i] = a[2*i];
            i = 2*i;
        }
        else
        {
            a[i] = e;
            break;
        }
    }
}


#include<stdio.h>
#define N 100001
int a[N];
int main()
{
    int n, i;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++)
    {
        scanf("%d",a+i);
    }
    
    heapsort(a,n);
    
    for(i = 1; i <= n; i++)
    {
        printf("%d%c",a[i],i==n?'\n':' ');
    }
}









