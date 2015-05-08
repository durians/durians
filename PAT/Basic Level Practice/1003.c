#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    
    int n;
    
    scanf("%d",&n);
    
    while(n--)
    {
        char str[101] = {0};
        
        scanf("%s",str);
        
        int len = strlen(str) , i = 0;
        int cP=0,pP=0,cA=0,pA=0,cT=0,pT=0,otr = 0;
        
        while( i < len )
        {
            if(str[i] == 'P')
            {
                cP++;
                pP = i;
            }
            else if(str[i] == 'A')
            {
                cA++;
                pA = i;
            }
            else if(str[i] == 'T')
            {
                cT++;
                pT = i;    
            }
            else
            {
                otr++;
                break;
            } 
            i++;
        }
        
        if( (otr == 0) && (cP == 1) && (cT == 1) && (cA >= 1) && 
        ( pP < pT) && ( (pP * (pT - pP - 1) == (len - 1 - pT)) ) )
            printf("YES\n");
        else
            printf("NO\n");
    }
}