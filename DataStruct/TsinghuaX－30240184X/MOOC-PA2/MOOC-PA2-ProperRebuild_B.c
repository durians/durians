#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    int data;
}*BinTree;

void Create(BinTree *t, int preOrder[], int postOrder[], int n)
{
    struct _node *root;
    int i = 0;
    
    if(n <= 0) return;
    
    //preOrder:  DL......R...... L[1,i+1) R[i+1,n)
    //postOrder: ......L......RD L[0,i)   R[i,n-1)
    root = (struct _node*)malloc(sizeof(struct _node));
    root->data = preOrder[0], root->left = NULL, root->right = NULL;
    *t = root;
    if(n == 1) return ;
    
    while(preOrder[1]!=postOrder[i++]);
    
    Create(&(root->left), preOrder+1,   postOrder,i);
    Create(&(root->right),preOrder+i+1, postOrder+i,n-i-1);
}

#ifndef _OJ_
void createBinTree(BinTree *t)
{
    int n, i;
    scanf("%d", &n);
    
    int *preOrder =  (int *)malloc(sizeof(int)*n);
    int *postOrder = (int *)malloc(sizeof(int)*n);
    
    for(i = 0; i < n; i++)
        scanf("%d", preOrder+i);
    for(i = 0; i < n; i++)
        scanf("%d",postOrder+i);
    
    Create(t,preOrder,postOrder,n);
    
}
#else
char ioinbuf[1<<20];
char iooutbuf[1<<20];
void createBinTree(BinTree *t)
{
    setvbuf(stdin, ioinbuf, _IOFBF, 1 << 20);
    setvbuf(stdout, iooutbuf, _IOFBF, 1 << 20);
    
    int n, i;
    scanf("%d", &n);
    
    int *preOrder =  (int *)malloc(sizeof(int)*n);
    int *postOrder = (int *)malloc(sizeof(int)*n);
    
    for(i = 0; i < n; i++)
        scanf("%d", preOrder+i);
    for(i = 0; i < n; i++)
        scanf("%d",postOrder+i);
    
    Create(t,preOrder,postOrder,n);
    
}
#endif // _OJ_


void orderTraversal(BinTree t)
{
    if(t)
    {
        orderTraversal(t->left);
        printf("%d ",t->data);
        orderTraversal(t->right);
    }
}
int main(int argc, char *argv[]) {
    
    BinTree t;
    
    createBinTree(&t);
    orderTraversal(t);
    
    return 0;
}







