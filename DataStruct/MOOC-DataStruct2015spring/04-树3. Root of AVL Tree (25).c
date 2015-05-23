#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    int data;
    struct BSTNode *lchild, *rchild;
    int height;
}BSTNode, *BSTree;

int GetHeight(BSTree T)
{
    if(T) return T->height;
    else return -1;
}

void LL_Rotate(BSTree *pT)
{
    BSTree A = *pT;
    BSTree B = A->lchild;
    
    A->lchild = B->rchild;
    B->rchild = A;
    
    A->height = GetHeight(A->lchild) < GetHeight(A->rchild) ? 
                GetHeight(A->rchild) +1: GetHeight(A->lchild) + 1;
    B->height = GetHeight(B->lchild) < GetHeight(B->rchild) ? 
                GetHeight(B->rchild) +1: GetHeight(B->lchild) + 1;
    *pT = B;
}

void LR_Rotate(BSTree *pT)
{
    BSTree A = *pT;
    BSTree B = A->lchild;
    BSTree C = B->rchild;
    B->rchild = C->lchild;

    A->lchild = C->rchild;
    C->lchild = B;
    C->rchild = A;
    A->height = GetHeight(A->lchild) < GetHeight(A->rchild) ? 
            GetHeight(A->rchild) +1: GetHeight(A->lchild) + 1;  
    B->height = GetHeight(B->lchild) < GetHeight(B->rchild) ? 
            GetHeight(B->rchild) +1: GetHeight(B->lchild) + 1;  
    C->height = GetHeight(C->lchild) < GetHeight(C->rchild) ? 
            GetHeight(C->rchild) +1: GetHeight(C->lchild) + 1;

    *pT = C;
}

void RR_Rotate(BSTree *pT)
{
    BSTree A = *pT;
    BSTree B = A->rchild;
    
    A->rchild = B->lchild;
    B->lchild = A;
  
A->height = GetHeight(A->lchild) < GetHeight(A->rchild) ? 
        GetHeight(A->rchild) +1: GetHeight(A->lchild) + 1;  
B->height = GetHeight(B->lchild) < GetHeight(B->rchild) ? 
        GetHeight(B->rchild) +1: GetHeight(B->lchild) + 1;  

//    A->height--;
    *pT = B;
    
}
void RL_Rotate(BSTree *pT)
{
    BSTree A = *pT;
    BSTree B = A->rchild;
    BSTree C = B->lchild;
    
    B->lchild = C->rchild;
    A->rchild = C->lchild;
  
    C->lchild = A;
    C->rchild = B;
    
    A->height = GetHeight(A->lchild) < GetHeight(A->rchild) ? 
            GetHeight(A->rchild) +1: GetHeight(A->lchild) + 1;  
    B->height = GetHeight(B->lchild) < GetHeight(B->rchild) ? 
            GetHeight(B->rchild) +1: GetHeight(B->lchild) + 1;  
    C->height = GetHeight(C->lchild) < GetHeight(C->rchild) ? 
            GetHeight(C->rchild) +1: GetHeight(C->lchild) + 1;

    *pT = C;
}
void InsertAVL(BSTree *pT, int data)
{
    BSTree T = *pT;
    
    if(!T)
    {
        T = (BSTree)malloc(sizeof(struct BSTNode));
        T->data = data,T->lchild = T->rchild = NULL,T->height = 0;
        *pT = T;
        return ;
    }
    else if(data < T->data)
    {
        InsertAVL(&(T->lchild), data);
        if(GetHeight(T->lchild) - GetHeight(T->rchild) == 2)
        {
            if(data < T->lchild->data)
            {
                //LL
                LL_Rotate(pT);
            }
            else
            {
                //LR
                LR_Rotate(pT);
            }
        }
    }
    else if(T->data < data)
    {
        InsertAVL(&(T->rchild), data);
        if(GetHeight(T->lchild) - GetHeight(T->rchild) == -2)
        {
            if(T->rchild->data < data)
            {
                  //RR
                RR_Rotate(pT);
            }else{
                RL_Rotate(pT);
            }
        }
    }
    else {
        /* data == T->data */
        return ;
    }
    
    T->height = GetHeight(T->lchild) < GetHeight(T->rchild) ?
    GetHeight(T->rchild) + 1 : GetHeight(T->lchild) + 1;
    
}

void CreateAVL(BSTree *pT)
{
    int n,d;
    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%d", &d);
        InsertAVL(pT, d);
    }
}

int main()
{
    BSTree T = NULL;
    CreateAVL(&T);
    printf("%d\n", T->data);
    return 0;
}








