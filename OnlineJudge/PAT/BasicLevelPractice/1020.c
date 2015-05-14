#include <stdio.h>
#include <stdlib.h>

typedef struct _mooncake
{
    double totalprice;
    double price;
    double goods;
}Mooncake;
Mooncake mooncake[1000];

int cmp(const void *a, const void *b)
{
    Mooncake *p, *q;
    p = (Mooncake *)a;
    q = (Mooncake *)b;
    
    return (q->price > p->price);
}
int main()
{
    int N,D;
    scanf("%d %d",&N,&D);
    int i;
    
    for(i = 0; i < N; i++)
    {
        scanf("%lf",&mooncake[i].goods);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%lf",&mooncake[i].totalprice);
        mooncake[i].price = mooncake[i].totalprice / mooncake[i].goods;
    }
    
    qsort(mooncake, N, sizeof(mooncake[0]), cmp);
    
    double total = 0;
    i = 0;
    while(D && i < N)
    {
        if(mooncake[i].goods < D)
        {
            total += mooncake[i].totalprice;
            D -= mooncake[i].goods;
        }
        else {
            total += D*mooncake[i].price;
            D = 0;
        }
        i++;
    }
    printf("%.2f",total);
    return 0;
}

/*
 int main(int argc, char *argv[])
 {
 int N, D, i;
 int k[1000],t[1000];
 double p[1000];
 
 scanf("%d %d",&N,&D);
 
 for(i = 0; i < N; i++)
 {
 scanf("%d",k+i);
 }
 for(i = 0; i < N; i++)
 {
 scanf("%d",t+i);
 p[i] = 1.0 * t[i] / k[i];
 }
 
 int type = 0;
 double total = 0, temp = 0;
 int df_price;
 while(D > 0)
 {
 type = 0;
 
 //find max price type
 for(i = 0; i < N; i++)
 {
 // p[i] > p [type]
 temp = (p[i] - p [type]) * 100000;
 df_price = (int )temp;
 if( df_price > 0 && k[i] > 0)
 {
 type = i;
 break;
 }
 }
 
 if(k[type] == 0) break;
 
 if( D >= k[type]){
 total += t[type];
 D = D - k[type];
 }
 else {
 total += D*p[type];
 k[type] -= D;
 D = 0;
 }
 
 }
 
 printf("%.2f",total);
 
 return 0;
 }
 */