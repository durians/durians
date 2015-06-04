#include <stdio.h>

#define LT(a,b)         ((a) < (b) ? (1) : (0))
#define compare(a,b)     LT(a,b)
#define swap(a,b)        do{a = a+b;b=a-b;a=a-b;}while(0)


//有序    移动次数：0＋        比较次数：n-1
//逆序    移动次数：O(N^2)    比较次数：O(N^2)
void bubbleSort(int a[], int n)
{
    int i, j, e, flag = 1;
    
    for(i = 1; flag && i < n; i++)
    {
        flag = 0;
        for(j = 0; j < n-i; j++)
        {
            if( compare(a[j+1],a[j]) )
            {//swap
                swap(a[j+1],a[j]);
                flag = 1;
            }
        }
    }
}

