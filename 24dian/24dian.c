//
//http://www.patest.cn/contests/ds/2-08
//

#include <stdio.h>

/*
 a1 op1 a2 op2 a3 op3 a4
 + - * / 所有的组合
 */
char op[64][4] ={
"+++", "++-", "++*", "++/",   
"+-+", "+--", "+-*", "+-/",   
"+*+", "+*-", "+**", "+*/",   
"+/+", "+/-", "+/*", "+//",  
"-++", "-+-", "-+*", "-+/",   
"--+", "---", "--*", "--/",
"-*+", "-*-", "-**", "-*/",
"-/+", "-/-", "-/*", "-//",    
"*++", "*+-", "*+*", "*+/",    
"*-+", "*--", "*-*", "*-/",   
"**+", "**-", "***", "**/",    
"*/+", "*/-", "*/*", "*//",    
"/++", "/+-", "/+*", "/+/",   
"/-+", "/--", "/-*", "/-/",    
"/*+", "/*-", "/**", "/*/",   
"//+", "//-", "//*", "///",    
};

/*
 a1 op1 a2 op2 a3 op3 a4
 a1 a2 a3 a4 所有的组合
 */
int b[24][4] = {
    
    {0,1,2,3},{0,1,3,2},{0,3,1,2},
    {0,2,3,1},{0,2,1,3},{0,3,2,1},
    
    {1,2,3,0},{1,2,0,3},{1,3,2,0},
    {1,3,0,2},{1,0,2,3},{1,0,3,2},
    
    {2,1,3,0},{2,1,0,3},{2,3,1,0},
    {2,3,0,1},{2,0,1,3},{2,0,3,1},
    
    {3,2,1,0},{3,2,0,1},{3,1,2,0},
    {3,1,0,2},{3,0,2,1},{3,0,1,2}
};

int calc(double a, char op, double b, double *pc)
{
    switch (op) {
        case '+':
            *pc = a + b;
            break;
        case '-':
            *pc = a - b;
            break;
        case '*':
            *pc = a * b;
            break;
        case '/':
            if(b == 0) return 0;
            *pc = a / b;
            break;
        default:
            return 0;
    }
    return 1;
}
/*
 五种不同运算方式如下（括号的五种不同组合）：
  　((a1 op1 a2) op2 a3) op3 a4
 　　(a1 op1 (a2 op2 a3)) op3 a4
 　　(a1 op1 a2) op2 (a3 op3 a4)
 　　a1 op1 ((a2 op2 a3) op3 a4)
 　　a1 op1 (a2 op2 (a3 op3 a4))
 */

int calc24(int a[4])
{
    double a1, a2, a3, a4;
    double r1, r2, r3;
    
    int i, j;
    
    
    for( i = 0; i < 24; i++)
    {
        //4个数有24个组合 b[24][]
        a1 = a[b[i][0]];a2 = a[b[i][1]];
        a3 = a[b[i][2]];a4 = a[b[i][3]];
        
        //运算符有64个排列 op[64][]
        for( j = 0; j < 64; j++)
        {
            // 括号有五种不同组合
            
            //1. ((a1 op1 a2) op2 a3) op3 a4
            if( calc(a1, op[j][0], a2, &r1) &&
                calc(r1, op[j][1], a3, &r2) &&
                calc(r2, op[j][2], a4, &r3) &&
                (24 == r3) )
            {
                printf("((%.0f%c%.0f)%c%.0f)%c%.0f\n",
                       a1,op[j][0],a2,op[j][1],a3,op[j][2],a4);
                return 1;
            }
            
            //2. (a1 op1 (a2 op2 a3)) op3 a4
            if( calc(a2,op[j][1],a3,&r1) &&
                calc(a1,op[j][0],r1,&r2) &&
                calc(r2,op[j][2],a4,&r3) &&
                (24 == r3))
            {
                printf("(%.0f%c(%.0f%c%.0f))%c%.0f\n",
                       a1,op[j][0],a2,op[j][1],a3,op[j][2],a4);
                return 1;
            }
            
            //3. (a1 op1 a2) op2 (a3 op3 a4)
            if( calc(a1,op[j][0],a2,&r1) &&
                calc(a3,op[j][2],a4,&r2) &&
                calc(r1,op[j][1],r2,&r3) &&
                (24 == r3))
            {
                printf("(%.0f%c%.0f)%c(%.0f%c%.0f)\n",
                       a1,op[j][0],a2,op[j][1],a3,op[j][2],a4);
                return 1;
            }
            //4. a1 op1 ((a2 op2 a3) op3 a4)
            if( calc(a2,op[j][1],a3,&r1) &&
                calc(r1,op[j][2],a4,&r2) &&
                calc(a1,op[j][0],r2,&r3) &&
                (24 == r3))
            {
                printf("%.0f%c((%.0f%c%.0f)%c%.0f)\n",
                       a1,op[j][0],a2,op[j][1],a3,op[j][2],a4);
                return 1;
            }
            //5. a1 op1 (a2 op2 (a3 op3 a4))
            if( calc(a3,op[j][2],a4,&r1) &&
                calc(a2,op[j][1],r1,&r2) &&
                calc(a1,op[j][0],r2,&r3) &&
               (24 == r3))
            {
                printf("%.0f%c(%.0f%c(%.0f%c%.0f))\n",
                       a1,op[j][0],a2,op[j][1],a3,op[j][2],a4);
                return 1;
            }
        }
    }
    
    return 0;
}


int main()
{
    int a[4];
    
    scanf("%d %d %d %d", a, a+1, a+2, a+3);
    
    if( !calc24(a) ) printf("-1\n");
    
	return 0;
}


