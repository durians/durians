//
//  07-排序2.c
//
//
//  Created by durians on 15/6/3.
//
//

#include <stdio.h>
#include <stdlib.h>
#define N 100
int c[N],a[N],n;

int equal(int a[], int c[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        if(a[i] != c[i])
            return 0;
    return 1;
}

int insertSort(int a[], int n)
{
    int i, j ,e;
    int f = 0;
    
    for(i = 1; i < n; i++)
    {
        e = a[i];
        for(j = i - 1; j >= 0 && e < a[j]; j--)
            a[j+1] = a[j];
        
        a[j+1] = e;
        
        if(f)
        {
            printf("Insertion Sort\n");
            for(f = 0; f < n; f++)
                printf("%d%c",a[f],f==n-1?'\n':' ');
            return 1;
        }
        
        if(equal(a,c,n))
        {
            f = 1;
        }
        
    }
    return 0;
}

void merge(int a[], int m, int n)
{
    int *b, i, j, k;
    
    b = (int *)malloc(sizeof(int)*n);
    
    i = 0, j = m, k = 0;
    
    while(i < m && j < n)
    {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    
    while(i < m) b[k++] = a[i++];
    while(j < n) b[k++] = a[j++];
    
    for(i = 0; i < n; i++)
        a[i] = b[i];
    
    free(b);
    
}
void mergeSort(int a[], int n)
{
    int i = 0, h, f = 0;
    
    for(h = 1; h < n; h *= 2)
    {
        for(i = 0; i + 2*h <= n; i += 2*h)
        {
            merge(a+i,h,2*h);
        }
        if(i + h < n)
        {
            merge(a+i,h,n-i);
        }
        
        if(f)
        {
            printf("Merge Sort\n");
            for(f = 0; f < n; f++)
                printf("%d%c",a[f],f==n-1?'\n':' ');
            return;
        }
        
        if(equal(a,c,n))
        {
            f = 1;
        }
    }
    
    
}

int main()
{
    int i,b[N];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
        scanf("%d",a+i), b[i] = a[i];
    for(i = 0; i < n; i++)
        scanf("%d",c+i);
    
    if(!insertSort(b,n))
    {
        mergeSort(a,n);
    }
    
    return 0;
}







