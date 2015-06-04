//
//  insertsort.c
//  
//
//  Created by durians on 15/6/3.
//
//


//有序    移动次数：0＋        比较次数：n-1
//逆序    移动次数：O(N^2)    比较次数：O(N^2)
void insertSort(int a[], int n)
{
    int i, j, e;
    
    for(i = 1; i < n; i += 1)
    {
        e = a[i];
        
        //find insert pos
        for(j = i - 1; j >= 0 && compare(e,a[j]); j -= 1)
            a[j+1] = a[j];
        
        a[j+1] = e;
    }
}

void binaryInsertSort(int a[], int n)
{
    int i, j, lo, hi, mid, e;
    
    for(i = 1; i < n; i++)
    {
        e = a[i];
        
        lo = 0, hi = i-1;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(compare(e,a[mid])) hi = mid - 1;
            else lo = mid + 1;
        }
        
        for(j = i - 1; j >= hi+1; j--)
            a[j+1] = a[j];
            
        a[hi+1] = e;    
    }
}

void shellSort(int a[], int n)
{
    int i,j,e,dk = n / 2;
    
    for(dk = n/2; dk; dk /=2)
    {
        for(i = dk; i < n; i += dk)
        {
            e = a[i];
            
            //find insert pos
            for(j = i - dk; j >= 0 && compare(e,a[j]); j -= dk)
                a[j+dk] = a[j];
            
            a[j+dk] = e;
        }
    }
}








