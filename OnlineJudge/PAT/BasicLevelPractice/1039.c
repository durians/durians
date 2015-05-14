#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    char ch1[1001],ch2[1001];
    int d[10] = {0},az[26] = {0}, AZ[26] = {0}, i = 0, j = 0, k = 0;
    scanf("%s%s",ch1,ch2);
    
    while(ch1[i])
    {
        if(isdigit(ch1[i]))
            d[ch1[i] - '0']++;
        else if (ch1[i] >= 'a') {
            az[ch1[i] - 'a']++;
        }    
        else {
            AZ[ch1[i] - 'A']++;
        }
        i++;
    }    
    while(ch2[j])
    {
        if(isdigit(ch2[j]))
            d[ch2[j] - '0']--;
        else if (ch2[j] >= 'a') {
            az[ch2[j] - 'a']--;
        }    
        else {
            AZ[ch2[j] - 'A']--;
        }
        j++;
    }
   
    for( i = 0 , j = 0, k = 0; i < 26; i++)
    {
        if(az[i] < 0)j -= az[i];
        else k += az[i];
        
        if(AZ[i] < 0)j -= AZ[i];
        else k += AZ[i];
        
        if(i < 10 && d[i] < 0) j -= d[i];
        else if(i < 10 && d[i] > 0) k += d[i];
        
    }
    
    if( j > 0)
        printf("No %d",j);
    else 
        printf("Yes %d",k);
    
    
    return 0;
}