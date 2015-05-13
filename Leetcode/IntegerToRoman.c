/************************************************
File Name: IntegerToRoman.c
@ Author: durians 
Created Time: 三  5/13 19:47:22 2015
 ***********************************************/

/*
 https://leetcode.com/problems/integer-to-roman/
 
 Given an integer, convert it to a roman numeral.
 
 Input is guaranteed to be within the range from 1 to 3999.
 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* intToRoman(int num)
{
    // num : from 1 to 3999
    
    // Roman
    // eg 3999 : MMMCMXCIX
    // digit:       I, II, III, IV, V, VI, VII, VIII, IX
    // ten place :  X XX XXX XL L LX LXX LXXX XC
    // 100 place :  C CC CCC CD D DC DCC DCCC CM
    // 1000 place:  M MM MMM

    char* g[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    char* t[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char* b[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char* q[4] =  {"","M","MM","MMM"};
    
    char *roman = (char *)malloc(10);
    
    strcat(roman,q[num/1000]);
    strcat(roman,b[num/100%10]);
    strcat(roman,t[num%100/10]);
    strcat(roman,g[num%10]);
    
    return roman;
    
}

int main()
{
    printf("%s\n",intToRoman(3999));
    return 0;
}






