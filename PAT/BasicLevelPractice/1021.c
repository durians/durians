#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int a[10] = {0}, i;
    char N[1001];
    
    scanf("%s",N);
    
    unsigned int len = strlen(N);
    
    for(i = 0; i < len; i++)
    {
        a[N[i]-'0']++;
    }
    
    for(i = 0; i < 10; i++)
    {
        if(a[i]) printf("%d:%d\n",i,a[i]);
    }
    
    return 0;
}