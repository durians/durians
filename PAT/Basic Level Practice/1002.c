#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char num[102] = {0};
    int sum = 0; // max = 9 * 101 = 909
    char *num_str[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    
    scanf("%s",num);
    int i = strlen(num);
    while(i > 0)
    {
        i--;
        sum += num[i] - '0';
    }
    
    if( (sum / 100 ) % 10 ) 
    {
        printf("%s ",num_str[(sum/100) % 10]);
        printf("%s ",num_str[(sum/10) % 10]);
        printf("%s\n",num_str[sum% 10]);
    }
    else if ((sum/10) % 10) {
        printf("%s ",num_str[(sum/10) % 10]);
        printf("%s\n",num_str[sum% 10]);
    }
    else {
        printf("%s\n",num_str[sum% 10]);
    } 
    
    
}