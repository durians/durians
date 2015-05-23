//http://www.patest.cn/contests/mooc-ds/02-%E7%BA%BF%E6%80%A7%E7%BB%93%E6%9E%843
// + + 2 * 3 - 7 4 / 8 4 =  2 + 3 *(7 - 4) + 8/4 = 13.0

/*
+ + 2 * 3 - 7 4 / 8 4
13.0

/ -25 + * - 2 3 4 / 8 4
12.5

/ 5 + * - 2 3 4 / 8 2
ERROR

	
+10.23
10.2

*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int operate(double a, double b, char op, double *va)
{
    switch (op) {
        case '+': *va = a + b; return 1;
        case '-': *va = a - b; return 1;
        case '*': *va = a * b; return 1;
        case '/': if( b == 0) return 0; 
                *va = a / b; return 1;
        default:
            break;
    }
    return 0;
}
int main(int argc, char *argv[]) 
{
    char prefix[32] = {0};
    
    while( gets(prefix) )
    {
        int len = strlen(prefix);
        int i = len;
        double stack[30] = { 0 }, va = 0;
        int top = -1;
        
        while(--i >= 0)
        {
            while( i >= 0 && prefix[i] != ' ')
                i--;
            if( i > 0) // find one space
            {
                if( isdigit(prefix[i+1]) || isdigit(prefix[i+2]))
                {
                    stack[++top] = atof(prefix + i + 1);
                }
                else
                {
                    if(top >= 1 && operate(stack[top],stack[top -1],prefix[i + 1],&va) )
                    {
                        stack[--top] = va;  
                    }
                    else {
                        printf("ERROR\n");
                        break;
                    }
                }
            }
            else  // no space , end!
            {
                if( isdigit(prefix[0]) || isdigit(prefix[1]) ) 
                {
                    if( top == -1)
                    {
                        printf("%.1f\n",atof(prefix));
                    }
                    else
                    {
                        printf("ERROR\n");
                    }
                }
                else  // the first length = 1
                {
                   if(top == 1 && operate(stack[1],stack[0],prefix[0],&va))
                   {
                       printf("%.1f\n",va); 
                   }
                   else 
                   {
                       printf("ERROR\n");
                   }    
                }  
            }    
        }
    }// while (gets)
    
    return 0;    
}