#include <stdio.h>

int a[10000];

int main() 
{
	
	int k, i, j, sum, maxsum, max_i, max_j;	
	scanf("%d", &k);
	
	for( i = 0; i < k; i++)
	{
		scanf("%d",a+i);
	}
	
	max_i = 0;
	max_j = 0;
	maxsum = a[0];
	
	for(i = 0; i < k; i++)
	{
		sum = 0;
		//sum = a[i ~ j]
		for(j = i; j < k; j++)
		{
			sum += a[j];
			if(sum > maxsum)
			{
				maxsum = sum;
				max_i = i;
				max_j = j;
			}
		}
		
	
	}
	
	if(maxsum < 0)
	{
		printf("0 %d %d\n",a[0],a[k-1]);
	}
	else
	{
		printf("%d %d %d",maxsum, a[max_i], a[max_j]);
	}
	
	return 0;
}