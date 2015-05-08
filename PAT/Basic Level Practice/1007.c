#include <stdio.h>
#include <math.h>

int isprime(int num)
{
    int i;
    for( i = 3; i <= sqrt(num) + 1; i += 2)
    {
        if( num % i == 0) return 0;
    }
    
    return 1;
    
}
int main(int argc, char *argv[]) 
{
    
    int N;
    int pre = 3 , i , count = 0;
    
    scanf("%d", &N);
    
    for( i = 5; i <= N; i += 2)
    {
        if(isprime(i) )
         {
            if( (i - pre) == 2)
                count++;
            pre = i;
         }   
    }
    printf("%d\n",count);
}