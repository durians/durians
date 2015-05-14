#include<stdio.h>
#include<ctype.h>

int main()
{
    char in[81] = {0}, ou[81] = {0}, chi,chj;
    int i = 0, j = 0, d[10] = {0} , ch[26] = {0}, space = 0;
    
    scanf("%s%s",in,ou);
    
    while(in[i])
    {
        if(in[i] == ou[j])
        {
            i++;
            j++;
        }
        else 
        {
            if(isdigit(in[i]) && !d[in[i] - '0'])
            {
                d[in[i] - '0'] = 1;
                printf("%c",in[i]);
            }
            else if (isalpha(in[i])) 
            {
                chi = toupper(in[i]);
                if( !ch[chi - 'A'])
                {
                    printf("%c",chi);
                    ch[chi-'A'] = 1;
                }            
            }
            else if( in[i] == '_' && !space)
            {
                printf("_");
                space = 1;
            }
            i++;
        }
    }
    
    return 0;
}