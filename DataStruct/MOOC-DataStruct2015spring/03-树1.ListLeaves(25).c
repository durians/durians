//http://www.patest.cn/contests/mooc-ds2015spring/03-树1
//题源：训练建树和遍历基本功
//题意：层次遍历输出叶子(list all the leaves in the order of top down, and left to right.)
//方法：所给数据parent、child关系明确，不需要动态确定关系，静态链表存储更优。
//     队列实现层次遍历：
//      1.Q.enque(root)
//      2.while(!Q.empty)
//          r = Q.deque()
//          visited(r)
//          Q.enque(r.lchild)
//          Q.enque(r.rchild)
//
//tips: C语言getchar()或scanf(%c)时回车处理让代码很丑陋
//      这里可以用gets(str)接收一行输入，str[0]、str[2]分别是左右子树

/*
 Sample Input:
 8
 1 -
 - -
 0 -
 2 7
 - -
 - -
 5 -
 4 6
 Sample Output:
 4 1 5
 
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define N (10)
typedef struct BiTNode
{
    int parent,lchild,rchild;
}BiTNode,BiTree[N];

void LevelTraversal(BiTree T)
{
    int Q[N];
    int r = 0, f = 0, e;
    
    Q[r++] = GetRoot(T);
    
    while(r != f)
    {
        e = Q[f++];
        
        if(0 <= T[e].lchild)
            Q[r++] = T[e].lchild;
        if(0 <= T[e].rchild)
            Q[r++] = T[e].rchild;
        //is leaf
        if(T[e].lchild < 0 && T[e].rchild < 0)
            printf("%d%c",e,r!=f?' ':'\n');
    }
    
}

void CreateBiTree(BiTree T)
{
    int n;
    
    //note: n <= 10
    scanf("%d", &n),getchar();
    
    for(int i = 0; i < n; i++)
    {
        char str[4] = {0};
        gets(str);
        
        if(isdigit(str[0]))
        {
            T[i].lchild = str[0] - '0';
            T[str[0]-'0'].parent = i;
        }
        else{
            T[i].lchild = -1;
        }
        if(isdigit(str[2]))
        {
            T[i].rchild = str[2] - '0';
            T[str[2]-'0'].parent = i;
        }
        else{
            T[i].rchild = -1;
        }
    }
    
}

int GetRoot(BiTree T)
{
    int root = 0;
    while(T[root].parent > 0)
        root = T[root].parent;
    
    return root;
}

int main()
{
    BiTree T = {0};
    CreateBiTree(T);
    LevelTraversal(T);
    return 0;
}















