//
//  04-树3.RootofAVLTree(25).c
//
//  Created by durians on 15/5/27.
//
//  http://www.patest.cn/contests/mooc-ds2015spring/04-树3
//  题源：2013年浙江大学计算机学院免试研究生上机考试真题，训练平衡树基本操作
//  题意：给一组数，建立AVL树，输出根结点
//

#include "bbst.c"

#include <stdio.h>
BSTree createAVLTree()
{
    int n,e;
    BSTree T = NULL;
    
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &e);
        T = insert(T,e);
    }
    
    return T;
}

int main()
{
    printf("%d\n",createAVLTree()->data);
    return 0;
}








