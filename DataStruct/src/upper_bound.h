//
//  upper_bound.h
//  
//
//  Created by durians on 15/5/16.
//
//

#ifndef _upper_bound_h
#define _upper_bound_h

//函数功能：在[lo, hi)中查找满足s[i]<=e的最大i
int upper_bound(int s[], int e, int lo, int hi)
{
    //搜索范围[lo,hi)
    while(lo < hi)
    {
        int mi = (lo + hi)>>1;
        // e < s[mi] 在左边：[lo, mi)
        // s[mi]<=e  在右边：(mi, hi)
        // 搜索范围调整为[lo, mi) 或 (mi, hi)
        (e < s[mi]) ? hi = mi: lo = mi+1;
        
        // Q1: why lo = mid ? 避免死循环
        // Q2: missing mi : [lo,mi) (mi, hi) ?
    }
    // lo = hi , s[lo-1] <= e < s[lo]
    return lo - 1;
}

#endif
