//http://www.patest.cn/contests/mooc-ds2015spring/00-%E8%87%AA%E6%B5%8B5

#include<stdio.h>

int main()
{
	int k, i;
	int a[55] = {0}, ktable[55] = {0};
	int r[55] = {0};
	char ch;
	
	scanf("%d",&k);
	for(i = 1; i <= 54; i++)
	{
		scanf("%d",ktable + i);
		a[i] = i;
	}	
	
	while( k-- )
	{
		for(i = 1; i <= 54; i++)
		{
			r[ktable[i]] = a[i];  
		}
		for(i = 1; i <= 54; i++ )
		{
			a[i] = r[i];
		}
	}
	
	for(i = 1; i <= 54; i++)
	{
		if(a[i] <= 13)
		{
			printf("S%d",a[i]);
		}	
		else if(13 < a[i] && a[i] <= 26 )
		{
			printf("H%d",a[i] - 13);
		}	
		else if( 26 < a[i] && a[i] <= 39)
		{
			printf("C%d",a[i] - 26);
		}	
		else if( 39 < a[i] && a[i] <= 52)
		{
			printf("D%d",a[i] - 39);
		}	
		else
		{
			printf("J%d",a[i] - 52);
		}
		if(i != 54 ) printf(" ");	   
	}

	return 0;
}
