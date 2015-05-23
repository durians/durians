//
//  lower_bound.h
//  
//
//  Created by durians on 15/5/16.
//
//

#ifndef _lower_bound_h
#define _lower_bound_h

//函数功能：在[lo,hi)中查找满足e<=s[i]的最小i
int lower_bound(int s[], int e, int lo, int hi)
{
    //初始搜索范围[lo, hi)
    while(lo < hi)
    {
        int mi = (lo + hi)>>1;
        
        (e <= s[mi]) ? hi = mi: lo = mi + 1;
    }
    
    return lo;
}

#endif
