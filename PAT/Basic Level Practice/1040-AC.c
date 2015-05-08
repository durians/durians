#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) 
{
    char PAT[100001] = {0};
    
    int pat = 0, t = 0 , at = 0, i;
    scanf("%s",PAT);
    
    for( i = strlen(PAT) - 1; i >= 0; i--)
    {
        if( PAT[i] == 'T')
        {
            t++;
        }    
        else if (PAT[i] == 'A') {
            at = at + t;
        }
        else if (PAT[i] == 'P') {
            pat = ( pat + at) % 1000000007;
        }
    }    
    printf("%d", pat);
    
    return 0;
}