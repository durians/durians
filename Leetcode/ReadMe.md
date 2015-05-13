
**[TwoSum][000]**

*hash*
>1.数组直接哈希[AC](TwoSum.c)，考虑到负数，映射为：(unsigned int)(key)%HASH_MAX_SIZE
>
>2.用开源的C语言hash库[AC](TwoSum-test.c)，[uthash.h][hash]（这个在leetcode中默认包含）
>

[000]:https://oj.leetcode.com/problems/two-sum/
[hash]:https://github.com/durians/uthash



**[LargestNumber][179]**

*排序*

>1.把输入整数，转成字符串，排序[AC](largestnumber.c)
>
>2.也可以依次取数字的高位进行比较排序，处理起来较麻烦，但，明显有BUG的代码居然也让我[AC](largestnumber-test.c)了，看来测试数据还不够强...


[179]:https://leetcode.com/problems/largest-number/


##About leetcode

[leetcode][0]
[0]:https://leetcode.com

[sample][1]
[1]:https://github.com/haoel/leetcode

[book][2]
[2]:https://github.com/durians/durians/blob/master/Leetcode/CleanCodeHandbook_v1.0.1.pdf