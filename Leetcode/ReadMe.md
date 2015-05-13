**[Word Break][139]**

>越来越觉得C语言不够用了，没有高级语言提供的库、高级数据结构来的方便。


[139]:https://leetcode.com/problems/word-break/


























**[TwoSum][000]**    *hash*

>1.数组直接哈希[AC](TwoSum.c)，考虑到负数，映射为：(unsigned int)(key)%HASH_MAX_SIZE
>
>2.用开源的C语言hash库[uthash.h][hash]（这个在leetcode中默认包含）
>

[000]:https://oj.leetcode.com/problems/two-sum/
[hash]:https://github.com/durians/uthash



**[Integer to Roman][012]**  *dictionary*

> 下面是1-3999对应的罗马字典，照着输出即可[AC](IntegerToRoman.c)
>
    // Roman
    // eg 3999 : MMMCMXCIX
    // digit:       I, II, III, IV, V, VI, VII, VIII, IX
    // ten place :  X XX XXX XL L LX LXX LXXX XC
    // 100 place :  C CC CCC CD D DC DCC DCCC CM
    // 1000 place:  M MM MMM
    
[012]:https://leetcode.com/problemset/algorithms/    





**[Roman to Integer][013]** *同Integer to Roman*

>1.对给的罗马字符串，从Integer to Roman一样到字典中从千位开始匹配,只是这样写代码好像比较丑。
>
    // Roman
    // eg 3999 : MMMCMXCIX
    // digit:       I, II, III, IV, V, VI, VII, VIII, IX
    // ten place :  X XX XXX XL L LX LXX LXXX XC
    // 100 place :  C CC CCC CD D DC DCC DCCC CM
    // 1000 place:  M MM MMM

>2.更好的办法[AC](IntegerToRoman.c)
>	
>扫描一遍字符串, 遇到字符加上对应的数，IV，IX，XL，XC，CD，CM特殊处理
>
	I = 1
	V = 5
	X = 10
	L = 50
	C = 100
	D = 500
	M = 1000

[013]:https://leetcode.com/problems/roman-to-integer/














**[LargestNumber][179]**  *排序*

>1.把输入整数，转成字符串，排序[AC](largestnumber.c)
>
>2.也可以依次取数字的高位进行比较排序，处理起来较麻烦，但，明显有BUG的代码居然也让我了，看来测试数据还不够强...


[179]:https://leetcode.com/problems/largest-number/




















##About leetcode

[leetcode][0]
[0]:https://leetcode.com

[sample][1]
[1]:https://github.com/haoel/leetcode

[book][2]
[2]:https://github.com/durians/durians/blob/master/Leetcode/CleanCodeHandbook_v1.0.1.pdf