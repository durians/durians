#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str[81] = {0};
    
    gets(str);
    int len = strlen(str); 
    
    int i;
    for( i = len -1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            str[i] = '\0';
            printf("%s ",&(str[i+1]) );
        }
    }
    printf("%s",str);
    
}