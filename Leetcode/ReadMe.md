
[leetcode][0]
[0]:https://leetcode.com

[sample][1]
[1]:https://github.com/haoel/leetcode

[book][2]
[2]:https://github.com/durians/durians/blob/master/Leetcode/CleanCodeHandbook_v1.0.1.pdf


**TwoSum**
*hash*解决
>1.考虑到正负数，哈希的key为：(unsigned int)(value)%HASH_MAX_SIZE
>2.用开源的C语言hash库，uthash.h（这个在leetcode中默认包含）
>两种方法均[AC](TwoSum.c)


**LargestNumber**
*排序*解决
>1.把输入转成字符串排序最简单
>2.也可以去数字的高位依次排序，处理起来较麻烦，但，居然也让我AC了，笑
>两种方法均AC，但是方法2明显有BUG，看来测试数据还不够强
