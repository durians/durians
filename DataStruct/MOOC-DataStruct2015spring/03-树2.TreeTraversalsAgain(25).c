// http://www.patest.cn/contests/mooc-ds2015spring/03-树2
//  题源：2014年秋季PAT甲级考试真题
//  题意：给出树中序遍历栈操作过程（非递归），求树的后续遍历
//
//  方法#1：中序遍历，Push序列为先序序列，Pop序列为中序序列;
//        依据先序、中序序列重新构建树,再后续遍历。
//      同类题：先序、后序求真二叉树的中序遍历
//      http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=405
//      注意：先序、后序不能确定一颗二叉树，所以不能用#2直接得到,要用#1重新构建二叉树再遍历
//
//  方法#2: 同#1，只是不用重新构建树，可以直接通过先序、中序得到后序
//        slovePostOrder(int preOrder[],int inOrder[], int n, int postOrder[])
//
//

/*
 Sample Input:
 6
 Push 1
 Push 2
 Push 3
 Pop
 Pop
 Push 4
 Pop
 Pop
 Push 5
 Push 6
 Pop
 Pop
 Sample Output:
 3 4 2 6 5 1
 */


#include <stdio.h>
#include <string.h>


void slovePostOrder(int preOrder[],int inOrder[], int n, int postOrder[])
{
    if(n <= 0) return;
    
    //  先序遍历：DL......R......
    //  中序遍历：...L...D...R...
    //  后序遍历：......L......RD

    int i = 0;
    while(inOrder[i]!=preOrder[0])
        i++;

    //root: preOrder[0] = inOrder[i] = postOrder[n-1]
    //L: pre[1,i+1) in[0,i)   post[0,i)
    //R: pre[i+1,n) in[i+1,n) post[i,n-1)
    
    //root
    postOrder[n-1] = preOrder[0];
    
    //L
    slovePostOrder(preOrder+1, inOrder, i, postOrder);
    
    //R
    slovePostOrder(preOrder+i+1, inOrder+i+1, n-i-1, postOrder+i);
}

int main()
{
    int n, i = 0, j = 0, k = 0;
    int stack[30], top = -1;
    int preOrder[30], inOrder[30];
    char op[5] = {0};
    
    //Sample Input
    scanf("%d", &n);
    for(i = 0; i < 2*n; i++)
    {
        scanf("%s", op);
        
        if(0 == strcmp("Push",op))
        {
            scanf("%d",preOrder+j);
            stack[++top] = preOrder[j++];
        }
        else // Pop
        {
            inOrder[k++] = stack[top--];
        }
    }
    
    //slove
    int postOrder[30];
    slovePostOrder(preOrder, inOrder, n, postOrder);
    
    //Sample Output
    for(i = 0; i < n; i++)
    {
        printf("%d%c",postOrder[i],i<n-1?' ':'\n');
    }
    
    return 0;
}







