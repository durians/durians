#include <stdio.h>

//#1.a[n]keeping the all card status.
//   a[n], 0 = up, 1 = down  　　
//   H [i,j], operate the card.
//   Q [i,j], search from a[i,j], count the number of 0=up.
//O(N)
//Exceed time limit 1 ≤ n ≤ 10^6


//#2.just keeping the back-card range [i, j]
//typedef struct{
//  i, j;    
//}bcr[m] 
//
//   H [i,j],change of bcr[m] 

typedef struct _range
{
    int i,j;
    struct _range *next;
}Range;

typedef struct{
    struct _range *head;
}List;

void InitList(List *L)
{
    L->head = (struct _range *)malloc(sizeof(struct _range)); 
    L->head->next = NULL;
    L->head->i = 0, L->head->j = 0;
}

void FreeList(List *L)
{
    struct _range *p = L->head, *q;
    while(p)
    {
        q = p;
        p = p->next;
        free(q),q=NULL;
    }
}

void change_card_range(List L,int i, int j)
{
    int k = 0;
    struct _range *p = L.head, *q = p->next, *nrange;
    
    while(q)
    {
        //[ q->i, i, j, q->j] == > [bcr.i, i) (j, bcr.j]
        if(q->i < i && j < q->j)
        {
            nrange = (struct _range *)malloc(sizeof(struct _range));
            nrange->i = j + 1, nrange->j = q->j;
            nrange->next = q->next;
            q->next = nrange;
            q->j = i - 1;
            
            p = nrange, q = nrange->next;
        }
        else if(q->i == i && j == q->j)
        {
            p->next = q->next;
            free(q), q = p->next;
        }
        //[ i, q->i, q->j, j] == > [i, q->i) (q->j, j]
        else if(i < q->i && q->j < j)
        {
            //(q->j, j]
            nrange = (struct _range *)malloc(sizeof(struct _range));
            nrange->i = q->j + 1, nrange->j = j;
            nrange->next = q->next;
            q->next = nrange;
            
            //[i, q->i)
            q->i = i;
            q->j = q->i - 1;
            
            p = nrange, q = nrange->next;
        }
        else if(q->j == i)
        {
            q->j = j;
        }
        else if (q->i == j) {
            q->i = i;
        }
        else if (q->j < i || q->i > j) {
            nrange = (struct _range *)malloc(sizeof(struct _range));
            nrange->i = i, nrange->j = j;
            nrange->next = q->next;
            q->next = nrange;
            p = nrange, q = nrange->next;
        }
        
    }
   
}
int main(int argc, char *argv[]) 
{
    
}










