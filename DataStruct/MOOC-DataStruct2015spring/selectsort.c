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

void selectsort(int a[], int n)
{
    int i, j , min;
    
    for(i = 0; i < n-1; i++)
    {
        min = i;
        
        //select min
        for(j = i+1; j < n; j++)
        {
            if(compare(a[j],a[min]))
                min = j;
        }
        
        if(min!=i)
            swap(a[i],a[min]);
    }
}



#define N 100000
int main()
{
    int a[N], i,n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", a+i);
    
    selectsort(a,n);
    
    for(i = 0; i < n; i++)
        printf("%d%c",a[i],i==n-1?'\n':' ');
    
    return 0;
}