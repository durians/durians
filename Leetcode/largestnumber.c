
int compare(const void *p, const void *q)
{
    char *a = *(char **)p;
    char *b = *(char **)q;
    
    char str1[64] = {0};
    char str2[64] = {0};
    
    strcat(str1,a),strcat(str1,b);
    strcat(str2,b),strcat(str2,a);

    int ret = strcmp(str2,str1);
    
    return ret; 
}
char* largestNumber(int* nums, int numsSize) 
{
    char **numstr; 
    int i, len = 0;
    
    numstr = (char **)malloc(numsSize*sizeof(char*));
    
    for( i = 0; i < numsSize; i++)
    {
        numstr[i] = (char *)malloc(32); 
        memset(numstr[i],0,32);
        sprintf(numstr[i],"%d",nums[i]);
        if(nums[i])
            len += strlen(numstr[i]);  
    }
    qsort(numstr,numsSize,sizeof(char *),compare);
    
    if(len == 0) return "0";
    
    char *result = (char *)malloc(len);
    memset(result,0,len);
    for(i = 0; i < numsSize; i++)
    {
        strcat(result,numstr[i]);
        free(numstr[i]); 
    }
    free(numstr);
    
    return result;
    
}
