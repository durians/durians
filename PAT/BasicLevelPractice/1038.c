#include <stdio.h>

int main(int argc, char *argv[]) {
    int N , s, d[101] = {0} , k, search , i;
    
    scanf("%d", &N);
    for( i = 0; i < N;i ++)
    {
        scanf("%d",&s);
        d[s]++;
    }
    scanf("%d", &k);
    while( k )
    {
        scanf("%d",&search);
        printf("%d%c",d[search], k == 1 ? '\n' : ' ');
        k--;
    }
    
}