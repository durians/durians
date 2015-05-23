
/*函数名： int binSearch(s[], e, lo, hi)
*
*函数功能：在有序数组s[]区间[lo, hi)中查找元素e
*返回值：不大于e的最后一个元素(s[i]<=e的最大i, s[i]<=e<s[i+1])
*值约定：1 + binSearch(e)为e作为新元素的插入点
*    查找成功：返回e的索引
*    重复元素：返回最后一个e的索引,保持插入次序的稳定
*    查找失败：
*            e < v[lo],  返回 lo - 1
*            v[hi-1] < e 返回 hi - 1
*/

#include "upper_bound.h"

int binSearch(s[], e, lo, hi)
{
    return upper_bound(s,e,lo,hi);
}

/*
 
 */

