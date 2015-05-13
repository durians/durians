
// 第一次写大数运算的代码，很糟糕
// 改进：把符号与处理，再进行运算

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int sub(const char *num1, const char *num2, char *out)
{
    int l1 , l2, len;
    int i, j, k, flag = 0,neg = 0;
    char *d1, *d2;
    
    if(num1[0] == '0' && num2[0] == '0')
    {
        out[0] = '0';
        out[1] = '\0';
        return 1;
    }
    
    if(num1[0] )
        l1 = strlen(num1), l2 = strlen(num2);
    if(l1 > l2 || (l1 == l2 && strcmp(num1,num2) >= 0))
    {
        d2 = num1;
        d1 = num2;
    }
    else
    {
        d2 = num2;
        d1 = num1;
        neg = 1;
    }
    
    int len_min = strlen(d1);
    int len_max = strlen(d2);
    int last_j = 0;
    while(len_min > 0)
    {
        int dd1 = d1[len_min - 1] - '0';
        int dd2 = d2[len_max - 1] - '0';
        
        if (last_j) dd2 = dd2 - 1;
        
        last_j = dd2 >= dd1 ? 0 : 1;
        dd2 = dd2 >= dd1 ? dd2 : dd2 + 10;
        out[len_max] = (dd2 - dd1) + '0';
        
        len_max -- ;
        len_min -- ;
    }
    
    while(len_max > 0)
    {
        int dd2 = (d2[len_max -1] - '0');
        if (last_j) dd2 = dd2 - 1;
        
        last_j = dd2 >= 0 ? 0 : 1;
        dd2 = dd2 >= 0 ? dd2 : dd2 + 10;
        
        out[len_max] = dd2 + '0';
        len_max --;
    }
    
    if (last_j)
        out[0] ='1';
    else
        out[0] ='0';
    if(neg)
    {
        for( i = len_max - 1; i >= 0; i--)
            out[i+1] = out[i];
        out[0]='-';
    }
    i = 0;
    while(out[i]=='0') i++;
    j = 0;
    while(out[i])
    {
        out[j++]=out[i++];
    }
    if(j)out[j] = '\0';
    return 1;
}
int add(const char *num1, const char *num2, char *num)
{
    int l1 , l2, len;
    l1 = strlen(num1), l2 = strlen(num2);
    len = l1 > l2 ? l1 + 1: l2 + 1;
    
    int i, j, k, flow = 0;
    for(i = l1-1, j = l2-1, k = len - 1; i >= 0 && j >= 0; i--, j--,k--)
    {
        num[k] = '0' + (num1[i] - '0' + num2[j] - '0' + flow ) % 10;
        flow = (num1[i] - '0' + num2[j] - '0' + flow ) / 10;
    }
    for(;i >= 0; i--,k--)
    {
        num[k] = '0' + (num1[i] - '0' + flow ) % 10;
        flow = (num1[i] - '0' + flow ) / 10;
    }
    for(;j >= 0; j--,k--)
    {
        num[k] = '0' + (num2[j] - '0' + flow ) % 10;
        flow = (num2[j] - '0' + flow ) / 10;
        
    }
    if(flow == 0)
    {
        for(i = 0; i < len - 1; i++)
            num[i] = num[i + 1];
        num[len-1] = '\0';
    }
    else {
        num[0] = flow + '0';
        num[len] = '\0';
    }
    
    
    return 1;
}

void multi(const char *a, const char *b, char *c)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int i, j , k ;
    
    if(a[0] == '0' || b[0] == '0')
    {
        c[0] = '0';
        c[1] = '\0';
        return ;
    }
    
    int *ic = (int *)malloc(sizeof(int)*(len1+len2));
    memset(ic,0,sizeof(int)*(len1+len2));
    
    for(i = len1 - 1; i >= 0; i--)
    {
        if(i == 0 && !isdigit(a[0]) )
            break;
        k = len2 + i;
        for (j = len2 - 1; j >= 0; j--)
        {
            if(j == 0 && !isdigit(b[0]))
                break;
            
            ic[k--] += (a[i] - '0') * (b[j] - '0');
        }
    }
    
    for(i = len1+len2-1; i >= k; i--)
    {
        if(ic[i] >= 10)
        {
            ic[i-1] += ic[i] / 10;
            ic[i] = ic[i] % 10;
        }
    }
    while (ic[k] == 0) {
        k++;
    }
    
    if((a[0] != b[0]) && (a[0] == '-' || b[0] == '-'))
    {
        c[0] = '-';
        i = 1;
    }
    else {
        i = 0;
    }
    
    for(; k < len1 + len2; k++,i++)
    {
        c[i] = ic[k] + '0';
    }
    c[k] = '\0';
    
    if(c[0] == '-' && (c[1] == '0' || c[1] == '\0'))
        c[0] = '0';
    
}
int main()
{
    int i;
    char a[51] = {0}, b[51] = {0};
    char num1[51] = {0}, num2[51] = {0};
    char num_add[52] = {0};
    char num_sub[52] = {0};
    char num_multi[103] = {0};
    
    
    scanf("%s %s",a,b);
    
    //add
    memset(num1, 0, 51),memset(num2, 0, 51);
    strcpy(num1,a),strcpy(num2,b);
    if(isdigit(num1[0]) && num2[0] == '-')
    {
        for(i = 0; i < strlen(num2) - 1; i++)
            num2[i] = num2[i+1];
        num2[i] = '\0';
        sub(num1,num2,num_add);
    }
    else if (num1[0] == '-' && isdigit(num2[0]))
    {
        for(i = 0; i < strlen(num1) - 1; i++)
            num1[i] = num1[i+1];
        num1[i] = '\0';
        sub(num2,num1,num_add);
    }
    else if (num1[0] == '-' && num2[0] == '-') {
        for(i = 0; i < strlen(num1) - 1; i++)
            num1[i] = num1[i+1];
        num1[i] = '\0';
        for(i = 0; i < strlen(num2) - 1; i++)
            num2[i] = num2[i+1];
        num2[i] = '\0';
        
        num_add[0] = '-';
        add(num1,num2,num_add+1);
    }
    else {
        add(num1,num2,num_add);
    }
    
    //sub
    memset(num1, 0, 51),memset(num2, 0, 51);
    strcpy(num1,a),strcpy(num2,b);
    if(isdigit(num1[0]) && num2[0] == '-')
    {
        for(i = 0; i < strlen(num2) - 1; i++)
            num2[i] = num2[i+1];
        num2[i] = '\0';
        add(num1,num2,num_sub);
    }
    else if (num1[0] == '-' && isdigit(num2[0]))
    {
        for(i = 0; i < strlen(num1) - 1; i++)
            num1[i] = num1[i+1];
        num1[i] = '\0';
        num_sub[0] = '-';
        add(num1,num2,num_sub+1);
    }
    else if (num1[0] == '-' && num2[0] == '-') {
        for(i = 0; i < strlen(num1) - 1; i++)
            num1[i] = num1[i+1];
        num1[i] = '\0';
        for(i = 0; i < strlen(num2) - 1; i++)
            num2[i] = num2[i+1];
        num2[i] = '\0';
        sub(num2,num1,num_sub);
    }
    else {
        sub(num1,num2,num_sub);
    }
    
    //multi
    memset(num1, 0, 51),memset(num2, 0, 51);
    strcpy(num1,a),strcpy(num2,b);
    multi(num1,num2,num_multi);
    
    printf("%s\n%s\n%s\n",num_add,num_sub,num_multi);
    
    
    return 0;
}