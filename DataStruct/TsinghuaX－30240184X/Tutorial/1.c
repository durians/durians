/************************************************
    Created Time: 四  5/14 20:38:30 2015
    Author: durianpy@icloud.com 
    File Name: 1.c
************************************************/


#include<stdio.h>

int main()
{
	long long a, b, c;

	char ch;

	scanf("%lld %c %lld",&a, &ch, &b);

	switch(ch)
	{
		case '+': 
			c = a + b; break;
		case '-':
			c = a - b; break;
		default:
		   	c  = a * b; break;
	}

	printf("%lld", c);
	
	return 0;
}
