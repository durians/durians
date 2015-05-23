/************************************************
    Created Time: 四  5/14 21:00:50 2015
    Author: durianpy@icloud.com 
    File Name: 2.c
************************************************/


#include<stdio.h>

int gcd(int a, int b)
{
	int c = a;

	while(a%b)
	{
		a = b;
		b = c%b;
		c = a;
	}

	return b;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a,b));

	return 0;
}



