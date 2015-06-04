//
//  bbst.c
//
//  平衡二叉搜索树（BBST，Balanced Binary Search Tree 又称AVL树）
//
//    1.数据
//
//    2.结构（关系）
//        #1 是BSTree：左子树 < 根 < 右子树
//        #2 是|BF|<=1的树：BF为左右子树高度差
//           树高定义：h(空树)＝－1，h(叶子)＝0，h(根)＝h(子树)＋1
//        #3 左右子树都是BBSTree
//
//    3.操作
//      插入(递归实现，关键在于破坏平衡后，平衡旋转操作)
//
//  Created by durians on 15/5/29.
//
//
#include<stdlib.h>

typedef int ElemType;
typedef struct BSTNode
{
    ElemType data;
    int height;
    struct BSTNode *left, *right;
}BSTNode,*BSTree;

#define Height(T)   ( (T) ? T->height : -1 )
#define BF(T)       abs(Height(T->left) - Height(T->right))
#define Max(a,b)    ( (a) > (b) ? (a) : (b) )

BSTree LLRote(BSTree T)
{
    BSTree A ;
    
    A = T->left,T->left = A->right,A->right = T;
    T->height = Max(Height(T->left), Height(T->right)) + 1;
    A->height = Max(Height(A->left), Height(A->right)) + 1;
    
    return A;
}

BSTree LRRote(BSTree T)
{
    BSTree A = T->left;
    BSTree B = A->right;
    
    //LR to LL
    A->right = B->left , B->left = A , T->left = B;
    
    A->height = Max(Height(A->left), Height(A->right)) + 1;
    B->height = Max(Height(B->left), Height(B->right)) + 1;
    
    return LLRote(T);
}

BSTree RRRote(BSTree T)
{
    BSTree A = T->right;
    
    T->right = A->left , A->left = T;
    
    T->height = Max(Height(T->left), Height(T->right)) + 1;
    A->height = Max(Height(A->left), Height(A->right)) + 1;
    
    return A;
}

BSTree RLRote(BSTree T)
{
    BSTree A = T->right , B = A->left;
    
    //RL to RR
    A->left = B->right , T->right = B ,B->right = A;
    
    B->height = Max(Height(B->left), Height(B->right)) + 1;
    A->height = Max(Height(A->left), Height(A->right)) + 1;
    
    return RRRote(T);
}


BSTree insert(BSTree T, ElemType e)
{
    if(!T)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = e,T->left = T->right = NULL;
    }
    else if(e < T->data)
    {
        T->left = insert(T->left,e);
        if(1 < BF(T)) T = (e < T->left->data) ? LLRote(T) : LRRote(T);
    }
    else if(T->data < e)
    {
        T->right = insert(T->right,e);
        if(1 < BF(T))  T = (T->right->data < e) ? RRRote(T) : RLRote(T);
    }
    T->height = Max(Height(T->left),Height(T->right)) + 1;
    
    return T;
}








