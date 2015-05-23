//http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=403
/*
Input
5 2
1 2 3 5 4


Output
push
pop
push
pop
push
pop
push
push
pop
pop

 1 ≤ n ≤ 1,600,000
 
 0 ≤ m ≤ 1,600,000
 

*/
#include <stdio.h>
#include <stdlib.h>

int a[1600000] = {0};
int b[3200000] = {0};

void slove(int a[], int n, int m)
{
	int *s = (int *)malloc(sizeof(int)*m);
	int top = -1;
	int i, j = 0, k=0;

	for(i = 1; top < m && i <= n; i++)
	{
		//push i
		s[++top] = i;
		b[k++] = 1;

		//pop
		while(top >= 0 && (s[top] == a[j]))
		{
			top--;
			j++;
			b[k++] = 0;
		}
	}

	if(top == -1)
	{
		for(i = 0; i < k; i++)
		{
			if(b[i]) printf("push\n");
			else printf("pop\n");
		}
	}
	else
	{
		printf("No");
	}
    free(s);
}

int main()
{

	int i,n,m;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i)
	{
		scanf("%d",a+i);
	}

	slove(a,n,m);

	return 0;
}