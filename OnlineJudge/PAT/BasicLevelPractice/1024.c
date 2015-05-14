#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char str[20000] = {0};
    int i, ie,e,j,m;
    
    scanf("%s",str);
    unsigned int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        if(str[i] == 'E') break;
    }
    /*
    if( i >= len){
        printf("%s",str);
        return 0;
    } */
    
    //find E number
    ie = i;
    e = atoi(str+ie+1);
    
    // find .
    for( i = 0; i < len; i++)
        if(str[i] == '.') break;
    
    //[i+1,ie-1] is number ; [i] is . [ie] is E
    if( e > 0)
    {
        j = i + 1;
        for( m = 0; m < e && j < ie; m++,j++)
        {
            str[j-1] = str[j];
        }
        
        for(j = ie - 1; m < e; j++, m++)
        {
            str[j] = '0';
        }
        str[j] = '\0';
        
    }
    else if (e == 0) {
        str[ie] = '\0';
    }
    //number [i+1,ie-1]  to [i+1-e,ie-1-e] && [i+1] = [i-1]to[i-e] && [i+1, i - e] = '0'
    else {
        for(j = ie - 1; j >= i + 1; j--)
        {
            str[j - e] = str[j];
        }
        for(j = i + 1; j < i+1 -e; j++)
        {
            str[j] = '0';
        }
        
        str[i-e] = str[i-1];
        str[i-1] = '0';
        str[ie - e] = '\0';
    }
    
    printf("%s",str);
    
    return 0;
}