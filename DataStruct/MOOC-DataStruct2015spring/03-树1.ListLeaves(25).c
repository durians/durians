//http://www.patest.cn/contests/mooc-ds2015spring/03-树1
/*

//
//list all the leaves in the order of top down, and left to right.

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

//静态链表存储
//层次遍历
//1.init  enque root
//2. while(!queue)
//     deque r, visited r
//     r->lchild enque, r->rchild enque
//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _node
{
    int lchild;
    int rchild;
    int parent;
}Node;

typedef struct _tree
{
    //静态链表 存储树
    struct _node *node;//node[10];
    int n;
    int leafs;
}Tree;


void CreateTree(Tree *t)
{
    int n, i;
    char lc, rc;
    
    scanf("%d", &n),getchar();
    
    //init Tree
    t->node = (struct _node *)malloc(n*sizeof(struct _node));
    t->n = n,t->leafs = 0;
    for(i = 0; i < n; i++)
    {
        t->node[i].parent = -1;
        t->node[i].lchild = -1;
        t->node[i].rchild = -1;
    }
    
    //create Tree
    for(i = 0; i < n; i++)
    {
        scanf("%c %c", &lc, &rc),getchar();
        if(isdigit(lc))
        {
            t->node[i].lchild = lc - '0';
            t->node[lc-'0'].parent = i;
        }
        
        if(isdigit(rc))
        {
            t->node[i].rchild = rc - '0';
            t->node[rc-'0'].parent = i;
        }
        
        if(lc == '-' && rc == '-')
        {
            t->leafs++;
        }
    }
}

int getParent(Tree t)
{
    int i = 0;
    while( t.node[i].parent >= 0)
        i = t.node[i].parent;
    
    return i;
}

void traversal(Tree t)
{
    int q[10] = {0}, r = 0, f = 0;
    int i, c = t.leafs;
    
    
    //EnQueue
    q[r] = getParent(t), r = (r + 1) % 10;
    
    while(r != f)
    {
        //DeQueue
        i = q[f], f = (f + 1) % 10;

        //is a leaf
        if(t.node[i].lchild < 0 && t.node[i].rchild < 0)
        {
            printf("%d%c", i, --c > 0 ? ' ': '\n');
        }
        else 
        {
            //lchild EnQueue
            if(t.node[i].lchild >= 0) q[r] = t.node[i].lchild, r = (r + 1) % 10;
             //lchild EnQueue
            if(t.node[i].rchild >= 0) q[r] = t.node[i].rchild, r = (r + 1) % 10;
        }
    }
}


int main()
{
    Tree t;
    
    CreateTree(&t);
    traversal(t);
    
    return 0;
}