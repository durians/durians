#include<stdio.h>
#include<ctype.h>

int main()
{
    int badkey[256] = {0}, flag = 1, i;
    char ch, str[100001] = {0};
    
    gets(str);
    for(i = 0; (ch = str[i]) != 0; i++)
    {
        badkey[ch] = 1;
        if(isupper(ch)) badkey[ch - 'A' + 'a'] = 1;
    }
    
    if(badkey['+'])
    {
        for(ch = 'A'; ch <= 'Z'; ch++)
        {
            badkey[ch] = 1;
        }
    }
    
    gets(str);
    for(i = 0; (ch = str[i]) != 0; i++)
    {
        if(!badkey[ch]) {
            printf("%c",ch);
            flag = 0;
        }
    }  
    
    if(flag) printf("\n");
    
    return 0;
}
