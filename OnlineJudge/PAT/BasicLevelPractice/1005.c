#include <stdio.h>
#include <stdlib.h>


int cmp(const void *p, const void *q)
{
    return (*(int *)p < *(int *)q);
}
int main(int argc, char *argv[]) {
    
    int K;
    
    scanf("%d",&K);
    
    int i , d[100] , key[151] = {0};
    for( i = 0; i < K; i++)
    {
        scanf("%d",d+i);
    }
    qsort(d,K,sizeof(int),cmp);
   
    for( i = 0; i <= 150; i++)
    {
        key[i] = 1;
    }
    
    int n;
    for( i = 0; i < K; i++)
    {
        n = d[i];    

        if(key[n] == 0) continue;
        
        if( n % 2) n = (3*n + 1) / 2;
        else  n = n / 2;
            
        while( n != 1 )
        {
            if( n <= 100)
                key[n] = 0;
            if( n % 2) n = (3*n + 1) / 2;
            else  n = n / 2;
        }
    }
    
    int count = 0;
    for( i = 0; i < K; i++)
    {
        if(key[d[i]]) count++;
    }
    
   
    
    for(i = 0; count > 0 && i < K; i++)
    {
        if(key[d[i]])
        {
            printf("%d", d[i]);
            count--;
            if(count > 0) printf(" ");
        }
    }
    return 0;
}