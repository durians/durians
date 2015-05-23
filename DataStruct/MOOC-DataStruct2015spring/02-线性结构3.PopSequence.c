//http://www.patest.cn/contests/mooc-ds2015spring/02-线性结构3

/*
//题意：判断一个序列是否可由栈操作得到
 
 M (the maximum capacity of the stack)
 N (the length of push sequence)
 K (the number of pop sequences to be checked).
 
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/

#include <stdio.h>

int checkSequence(int order[], int n ,int stack_size)
{
    int stack[1000] = {0};
    int top = -1, num = 0, i = 0;
    
    while( i < n && top < stack_size-1)
    {
        stack[++top] = ++num;
        
        while( top >= 0 && i < n && stack[top] == order[i])
        {
            top--;
            i++;
        }    
    }
    return (i == n) ? 1 : 0;
}

int main(int argc, char *argv[]) 
{
    int M, N, K;
    int order[1000]; 
    scanf("%d %d %d",&M, &N, &K);
    
    int i, j;
    for( i = 0; i < K; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d",order + j);
        }
        if( checkSequence(order, N, M) )
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");    
        }
    }
}