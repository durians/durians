//http://www.patest.cn/contests/mooc-ds2015spring/00-%E8%87%AA%E6%B5%8B3

//10minute
#include<stdio.h>

int main()
{
	int a[1000], N , M;
	int b[1000] = {0};
	int i, n, j;
	
	scanf("%d %d",&N, &M);
	for(i = 0; i < N; i++)
		scanf("%d",a + i);
	
	for(i = 0; i < N; i++)
	{
		j = (i + M) % N;
		b[j] = a[i];
	}
	
	for(i = 0; i < N; i++)
		printf("%d%c",b[i], (i == N-1) ? '\n' : ' ');
	
		
	return 0;
}
