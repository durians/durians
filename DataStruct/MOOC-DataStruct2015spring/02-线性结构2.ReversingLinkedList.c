//http://www.patest.cn/contests/mooc-ds2015spring
//http://www.patest.cn/contests/mooc-ds2015spring/02-线性结构2


#include<stdio.h>
typedef struct _node
{
    int data;
    int next;
}Node, List[100002]; // L[100000] is the list head

#define HEAD (100001)

List L;
int N;//N which is the total number of nodes
//1→2→3→4→5→6
//if K = 3, then you must output 3→2→1→6→5→4;
//if K = 4, you must output 4→3→2→1→5→6.
int K;//K which is the length of the sublist to be reversed

void output()
{
    int p = L[HEAD].next;
    
    //if(p==-1) return;
    
    while(L[p].next != -1)
    {
        printf("%05d %d %05d\n",p,L[p].data,L[p].next);
        p = L[p].next;
    }
    printf("%05d %d %d\n",p,L[p].data,L[p].next);
    
}

int Reverse(int head)
{
    int cnt, i;
    int new, old,temp;

    new = L[head].next,old = L[new].next;
    cnt = 1;
    while(cnt++ < K)
    {
        temp = L[old].next;
        L[old].next = new,new = old,old = temp;
    }
    L[L[head].next].next = old;
    
    return new;
}

void ReverseCircul()
{
    int i;
    int head;
    
    L[HEAD].next = head = Reverse(HEAD);
    
    for(i = K; i + K <= N; i += K)
    {
        head = Reverse(head);
    }    
}

void CreateList()
{
    int Address, Data, Next;
    int i;
    
    scanf("%d %d %d", &(L[HEAD].next), &N, &K);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d", &Address,&Data,&Next);
        L[Address].data = Data;
        L[Address].next = Next;
    }
}

int main()
{
    CreateList();
    ReverseCircul();
    output();
    return 0;
}



