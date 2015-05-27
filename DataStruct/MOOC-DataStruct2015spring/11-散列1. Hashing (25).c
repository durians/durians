//
//  11-散列2.c
//  http://www.patest.cn/contests/mooc-ds2015spring/11-散列1
//
//  H(key) = key % TSize
//                 TSize >= MSize and TSize is a prime.
//
//  collisions: key = key + i^2 % TSize
//                          i = 1, 2, 3, ... ,TSize
//
//  Created by durians on 15/5/26.
//
//
#include<stdio.h>
#include<math.h>

int H[100004], TSize = 100004;

int isPrime(int n)
{
    
    if(n == 1) return 0;
    
    if(n > 2 && n % 2 == 0) return 0;
    
    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int hashCode(int key)
{
    int h = key % TSize, i = 0;
    
    while(H[h] && ++i < TSize)
    {
        h = (key + i*i) % TSize;
    }
    
    if(!H[h])
    {
        H[h] = key;
        return h;
    }
    
    return -1;
}

void setTSize(int MSize)
{
    TSize = MSize;
    while(!isPrime(TSize))TSize++;
}

int main()
{
    int MSize, N, h, key;
    
    scanf("%d %d", &MSize, &N),setTSize(MSize);
    
    while(N--)
    {
        scanf("%d", &key);
        if( (h = hashCode(key) ) >= 0)
            printf("%d%c",h,N?' ':'\n');
        else
            printf("-%c",N?' ':'\n');
    }
}








