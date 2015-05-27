//
//  http://www.patest.cn/contests/mooc-ds2015spring/04-树5
//  Complete Binary Search Tree
//  http://mooc.study.163.com/learn/ZJU-1000033001#/learn/content?type=detail&id=1000113013&cid=1000116014

//  Created by durians on 15/5/23.
//
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N  (1001)


int cbt[N]; //Complete Binary Tree

int cbst[N]; //Complete Binary Search Tree

int GetLeftLength(int n)
{
    // n = 2^H - 1 + x
    int H = log(n+1)/log(2);
    
    int x = n - pow(2,H) + 1;
    if(x > pow(2,H-1)) x = pow(2,H-1);
    
    int L = pow(2,H-1) - 1 + x;
    
    return L;
}
void slove(int cbt_i, int cbt_j, int cbst_Root)
{
    int n = cbt_j - cbt_i + 1;
    
    if( 0 == n) return;
    
    int L = GetLeftLength(n);
    
    cbst[cbst_Root] = cbt[cbt_i + L];
    
    //L: [cbt_i, cbt_i + L - 1] root is cbst_Root*2
    //R: [cbt_i + L + 1, cbt_j] root is cbst_root*2 + 1
    
    slove(cbt_i, cbt_i + L - 1, cbst_Root*2);
    slove(cbt_i + L + 1, cbt_j, cbst_Root*2+1);
}

int cmp(const void *a, const void *b)
{
    return (int *)a - (int *)b;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++)
    {
        scanf("%d", cbt+i);
    }
    qsort(cbt+1,n,sizeof(int),cmp);
    slove(1,n,1);
    
    printf("%d",cbst[1]);
    for(i = 2; i <= n; i++)
    {
        printf(" %d", cbst[i]);
    }
    
    return 0;
}


















