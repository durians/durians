

//查找k <= a[i] 的最小i
//1。查找成功：则返回最小i
//2。查找失败：即k>a[i],返回n即k的插入点
int lower_bound(int a[], int n, int k)
{
    //初始解的范围[lo,hi]
    int lo = 0, hi = n - 1, mid;
    while(lo < hi)  
    {
        mid = (lo + hi) / 2;
        
        if(k <= a[mid])  //解在[lo, mid] 内
        {
            hi = mid; //死循环风险？没有：hi = mid, (lo + hi) / 2 < mid ,也就是mid必然会减
        }
        else {  //解在[mid+1, hi] 内
            lo = mid + 1;
        }
    }

    return (k <= a[lo]) ? lo : n; 
}



