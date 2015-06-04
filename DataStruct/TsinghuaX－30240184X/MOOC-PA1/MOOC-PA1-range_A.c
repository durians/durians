/************************************************
    Created Time: 四  5/14 21:24:36 2015
    Author: durianpy@icloud.com 
    File Name: range.c
************************************************/


/*
 http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=400
 
 Descriptioin
 Let S be a set of n integral points on the x-axis. For each given interval [a, b], you are asked to count the points lying inside.
 
 Input
 The first line contains two integers: n (size of S) and m (the number of queries).
 
 The second line enumerates all the n points in S.
 
 Each of the following m lines consists of two integers a and b and defines an query interval [a, b].
 
 Output
 The number of points in S lying inside each of the m query intervals.
 
 Example
 Input
 
 5 2
 1 3 7 9 11
 4 6
 7 12
 Output
 
 0
 3
 Restrictions
 0 <= n, m <= 5 * 10^5
 
 For each query interval [a, b], it is guaranteed that a <= b.
 
 Points in S are distinct from each other.
 
 Coordinates of each point as well as the query interval boundaries a and b are non-negative integers not greater than 10^7.
 
 Time: 2 sec
 
 Memory: 256 MB
 */


#include<stdio.h>
#include<stdlib.h>

//返回k <= a[i] 的最小i , 没有时返回－1
int lower_bound(int a[], int n, int k)
{
    //初始解的范围[lo,hi]
    int lo = 0, hi = n - 1, mid;
    while(lo < hi)  
    {
        mid = (lo + hi) / 2;
        
        if(k <= a[mid])  //解在[lo, mid] 内
        {
            hi = mid;
        }
        else {  //解在[mid+1, hi] 内
            lo = mid + 1;
        }
    }
    //结束时 lo == hi
    if( a[lo] < k) return n;  // 表示没有k <= a[i], k 大于所有a[i]
    
    return lo;
}

int upper_bound(int a[], int n, int k)
{
    //找 k < a[i]的最小i
    //1.若没有找到，i = n － 1, 即 k > 所有a[i]: j = i = n - 1 满足a[j] <= k 的最大j
    //2.若正常找到 j = i - 1;
    //  若i = 0, 即 k < 所有a[i]：没有 a[j] <= k 返回 j = i - 1 = 0 - 1 = -1
    //  即 k < a[i]的最小i: j = i - 1 就是 a[j] <= k 的最大j  （ a[j]<=k<a[i] ）
    
    
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
    
    //查找失败 
    if(k >= a[lo]) return n-1;  
    
    return lo - 1;
}



void merge(int a[], int len1, int b[], int len2)
{
    int i = 0, j = 0, k = 0;
    int *c = malloc(sizeof(int)*(len1 + len2));

    while(i < len1 && j < len2)
    {
        if(a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }

    while(i < len1)c[k++] = a[i++];
    while(j < len2)c[k++] = b[j++];
    
    for(i = 0; i < k; i++)
    {
        a[i] = c[i];
    }

    free(c);
    c = NULL;
}

void mergeSort(int a[], int n)
{
    if(n <= 1) return ;

    mergeSort(a, n/2);
    mergeSort(a + n/2, n - n/2);
    
    merge(a, n/2, a + n/2, n - n/2);

}

int find_left(int *A, int n, int a)  
{  
    int lo = 0;  
    int hi = n-1;  
    while(1 < hi - lo)  
    {  
        int mi = (lo+hi) >> 1;  
        if(a < A[mi]) hi = mi;
        else lo = mi;
    }  
    return a <= A[lo]? lo : hi;  
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

int solution(int s[],int n, int a, int b)
{
    if ((a > s[n-1] && b > s[n-1]) || (a < s[0] && b < s[0]))
    {
        return 0;
    }  
    return find_right(s,n,b) - find_left(s,n,a) + 1;
}


int solution2(int s[],int n, int a, int b)
{
    int c = 0, i ;

    /*
     * 查找超时，需要改进。
     * 二分查找，可从O(N)，降到O(logN)，需要排序
     */
    for(i = 0; i < n; i++)
    {
        if(s[i] >= a && s[i] <= b)
            c++;
    }
    return c;
}


int main()
{
    int n, m, a, b, c, i;
    scanf("%d %d", &n, &m);

    int s[500000] = {0};
    for(i = 0; i < n; i++)
        scanf("%d", s+i);

    mergeSort(s,n);

    while(m--)
    {
     scanf("%d %d",&a,&b);
        c = solution(s, n, a, b);
        printf("%d\n",c);
    }
    return 0;
}
