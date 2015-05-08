//http://www.patest.cn/contests/mooc-ds2015spring/00-%E8%87%AA%E6%B5%8B4

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
	int k , i , num, flow;
	char digits[21] = {0}; 
	char d[22] = {0};
	int a[10] = {0}, b[10] = {0};
	
	scanf("%s",digits);
	k = strlen(digits);
	

	for( i = k , flow = 0; i > 0; i--)
	{
		num = ( digits[i-1] - '0') * 2 + flow;
		d[i] = num % 10 + '0';
		flow =  num / 10;
	}
	if( flow > 0)
	{
		d[0] = flow + '0';
		printf("No\n%s",d);
		return 0;
	}	
	else
	{
		for( i = 0; i < k; i++)
		{
			a[d[i+1] - '0']++;
			b[digits[i] - '0']++;
		}	
		
		for( i = 0; i < 10; i++)
		{
			if( a[i] != b[i])
			{
				printf("No\n%s",d+1);
				return 0;
			}
		}
		
		printf("Yes\n%s",d+1);
		
	}		
	
	return 0;	
}