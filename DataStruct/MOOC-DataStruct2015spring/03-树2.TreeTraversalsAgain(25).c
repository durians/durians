#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    int data;
}*BinTree;

void Create(BinTree *t, int preOrder[],int inOrder[], int n)
{
    struct _node *root;
    int i = 0;
    
    if( n <= 0) return;
    
    //root is :  preOrder[0] = inOrder[i]
    //inOrder :  L[0 , i) R[i+1,n)
    //preOrder:  L[1,i+1) R[i+1,n)    
    while(inOrder[i]!=preOrder[0])
        i++;

    // root
    root = (struct _node *)malloc(sizeof(struct _node));
    root->data = preOrder[0],root->left = NULL, root->right = NULL;
    *t = root;
    
    // root->left
    Create(&(root->left), preOrder+1, inOrder,i);
    
    // root->right
    Create(&(root->right),preOrder+i+1, inOrder+i+1, n-i-1);
    
}

void CreateBinTree(BinTree *t)
{
    int n, i = 0, j = 0, k = 0;
    int stack[30], top = -1;
    int preOrder[30], inOrder[30];
    char op[5] = {0};
    
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
    
    Create(t, preOrder, inOrder, n);
    
}

void postOrderTraversal(BinTree t)
{
    if(t)
    {
        postOrderTraversal(t->left);
        postOrderTraversal(t->right);
        
        printf("%d ", t->data);
        
        free(t), t = NULL;
    }
}

int main()
{
    BinTree t;
    
    CreateBinTree(&t);
    if(t)
    {
        postOrderTraversal(t->left);
        postOrderTraversal(t->right);
        printf("%d",t->data);
    }
    
    return 0;
}







