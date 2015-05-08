//http://www.patest.cn/contests/mooc-ds2015spring/01-%E5%A4%8D%E6%9D%82%E5%BA%A61

/*
01-复杂度1. 最大子列和问题(20)

给定K个整数组成的序列{ N1, N2, ..., NK }，“连续子列”被定义为{ Ni, Ni+1, ..., Nj }，其中 1 <= i <= j <= K。
“最大子列和”则被定义为所有连续子列元素的和中最大者。
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
现要求你编写程序，计算给定整数序列的最大子列和。

输入格式：

输入第1行给出正整数 K (<= 100000)；第2行给出K个整数，其间以空格分隔。

输出格式：

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。
输入样例：

6
-2 11 -4 13 -5 -2

输出样例：

20
*/

//算法
//1、序列有K个数，依次序列长为1、序列长为2、序列长为3、......
//2、输出最大和

#include <stdio.h>

int table[100000+1];

int calSum(int i, int len)
{
	int sum = table[i];
	
	while(--len)
		sum += table[++i];
		
	return sum;	
}

int main()
{
	int k , i , j, n, sum, maxsum;
	
	while(scanf("%d",&k) != EOF)
	{
		sum = 0;
		maxsum = 0;
		
		for(i = 0; i < k; i++)
		{
			scanf("%d",&table[i]);
		}
		for(i = 1; i <= k; i++)
		{
			sum = table[i-1];
			for(j = i+1; j <= k; j++)
			{
				sum += table[j - 1];
				if(maxsum < sum)
					maxsum = sum;
			}
		}
/*		//我们并不需要用数组sumTable[100000+1][100000+1] 这么大空间 去保留中间和 
		//一个变量就够了 
		for(i = 1; i <= k ; i++)
		{
			sumTable[1][i] = sumTable[1][i - 1] + table[i-1];	
		}
		for(i = 1; i <= k; i++)
		{
			for(j = i; j <= k; j++)
			{
				sumTable[i][j] = sumTable[1][j] - sumTable[1][i] + table[i-1];
				if(maxsum < sumTable[i][j])
					maxsum = sumTable[i][j];
			}
		}	
*/
			
/*      // 暴力法会超时		
		maxsum = table[0] > 0 ? table[0] : 0;	
		for(n = 1; n <= k; n++) // 最大序列长度 
		{
			for(i = 0; i <= k - n; i++)
			{
				sum = calSum(i, n);
				if ( sum > maxsum)
					maxsum = sum;
			}
		}
*/		
		
		printf("%d\n",maxsum);	
	}
	return 0;
}




 

