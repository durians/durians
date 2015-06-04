//
//  selectsort.c
//  
//
//  Created by durians on 15/6/3.
//
//
#define LT(a,b)         ((a) < (b) ? (1) : (0))
#define compare(a,b)     LT(a,b)
#define swap(a,b)        do{a = a+b;b=a-b;a=a-b;}while(0)

#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int m, int n)
{
    int *b = (int *)malloc(sizeof(int)*n);
    int i = 0, j = m, k = 0;
    
    while(i < m && j < n)
    {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    
    while(i < m)b[k++] = a[i++];
    while(j < n)b[k++] = a[j++];
    
    for(i = 0; i < n; i++)
        a[i] = b[i];
    
    free(b);
}

void mergesort(int a[], int n)
{
    if(n <= 1) return;
    
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    merge(a,n/2,n);
}

void mergeSort(int a[], int n)
{
    int i, h;
    
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
    }
    
    
}


#define N 100000
int main()
{
    int a[N], i,n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", a+i);
    
    mergeSort(a,n);
    
    for(i = 0; i < n; i++)
        printf("%d%c",a[i],i==n-1?'\n':' ');
    
    return 0;
}