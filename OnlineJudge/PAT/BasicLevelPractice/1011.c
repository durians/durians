#include <stdio.h>

int main(int argc, char *argv[]) {
    long long a , b , c;
    int n, i;
    scanf("%d",&n);
    
    for(i = 1; i <= n; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
       // printf("%lld %lld",a+b,c);
        if(a + b > c)
            printf("Case #%d: true",i);
        else
            printf("Case #%d: false",i);
        if(i < n) printf("\n");    
    }
    

}