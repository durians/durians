/************************************************
File Name: RomanToInteger.c
@ Author: durians 
Created Time: 三  5/13 20:20:21 2015
 ***********************************************/

#include<string.h>
#include<stdio.h>

/*
 https://leetcode.com/problems/roman-to-integer/
 
 Given a roman numeral, convert it to an integer.
 
 Input is guaranteed to be within the range from 1 to 3999.
 
 */

int romanToInt(char* s)
{
    int i , num = 0;;
    
    for(i = strlen(s) - 1; i >= 0; i--)
    {
        switch (s[i])
        {
            case 'I':
                num += ( num >= 5 ? -1 : 1);  // "IV", "IX"
                break;
                
            case 'V': num += 5;  break;
                
            case 'X':
                num += (num >= 50 ? -10 : 10); // XL  XC
                break;
                
            case 'L': num += 50; break;
                
            case 'C':
                num += (num >= 500 ? -100 : 100);  // CD  CM
                break;
                
            case 'D': num += 500; break;
                
            case 'M': num += 1000; break;
                
            default:
                break;
        }
    }
    
    return num;
    
}

int romanToInt1(char* s)
{
    int i , num = 0;;
    
    for(i = strlen(s) - 1; i >= 0; i--)
    {
        switch (s[i])
        {
            case 'I': num += 1;  break;
            case 'V': num += 5;  break;
            case 'X': num += 10; break;
            case 'L': num += 50; break;
            case 'C': num += 100; break;
            case 'D': num += 500; break;
            case 'M': num += 1000; break;
            default:
                break;
        }
        
        if( s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X') )
        {
            num -= 2;
        }
        
        if( s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C') )
        {
            num -= 20;
        }
        
        if( s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M') )
        {
            num -= 200;
        }
    }
    
    return num;

}


//第一次AC所用的方法
int romanToInt2(char* s)
{
    //from I to MMMCMXCIX
    int num = 0, i = 0, j;
    
    char* g[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    char* t[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char* b[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char* q[4] =  {"","M","MM","MMM"};
    
    //1000 place
    while(s[i] && s[i] == 'M')
        i++;
    num += i*1000;
    if(!s[i]) return num;
    
    //100place
    for(j = 9; j > 0; j--)
    {
        if( (s+i) == strstr(s+i,b[j]) )
            break;
    }
    num += j*100;
    i += strlen(b[j]);
    if(!s[i]) return num;
    
    //10place
    for(j = 9; j > 0; j--)
    {
        if( (s+i) == strstr(s+i,t[j]) )
            break;
    }
    num += j*10;
    i += strlen(t[j]);
    if(!s[i]) return num;
    
    //digit place
    for(j = 9; j > 0; j--)
    {
        if( (s+i) == strstr(s+i,g[j]) )
            break;
    }
    num += j;
    i += strlen(g[j]);
    if(!s[i]) return num;
    
    
    return num;
    
}



int main()
{
    printf("%d\n",romanToInt("MMMCMXCIX"));
    return 0;
}







