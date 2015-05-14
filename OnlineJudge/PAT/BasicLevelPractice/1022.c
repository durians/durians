#include <stdio.h>

int main(int argc, char *argv[]) {
    int a , b , c, d , flag = 0;
    int t[32] = {0};
    scanf("%d %d %d",&a,&b, &d);
    c = a + b;
    
    if(c == 0) 
    {
        printf("0");
        return 0;
    }
    
    if( c < 0)
    {
        flag = 1;
        c = -c;
    }    
    
    int i = 31;
    while( c )
    {
        t[i] = c % d;
        c = c / d;
        i--;
    }
    if(flag) printf("-");
    while(++i < 32)
    {
        printf("%d",t[i]);
    }
    
}