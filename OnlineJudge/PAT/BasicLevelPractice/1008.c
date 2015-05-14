#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int N, M;
    scanf("%d %d",&N, &M);
    
    int i, a[100], b[100];
    for(i = 0; i < N; i++)
        scanf("%d",a+i);
        
    int j;
    for(i = 0; i < N; i++)
    {
        j = (i + M) % N;
        b[j] = a[i];
    }
    
    printf("%d",b[0]);
    for( i = 1; i < N; i++)
        printf(" %d",b[i]);    
}