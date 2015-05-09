#include <stdio.h>
#include <string.h>
#include <ctype.h>

//DD 前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四
// MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日
//HH 第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头
//  （于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
//MM 后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟

//
int main(int argc, char *argv[]) 
{
    char str[4][62] = {0};

    int dd = -1, hh = -1, mm, i;
    
    for(i = 0; i < 4; i++)
        scanf("%s",str[i]);
    
    unsigned int len , len2;
    
    len = strlen(str[0]); 
    len2 = strlen(str[1]);
    
    //DD 第1对相同的大写英文字母,A~G = 0~6 
    char *DD[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    for(i = 0; i < len && i < len2; i++)
    {
        if( (str[0][i] == str[1][i]) && 
            (str[0][i] >= 'A') && 
            (str[0][i] <= 'G') )
        {
 
            dd = str[0][i] - 'A';
            break;
        }
    }
    
    //HH 第2对相同的字符,0点到23点由数字0到9、以及大写字母A到N表示
    for(i = i + 1; i < len && i < len2; i++)
    {
        if( str[0][i] == str[1][i] )
        {
            if(isdigit(str[0][i]) ) {
                hh = str[0][i] - '0';
                break;
            }
            else if( (str[0][i] >= 'A') && (str[0][i] <= 'N') ) 
            {
                hh = str[0][i] - 'A' + 10;
                break;
            }
        }
    }
    
    //mm 后面两字符串第1对相同的英文字母出现位置
    len = strlen(str[2]); 
    len2 = strlen(str[3]);
    for(i = 0; i < len && i < len2; i++)
    {
        if( isalpha(str[2][i]) && (str[2][i] == str[3][i]) )
        {
            mm = i;
            break;
        }   
    }
    
    printf("%s %02d:%02d",DD[dd],hh,mm);
    
}