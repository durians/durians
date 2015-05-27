//
//  04-树3.RootofAVLTree(25).c
//
//  Created by durians on 15/5/27.
//
//  http://www.patest.cn/contests/mooc-ds2015spring/04-树3
//  题源：2013年浙江大学计算机学院免试研究生上机考试真题，训练平衡树基本操作
//  题意：给一组数，建立AVL树，输出根结点
//
//
//  平衡二叉树定义:
//  1.是BST（左 < 根 < 右），且左右子树都是AVLTree
//  2.｜BF｜<=1，即左右子树高度差小于等于1
//
//  平衡二叉树主要操作：
//  1.插入(递归实现，关键在于破坏平衡后，平衡旋转操作)


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _vnode* AVLTree;
typedef struct _vnode
{
    int data;
    int height;
    AVLTree left,right;
    
}VNode;

#define   Max(a,b)  ((a) > (b) ? (a) : (b))
#define   BF(a,b)   (abs((a)-(b)))

int GetHeight(AVLTree T)
{
    return T ? T->height : -1;
}

AVLTree LLRote(AVLTree T)
{
    AVLTree A = T->left;
    
    T->left = A->right;
    A->right = T;
    
    T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    return A;
}

AVLTree LRRote(AVLTree T)
{
    AVLTree A = T->left;
    AVLTree B = A->right;
    
    //LR to LL
    A->right = B->left;
    B->left = A;
    T->left = B;
    
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    return LLRote(T);
}

AVLTree RRRote(AVLTree T)
{
    AVLTree A = T->right;
    
    T->right = A->left;
    A->left = T;
    
    T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    
    return A;
}

AVLTree RLRote(AVLTree T)
{
    AVLTree A = T->right;
    AVLTree B = A->left;
    
    //RL to RR
    A->left = B->right;
    T->right = B;
    B->right = A;
    
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    
    return RRRote(T);
}

AVLTree InsertAVLTree(AVLTree T, int e)
{
    if(!T)
    {
        T = (AVLTree)malloc(sizeof(VNode));
        T->data = e, T->height = 0, T->left = T->right = NULL;
        return T;
    }
    else if(e < T->data)
    {
        //插在T的左边
        T->left = InsertAVLTree(T->left, e);
        
        //T的平衡破坏
        if( 1 < BF(GetHeight(T->left),GetHeight(T->right)) )
        {
            if(e < T->left->data)
            {
                //LL
                T = LLRote(T);
            }
            else
            {
                //LR
                T = LRRote(T);
            }
        }
    }
    else if(T->data < e)
    {
        T->right = InsertAVLTree(T->right, e);
        if( 1 < BF(GetHeight(T->left),GetHeight(T->right)) )
        {
            if(T->right->data < e)
            {
                //RR
                T = RRRote(T);
            }
            else
            {
                //RL
                T = RLRote(T);
            }
        }
    }
    else
    {
        //e == T->data
        return T;
    }
    
    int Hl = GetHeight(T->left);
    int Hr = GetHeight(T->right);
    T->height = Max(Hl,Hr) + 1;
    
    return T;
}

AVLTree CreateAVLTree()
{
    int n,e;
    AVLTree T = NULL;
    
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &e);
        T = InsertAVLTree(T,e);
    }
    
    return T;
}

int main()
{
    printf("%d\n",CreateAVLTree()->data);
    return 0;
}








