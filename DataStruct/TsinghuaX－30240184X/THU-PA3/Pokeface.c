//http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=391
#include <stdio.h>

int a[1000000+1]; // 0 up, 1 down
int main(int argc, char *argv[]) 
{
    char ch;
    int n, m, k,i, j, c;
    scanf("%d %d", &n, &m);
    
    while(m--)
    {
        while((ch=getchar()) && (ch != 'H' && ch != 'Q'));

        scanf("%d %d", &i, &j);
        
        if(ch == 'H')
        {
            for(k = i; k <= j; k++)
                a[k] = (a[k] + 1)%2;   
        }
        else if (ch == 'Q') 
        {
            c = 0;
            for(k = i; k <= j; k++)
            {
                if(0 == a[k]) c++;
            }
            printf("%d\n",c);
        }
    }
}