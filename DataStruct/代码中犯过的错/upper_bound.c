
//a[j] <= k 的最大j
//等价 k < a[i]的最小i的前驱
 
int upper_bound(int a[], int n, int k)
{
    //找 k < a[i]的最小i
    //1.若没有找到 j = n － 1, 所有a[j] <= k,
    //2.若正常找到 j = i - 1;
    //  若i = 0, k < a[0]：j = -1 ,即不存在a[j] <= k
    //  a[i - 1] <= k < a[i] : j = i - 1
    
    
    //找 k < a[i]的最小i
    //初始解范围[lo,hi]
    int lo = 0, hi = n -1, mid;
    
    while(lo < hi)  //结束时lo = hi
    {
        mid = (lo + hi) / 2;
        if(k < a[mid]) //[lo, mid]
        {
            hi = mid;  
        }
        else {  //[mid+1, hi]
            lo = mid + 1;
        }
    }
    return lo - 1;
}

int find_right(int *A, int n,int a)  
{  
  
    int lo = 0;  
    int hi = n-1;  
    while(1 < hi - lo)  
    {  
        int mi = (lo+hi) >> 1;  
        if(a < A[mi]) hi = mi;
        else lo = mi;
    }  
    return a >= A[hi]? hi : lo;  
} 



// 错误版本
// 容易犯的错误：
// 1、while(lo < hi)... lo = mid 会导致死循环
//   改正成while(lo + 1 < hi) ... lo = mid

//a[j] <= k 的最大j
int upper_bound_error(int a[], int n, int k)
{
    //初始解范围[lo,hi]
    int lo = 0, hi = n -1, mid;
    
    while(lo < hi)  //结束时lo = hi
    {
        mid = (lo + hi) / 2;
        if(a[mid] <= k) //[mid, hi]
        {
            lo = mid;   //死循环：lo = mid , hi = mid + 1, (lo + hi)/2 = mid , a[mid] <= k 
        }
        else {  //[lo, mid-1]
            hi = mid - 1;
        }
    }
    
    //查找失败  k 小于所有a[j]
    if(k < a[lo]) return -1;  
    
    return lo;
}

