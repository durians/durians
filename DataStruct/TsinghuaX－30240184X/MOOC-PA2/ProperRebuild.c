#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *lchild;
    struct _node *rchild;
}*Tree;

void properRebuild(Tree *pR,int dlr[], int i, int j, int lrd[], int k, int f)
{
    int m,n;
    
    Tree r;
    r = (struct _node*)malloc(sizeof(struct _node));
    r->data = dlr[i];//lrd[f]
    r->lchild = NULL, r->rchild = NULL;
    
    *pR = r;
    
    if(i == j && k == f)
        return;
    
    //lrd: L[k,m-1]  R[m, f-1]
    m = k;
    while(lrd[m++] != dlr[i+1]);//L
    
    //dlr: L[i+1,n] R[n+1, j]
    n = j;
    while(dlr[n--] != lrd[f-1]);//R
    
    properRebuild(&r->lchild,dlr,i+1,n,lrd,k,m-1);
    properRebuild(&r->rchild,dlr,n+1,j,lrd,m,f-1);
}

void visit(struct _node *r)
{
    printf("%d ", r->data);
}

void ldr(Tree r)
{
    if(r)
    {
        ldr(r->lchild);
        visit(r);
        ldr(r->rchild);
        
        free(r->rchild),r->rchild = NULL;
        free(r->lchild),r->lchild = NULL;
    }
    
}

int main(int argc, char *argv[])
{
    int n, i;
    int *lrd, *dlr;
    Tree r;
    
    scanf("%d", &n);
    
    dlr = (int *)malloc(sizeof(int)*n);
    lrd = (int *)malloc(sizeof(int)*n);
    
    for(i = 0; i < n; i++)
        scanf("%d",dlr+i);
    for(i = 0; i < n; i++)
        scanf("%d",lrd+i);
    
    properRebuild(&r,dlr,0,n-1,lrd,0,n-1);
    ldr(r);
    
    free(dlr),dlr=NULL;
    free(lrd),lrd=NULL;
    
    return 0;
}




