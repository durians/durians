#include<stdio.h>

int main()
{
	int a, n, zero_ploy = 0;
	
	scanf("%d %d",&a,&n);
	if( n == 0)
	{
		zero_ploy = 1;
	}
	else if( n != 0 )
	{
		printf("%d %d",a*n,(n-1));
		zero_ploy = 0;
	} 

	while(scanf("%d %d", &a, &n) != EOF)
	{
		if( n != 0 )	
		{
			printf(" %d %d",a*n,(n-1));
			zero_ploy = 0;
		}
	}
	if( zero_ploy ) printf("0 0");
		
	return 0;
}
