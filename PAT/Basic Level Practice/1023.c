#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int i,n;
    int a[10] = {0};
    
    for(i = 0; i < 10; i++)
    {
        scanf("%d",&n);
        a[i] = n;
    }
    
    for(i = 1; i < 10; i++)
        if(a[i] != 0) break;
        
    printf("%d",i);
    a[i]--;
    
    for( i = 0; i < 10; i++)
    {
        while(a[i] != 0) 
        {
            printf("%d",i);
            a[i]--;
        }
    }
    
    
    return 0;
}