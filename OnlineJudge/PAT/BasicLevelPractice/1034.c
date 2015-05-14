#include<stdio.h>

int gcd(long long a, long long b)
{
    int c;
    while(a % b)
    {
        c = a;
        a = b;
        b = c % b;
    }
    return b;
}

void out(long long a, long long b)
{
    if(b == 0)
    {
        printf("Inf");
        return;
    }
    
    long long k = a / b;
    long long c = a % b;
    long long d = b;
    long long m = gcd(c,d);
    c = c / m;
    d = d / m;
    
    if(d < 0)
    {
        c = -c;
        d = -d;
    }
    
    if( k > 0)
    {
        printf("%lld", k);
        if( c!=0 ) printf(" %lld/%lld",c,d);
    }
    else if (k == 0) {
        if(c < 0) printf("(%lld/%lld)",c,d);
        else if(c == 0) printf("0");
        else printf("%lld/%lld",c,d);
    }
    else {
        printf("(%lld",k);
        if(c == 0) printf(")");
        else printf(" %lld/%lld)",-c,d);
    }
    
    
}

void operate(long long a1, long long b1, long long a2, long long b2, char op)
{
    double a, b;
    
    switch (op)
    {
        case '+':
            a = a1*b2 + a2*b1;
            b = b1*b2;
            break;
        case '-':
            a = a1*b2 - a2*b1;
            b = b1*b2;
            break;
        case '*':
            a = a1*a2;
            b = b1*b2;
            break;
        case '/':
            a = a1*b2;
            b = b1*a2;
            break;
        default:
            break;
    }
    out(a1,b1);printf(" %c ",op);out(a2,b2);printf(" = ");out(a,b);printf("\n");
}
int main()
{
    long long a1,b1,a2,b2;
    
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    
    operate(a1,b1,a2,b2,'+');
    operate(a1,b1,a2,b2,'-');
    operate(a1,b1,a2,b2,'*');
    operate(a1,b1,a2,b2,'/');
    
    return 0;
}