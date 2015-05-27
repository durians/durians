//
//  http://www.patest.cn/contests/mooc-ds2015spring/05-树8
//
//
//  Created by durians on 15/5/26.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vnode *HuffmanTree;
typedef struct _vnode
{
    int weight;
    char data;
    HuffmanTree left, right;
    int height;
}VNode;




//////////////////////////  MinHeap  ///////////////////////
typedef struct _minheap
{
    HuffmanTree *elements;
    int size;
    int capacity;
}MinHeap;

MinHeap CreateMinHeap(int n)
{
    MinHeap H;
    
    H.elements = (HuffmanTree *)malloc(sizeof(HuffmanTree)*n);
    H.size = 0;
    H.capacity = n;
    
    return H;
}

void DestoryMinHeap(MinHeap *H)
{
    if(H->elements) free(H->elements);
    H->elements = NULL, H->size = 0, H->capacity = 0;
}

HuffmanTree DeleteMinHeap(MinHeap *H)
{
    HuffmanTree e = H->elements[1], t = NULL;
    
    H->elements[1] = H->elements[H->size--];
    
    int i = 1;
    while(i < H->size)
    {
        // i, 2*i, 2*i+1
        
        if(2*i+1 <= H->size &&
           H->elements[2*i+1]->weight <= H->elements[2*i]->weight &&
           H->elements[2*i+1]->weight < H->elements[i]->weight)
        {
            t = H->elements[2*i+1];
            H->elements[2*i+1] = H->elements[i];
            H->elements[i]=t;
            
            i = 2*i + 1;
        }
        else if(2*i <= H->size && H->elements[2*i]->weight < H->elements[i]->weight)
        {
            t = H->elements[2*i];
            H->elements[2*i] = H->elements[i];
            H->elements[i] = t;
            i = 2*i;
        }
        else break;
    }
    
    return e;
}

void InsertMinHeap(MinHeap *H, HuffmanTree e)
{
    int i;
    for(i = ++H->size;
        i/2 >=1 && e->weight < H->elements[i/2]->weight;
        i = i/2)
    {
        H->elements[i] = H->elements[i/2];
    }
    
    H->elements[i] = e;
}



//////////////////  HuffmanTree  ///////////////////////

HuffmanTree Huffman(MinHeap *H)
{
    HuffmanTree T;
    
    while(H->size > 1)
    {
        T = (HuffmanTree)malloc(sizeof(struct _vnode));
        
        T->left = DeleteMinHeap(H);
        
        T->right = DeleteMinHeap(H);
        
        T->weight = T->left->weight + T->right->weight;
        
        T->height = 0;
        
        InsertMinHeap(H,T);
    }
    return DeleteMinHeap(H);
}

int GetHuffmanCost(HuffmanTree T)
{
    static int cost = 0;
    
    if(T)
    {
        if(T->left == NULL && T->right == NULL)
        {
            cost += T->height * T->weight;
        }
        
        if(T->left)
        {
            T->left->height = T->height + 1;
            GetHuffmanCost(T->left);
        }
        
        if(T->right)
        {
            T->right->height = T->height + 1;
            GetHuffmanCost(T->right);
        }
    }
    
    return cost;
}


int main()
{
    int i, n, m, cost, f[256] = {0};;
    HuffmanTree e, T;
    
    
    scanf("%d", &n),getchar();
    MinHeap H = CreateMinHeap(2*n);
    for(i = 0; i < n; i++)
    {
        e = (HuffmanTree)malloc(sizeof(struct _vnode));
        e->height = 0, e->left = e->right = NULL;
        scanf("%c %d", &e->data,&e->weight),getchar();
        
        f[e->data] = e->weight;
        
        InsertMinHeap(&H,e);
    }
    T = Huffman(&H), cost = GetHuffmanCost(T);
    DestoryMinHeap(&H);
    
    
    
    char ch, code[64][64] = {0};
    int cost2, flag;
    
    scanf("%d", &m),getchar();
    while(m--)
    {
        cost2 = 0, flag = 1;
        for(i = 0; i < n; i++)
        {
            scanf("%c",&ch),scanf("%s",code[i]),getchar();
            cost2 += f[ch] * strlen(code[i]);
        }
        
        if(cost2 != cost)
        {
            flag = 0;
            printf("No\n");
        }
        else
        {
            // sort
            for(i = 1; i < n; i++)
            {
                for(int j = 0; j < n - i; j++)
                {
                    if(strlen(code[j]) > strlen(code[j+1]))
                    {
                        char t[64];
                        strcpy(t, code[j]),strcpy(code[j], code[j+1]),strcpy(code[j+1], t);
                    }
                }
            }
            
            //check 前缀码
            for(i = 0; i < n && flag; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    char *s = code[j];
                    if(s == strstr(s,code[i]))
                    {
                        flag = 0;
                        printf("No\n");break;
                    }
                }
            }
            
            if(flag) printf("Yes\n");
            
        }
        
    }
    
    
    return 0;
}









