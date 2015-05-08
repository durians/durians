//最简单暴力而得分较多的方法，如下：真正解决问题时应采用最快容易出效果的方法。

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100001];
    scanf("%s", str);
    int i, j, k, c = 0;
    unsigned int len = strlen(str);
    
    for( i = 0; i < len; i++)
    {
        if(str[i] == 'P')
        {
            for( j = i + 1; j < len; j++)
            {
                if(str[j] == 'A')
                {
                    for(k = j + 1; k < len; k++)
                    {
                        if(str[k] == 'T')
                        {
                            c = (c + 1) % 1000000007;
                        }
                    }
                }
            }
        }
    }
    printf("%d",c);
    return 0;
}