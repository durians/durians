#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned long long sum = 0;
    unsigned int A = 0, Da = 0, B = 0, Db = 0, Pa = 0,Pb = 0;
    
    scanf("%d %d %d %d",&A,&Da,&B,&Db);
    
    while(A && Da)
    {
        if( (A % 10) == Da ) Pa = Pa*10 + Da;
        A = A / 10;
    }
    while(B && Db)
    {
        if( (B % 10) == Db ) Pb = Pb*10 + Db;
        B = B / 10;
    }
    sum = Pa + Pb;
    printf("%llu",sum);
}