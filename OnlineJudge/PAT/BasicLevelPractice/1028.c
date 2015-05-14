#include <stdio.h>
#include <string.h>

int main()
{
    int n, ef = 0, i;
    scanf("%d",&n);
    
    char max_n[6] = {"new"}, min_n[6] = {"old"};
    char max_t[11] = {"2014/09/07"}, min_t[11] ={"1815/09/05"};
    char name[6],time[11];
    
    for( i = 0; i < n; i++)
    {
        scanf("%s %s", name, time);
        
        if(strcmp(time,"1815/09/05") > 0 && strcmp(time, "2014/09/07") < 0)
        {
            if( strcmp(time, max_t) < 0)
            {
                strcpy(max_t,time);
                strcpy(max_n,name);
            }
            
            else if (strcmp(time, min_t) < 0) {
                strcpy(min_t,time);
                strcpy(max_n,name);
            }
            ef++;
        }
    }
    
    if(ef > 0)
        printf("%d %s %s",ef, max.name, min.name);
    else printf("0");
    return 0;
}