#include<stdio.h>

#include "heap.c"

void slove()
{
    int n, e,e1,e2;
    long long cost;
    //priority_queue< int, vector<int>, greater<int> >que;
    Heap *H;
    scanf("%d", &n);
    H= createHeap(n);
    
    while(n--)
    {
        scanf("%d",&e);
        //que.push(e);
        pushHeap(H,e);
    }
    cost = 0;
    //while(que.size() > 1)
    while(H->size > 1)
    {
//        e1 = que.top(),que.pop();
//        e2 = que.top(),que.pop();
        e1 = popHeap(H);
        e2 = popHeap(H);
        
        cost += e1 + e2;
        //que.push(e1+e2);
        pushHeap(H,e1+e2);
    }
    printf("%lld\n", cost);
    destoryHeap(H);
}

int main()
{
    slove();
    return 0;
}






