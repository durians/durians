#include <stdio.h>

int main(int argc, char *argv[]) 
{
    //B代表“布”、C代表“锤子”、J代表“剪刀”
    int s[3] = {0}, s2[3] = {0};
    char ch1[2] = {0}, ch2[2] = {0};
    int N, i = 0;
    int p = 0;
    scanf("%d",&N);
    
    while(i++ < N)
    {
        scanf("%s %s", ch1, ch2);
        if(ch1[0] == ch2[0])
        {
            p++;
        }
        else
        {
            if( (ch1[0] == 'B' && ch2[0] == 'C') ||
                (ch1[0] == 'C' && ch2[0] == 'J') ||
                (ch1[0] == 'J' && ch2[0] == 'B'))
                {
                    if(ch1[0] == 'B') s[0]++;
                    else if(ch1[0] == 'C') s[1]++;
                    else s[2]++;
                }
                if( (ch2[0] == 'B' && ch1[0] == 'C') ||
                    (ch2[0] == 'C' && ch1[0] == 'J') ||
                    (ch2[0] == 'J' && ch1[0] == 'B'))
                    {
                        if(ch2[0] == 'B') s2[0]++;
                        else if(ch2[0] == 'C') s2[1]++;
                        else s2[2]++;
                    }      
        }
    }
    printf("%d %d %d\n", s[0]+s[1]+s[2] , p , N - (s[0]+s[1]+s[2]) - p);
    printf("%d %d %d\n", N - (s[0]+s[1]+s[2]) - p, p , s[0]+s[1]+s[2]);
    
    if(s[0] >= s[1] && s[0] >= s[2])
        printf("B ");
    else if(s[1] >= s[0] && s[1] >= s[2] )
        printf("C ");
    else
        printf("J ");        
    
    if(s2[0] >= s2[1] && s2[0] >= s2[2])
        printf("B");
    else if(s2[1] >= s2[0] && s2[1] >= s2[2] )
        printf("C");
    else
        printf("J"); 
}