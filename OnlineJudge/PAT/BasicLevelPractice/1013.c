#include <stdio.h>
#include <math.h>

int p[10001] = {0};

void getprime(int M)
{
    int num, i, j, isprime;
    
    p[1] = 2;
    i = 2;
    for(num = 3; i <= M; num += 2)
    {
        isprime = 1;
        for(j = 1; (j < i) && (p[j]<= sqrt(num)); j++)
        {
            //num not prime
            if( (num % p[j]) == 0 )
            {
                isprime = 0;
                break;
            }
        }
        
        if(isprime)
        {
            p[i] = num;
            i++;
        }
    }
    
    
}
int main()
{
    int i, N, M;
    scanf("%d %d",&N,&M);
    
    getprime(M);
    for(i = N; i <= M; i++)
    {
        printf("%d%c",p[i],( ((i-N+1)%10) && i < M )? ' ' : '\n' );
    }
}


