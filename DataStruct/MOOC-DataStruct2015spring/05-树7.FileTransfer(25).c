//
//  05-树7.FileTransfer(25).c
//  http://www.patest.cn/contests/mooc-ds2015spring/05-树7
//  题源：关于并查集，2005、2007年浙江大学计算机学院免试研究生上机考试题
//  题意：
//      I 3 2 合并3、2到同一集合；
//      C 3 2 查询3、2是否在同一集合；
//      检查是不是所有元素都在同一集合
//
//  Created by durians on 15/5/27.
//
//

/*
 Sample Input 1:
 5
 C 3 2
 I 3 2
 C 1 5
 I 4 5
 I 2 4
 C 3 5
 S
 Sample Output 1:
 no
 no
 yes
 There are 2 components.
 Sample Input 2:
 5
 C 3 2
 I 3 2
 C 1 5
 I 4 5
 I 2 4
 C 3 5
 I 1 3
 C 1 5
 S
 Sample Output 2:
 no
 no
 yes
 yes
 The network is connected.
 */

#include <stdio.h>

typedef struct Set
{
    int data;
    
    //parent
    //  > 0     代表父亲
    //  = 0     代表空集
    //  < 0     代表根结点，具体负值代表根结点集合元素个数
    int parent;
}Set;

#define N   (10000)

Set s[N];

int findSet(Set s[],int n, int e)
{
    int i = e;
    /*
     for(i = 1; i <= n; i++)
     {
     if(s[i].data == e && s[i].parent != 0 )
     break;
     }
     */
    if(i <= n)
    {
        while( s[i].parent > 0 )
            i = s[i].parent;
        
        return i;
    }
    
    return -1;
}

void unionSet(Set s[], int n, int x1, int x2)
{
    int i = findSet(s, n, x1);
    
    int j = findSet(s, n, x2);
    
    if(i != j)
    {
        //si > sj
        if(s[i].parent < s[j].parent)
        {
            s[i].parent += s[j].parent;
            s[j].parent = i;
        }
        else
        {
            s[j].parent += s[i].parent;
            s[i].parent = j;
        }
    }
}


void slove()
{
    int n, c1, c2, i;
    
    scanf("%d", &n),getchar();
    for(i = 1; i <= n; i++)
    {
        s[i].parent = -1;
        s[i].data = i;
    }
    
    while(1)
    {
        char op = 0;
        while(op != 'S' && op != 'I' && op != 'C')
            op = getchar();
        
        if(op == 'S')
        {
            int count = 0;
            for(i = 1; i <= n; i++)
            {
                if(s[i].parent < 0)
                {
                    count++;
                }
            }
            
            if(count > 1)
            {
                printf("There are %d components.\n",count);
            }
            else{
                printf("The network is connected.\n");
            }
            return;
        }
        
        scanf("%d %d", &c1, &c2);
        
        if(op == 'I')
        {
            unionSet(s,n,c1,c2);
        }
        else//if(op == 'C')
        {
            if( findSet(s,n,c1) == findSet(s,n,c2) )
                printf("yes\n");
            else
                printf("no\n");
        }
    }
}

int main()
{
    slove();
    
    return 0;
}


