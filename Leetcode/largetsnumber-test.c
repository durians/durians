#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int getnumat(int num, int index)
{
    int a = pow(10,index-1);
    
    if(index == 1 && num < 10) return num;
    
    if(num < a ) return -1;
    
    while(num >= 10*a)
    {
        num = num / 10;
    }
    
    return (num % 10);
}

int cmp(const void *p, const void *q)
{
    int a = *(int *)p;
    int b = *(int *)q;
    int i = 1, c, d,tm,tc,td;
    
    while( (c = getnumat(a,i)) >= 0 && (d = getnumat(b,i)) >= 0)
    {
        if(c != d) return d - c;
        i++;
    }
    
    if( c >= 0)
    {
        d = getnumat(b,i-1);
        tm = getnumat(b,1);
        if(d < tm) d = tm;
        while( (c = getnumat(a, i)) >= 0 && (c == d))
            i++;
        
        if( c < 0)
        {
            //a = 121111, b = 121  d = 1  c = -1 return 2
            //121 > 121111
            //a = 828888, b = 828  d = 8  c = -1 return 9
            //828 < 828888
            i = 1;
            tc = getnumat(a,1);
            td = getnumat(a,2);
            while(tc == td)
            {
                i++;
                tc = td;
                td = getnumat(a,i);
            }
            return td - tc;
        }
        
    }
    else
    {
        c = getnumat(a, i-1);
        tm = getnumat(a,1);
        if(c < tm) c = tm;
        
        while( (d = getnumat(b, i)) >= 0 && (c == d))
            i++;
        
        if( d < 0)
        {
            i = 1;
            tc = getnumat(b,1);
            td = getnumat(b,2);
            while(tc == td)
            {
                i++;
                tc = td;
                td = getnumat(b,i);
            }
            return tc - td;
        }
        
    }
    
    return d - c;
}
char* largestNumber1(int* nums, int numsSize)
{
    int i,iszero = 1;
    char * result = malloc(numsSize*31*sizeof(char));
    memset(result,0, numsSize*5*sizeof(char));
    
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] > 0) iszero = 0;
        sprintf(result+strlen(result),"%d",nums[i]);
    }
    if(iszero){
        result[0] = '0';
        result[1] = '\0';
    }
    
    return result;
}


int main(int argc, char *argv[])
{
    int nums[] = {1,2,3,4,5,6,7,8,9,0};//{828,82888888,121111111,121};
    int numsSize = sizeof(nums)/sizeof(int);
    
    printf("%s\n", largestNumber(nums,numsSize) );
    
    return 0;
}
