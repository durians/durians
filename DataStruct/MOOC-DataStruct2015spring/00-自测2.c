//http://www.patest.cn/contests/mooc-ds2015spring/00-%E8%87%AA%E6%B5%8B2

//用了半小时，本来10分钟可以解决，一个=好没考虑到，我去
 
#include<stdio.h>
#include<math.h>

int isPrime(int i)
{
	int j;
	
	for(j = 3; j <= sqrt(i) +1 ; j += 2)
		if( i % j == 0)
			return 0;
	
	return 1;
}
int main()
{
	int N, count , i , x;
	
	scanf("%d",&N);
	count = 0;
	
//	for(i = 3; i < N && (i + 2) <= N; i += 2)
//	{
//		if( isPrime(i) && isPrime(i+2))
//			count++;	
//	}
	
	//改进
	for(x = 3,i = 5; i <= N; i += 2)
	{
		if(isPrime(i))
		{
			if( i - x == 2)
				count++;
			x = i;	
		}
	} 
	printf("%d\n",count);
	
	return 0;
}
