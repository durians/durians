/*
 http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=400
 
描述
祖玛是一款曾经风靡全球的游戏，其玩法是：在一条轨道上初始排列着若干个彩色珠子，其中任意三个相邻的珠子不会完全同色。此后，你可以发射珠子到轨道上并加入原有序列中。一旦有三个或更多同色的珠子变成相邻，它们就会立即消失。这类消除现象可能会连锁式发生，其间你将暂时不能发射珠子。

开发商最近准备为玩家写一个游戏过程的回放工具。他们已经在游戏内完成了过程记录的功能，而回放功能的实现则委托你来完成。

游戏过程的记录中，首先是轨道上初始的珠子序列，然后是玩家接下来所做的一系列操作。你的任务是，在各次操作之后及时计算出新的珠子序列。

输入
第一行是一个由大写字母'A'~'Z'组成的字符串，表示轨道上初始的珠子序列，不同的字母表示不同的颜色。

第二行是一个数字n，表示整个回放过程共有n次操作。

接下来的n行依次对应于各次操作。每次操作由一个数字k和一个大写字母Σ描述，以空格分隔。其中，Σ为新珠子的颜色。若插入前共有m颗珠子，则k ∈ [0, m]表示新珠子嵌入之后（尚未发生消除之前）在轨道上的位序。

输出
输出共n行，依次给出各次操作（及可能随即发生的消除现象）之后轨道上的珠子序列。

如果轨道上已没有珠子，则以“-”表示。


Example
Input

ACCBA
5
1 B
0 A
2 B
4 C
0 A
Output

ABCCBA
AABCCBA
AABBCCBA
-
A
Restrictions
0 <= n <= 10^4

0 <= length of the initial sequence <= 10^4

Time: 2 sec

Memory: 256 MB


*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    char data;
    struct _node *next;
    struct _node *pre;
}LNode;

typedef struct _list
{
    LNode *head;
}List;

void InitList(List *pL, char *str)
{
    LNode *node, *p;
    int i;
    
    p = pL->head = (LNode *)malloc(sizeof(LNode));
    p->data = 0, p->next = NULL, p->pre = NULL;
    
    for(i = 0; i < strlen(str); i++)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = str[i];
        node->next = NULL;
        node->pre = p;
        
        p->next = node;
        p = node;    
    }
}


void ListTraverse(List L)
{
    LNode *p = L.head->next;
    
    if(!p) printf("-");
    
    while(p)
    {
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
}

void ListCheck(LNode *p)
{
    LNode *r, *q, *temp,*tempdel;
    int n = 1;
    
    while(1)
    {
        n = 1;
        r = p->next, q = p->pre;
        
        //next cout
        while(r && r->data == p->data)
        {
            n++;
            r = r->next;
        }   
        
        //pre count
        while(q && q->data == p->data)
        {
            n++;
            q = q->pre;
        }
        
        if(n >= 3)
        {
            temp = q->next;
            while(temp != r)
            {
                tempdel = temp;
                temp = temp->next;
                free(tempdel);
            }    
            
            q->next = r;
            if(r) r->pre = q;
            
            p = q;
            
        }
        else {
            return ;
        }
    }
}
void ListInsert(List L, int index, char e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = e, p->next = NULL, p->pre = NULL;
    
    int i = -1;
    LNode *q = L.head;
    
    //finde index-1
    while(q && i < index - 1)
    {
        q = q->next;
        i++;
    }
    
    //insert p
    if(q->next)  q->next->pre = p;
    p->next = q->next;
    p->pre = q;
    q->next = p;

    ListCheck(p);

}
int main(int argc, char *argv[]) 
{
    char initial[10001] = {0};
    int n, i;
    char ch;
    List L;
 
#ifdef _OJ_
    const int SZ = 1<<20;
    char inbuf[SZ];
    char outbuf[SZ];
    setvbuf(stdin,inbuf,_IOFBF,SZ);
    setvbuf(stdout,outbuf,_IOFBF,SZ);
#endif   

    scanf("%s", initial);
    
    InitList(&L, initial);
    
    scanf("%d", &n);
    while( n-- )
    {
        scanf("%d %c", &i, &ch);
        ListInsert(L, i, ch);
        ListTraverse(L);    
    }
    
    return 0;
}
















