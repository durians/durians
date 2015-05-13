/************************************************
	> File Name: TwoSum.c
	> Author: durians 
	> Created Time: 日  5/10 22:37:35 2015
 ***********************************************/

/*
 * https://leetcode.com/problems/two-sum/
 *
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 *
 * */

#include<stdio.h>
#include<stdlib.h>

/*
* 
注意：
测试数据numbers中可能有负数，可能有相同的数
numbers={4, 4, 11, 15}, target=8
numbers={5, 4, 7, －5}, target=0
*/


int* twoSum(int* nums, int numsSize, int target) 
{
#define HASH_MAX_SIZE    (1000000)    
#define HASH_KEY(value)  (unsigned int)(value)%HASH_MAX_SIZE    

    int *result = (int *)malloc(2*sizeof(int));
    int hash[HASH_MAX_SIZE] = {0};
    int i, tofind;
    
    for(i = 0; i < numsSize; i++)
    {
        tofind = target - nums[i];
        if( hash[HASH_KEY(tofind)] )
        {
            result[0] = hash[HASH_KEY(tofind)];
            result[1] = i+1;
            return result;           
        }
        else 
        {
            hash[HASH_KEY(nums[i])] = i + 1;
        }
    }
    
    return result;
}

int main()
{
    int nums[] = {2,1,9,4,4,56,90,3}, target = 8;
    int* ret = twoSum(nums, 8, target) ;
    printf("%d %d\n",ret[0], ret[1]);
    
    return 0;
}

