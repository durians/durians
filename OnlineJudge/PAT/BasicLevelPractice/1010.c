#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int a, e, zero;
    
    scanf("%d %d", &a,&e);
    if( e == 0 || a == 0)
    {
        zero = 1;
    }
    else
    {
        zero = 0;
        printf("%d %d", a*e,(e-1));
    }
    
    
    while (scanf("%d %d", &a,&e)!=EOF) 
    {
        if( !zero && (e!=0 && a!=0))
        {
            printf(" %d %d", a*e,(e-1));
        }
        else if(zero && (e!=0 && a!= 0))
        {
            zero = 0;
            printf("%d %d", a*e,(e-1));
        }
    }
    if(zero) printf("0 0");
}