//
//  11-散列3. Hashing - Hard Version (30)
//  http://www.patest.cn/contests/mooc-ds2015spring/11-散列3
//
//  Created by durians on 15/5/25.
//
//

/*
 根据给出的hash表，求表的原始输入顺序
 H(x) = x%N ，linear probing to solve collisions
 
 Sample Input:
 11
 33 1 13 12 34 38 27 22 32 -1 21
 
 Sample Output:
 1 13 12 21 33 34 38 27 22 32
 
 拓扑排序
 
 如果 H(v[i])!= i
 则，[H(v[i]), i)都是v[i]的前驱
 用图来表达前驱后继，拓扑排序（多个取最小的）
 */


#include <stdio.h>
#define N  1000
int n;
int a[N],arcs[N][N],indeed[N];

void insert(int s[],int key, int n)
{
    int i;
    
    for(i = n-1; i >= 0 && a[key] < a[s[i]]; i--)
        s[i+1] = s[i];
    
    s[i+1] = key;
}
int del(int s[],int n)
{
    int i,e;
    
    e = s[0],n--;
    
    for(i = 0; i < n; i++)
        s[i] = s[i+1];
    
    return e;
}
void topoSort()
{
    int s[N],top = 0, i,v;
    
    for(i = 0; i < n; i++)
        if(indeed[i] == 0)
            insert(s,i,top++);
    
    while(top > 0)
    {
        v = del(s,top--);
        
        for(i = 0; i < n; i++)
            if(arcs[v][i] && --indeed[i] == 0)
                insert(s,i,top++);
        if(a[v] >= 0)
            printf("%d%c",a[v],top==0?'\n':' ');
    }
    
}

void slove()
{
    int i,h;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", a+i);
        
        if(a[i] < 0) continue;
        
        h = a[i] % n;
        
        while(h != i)
        {
            arcs[h][i] = 1;
            h = (h + 1)%n;
            indeed[i]++;
        }
    }
    
    topoSort();
}

int main()
{
    slove();
    return 0;
}