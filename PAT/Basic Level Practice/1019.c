#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*p, const void *q)
{
    return ( *(int *)p - *(int *)q);
}
int cmp2(const void*p, const void *q)
{
    return ( *(int *)q - *(int *)p);
}

int nodecrease(int num)
{
    //6677
    int n[4] = {0};
    n[3] = num % 10;
    n[2] = (num/10) % 10;
    n[1] = (num/100)%10;    
    n[0] = (num/1000)%10;
    
    qsort(n,4,sizeof(int),cmp1);
    
    num = n[0]*1000 + n[1]*100 + n[2]*10 + n[3];
    
    return num;
}
int noincrease(int num)
{
    //7766
    int n[4] = {0};
    n[3] = num % 10;
    n[2] = (num/10) % 10;
    n[1] = (num/100)%10;    
    n[0] = (num/1000)%10;
    
    qsort(n,4,sizeof(int),cmp2);
    
    num = n[0]*1000 + n[1]*100 + n[2]*10 + n[3];
     
    return num;
}
int main(int argc, char *argv[]) {
    int num , n1, n2;
    scanf("%d", &num);

    while(1)
    {
        n1 = noincrease(num);
        n2 = nodecrease(num);
        num = n1 - n2;
        printf("%04d - %04d = %04d\n",n1,n2,num);
        if( num == 6174 || num == 0) return 0;
    }
    
    return 0;
}