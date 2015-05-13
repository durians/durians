/*
 uthash ：
 */
#include"uthash.h"
struct _hashnode {
    int key ;
    int val ;
    UT_hash_handle hh;
};

int* twoSum(int* nums, int numsSize, int target)
{
    struct _hashnode *hashtable = NULL , *tmp = NULL, *ptr;
    int *result = (int *)malloc(2*sizeof(int));
    int i, tofind;
    
    for(i = 0; i < numsSize; i++)
    {
        tofind = target - nums[i];
        HASH_FIND_INT(hashtable, &tofind, tmp);
        if( tmp )
        {
            result[0] = tmp->val;
            result[1] = i+1;
            break;
        }
        else
        {
            ptr = (struct _hashnode *)malloc(sizeof(struct _hashnode));
            ptr->key =nums[i] ;
            ptr->val =i+1;
            HASH_ADD_INT(hashtable,key,ptr);
        }
    }
    
    HASH_ITER(hh, hashtable, ptr, tmp) {
        HASH_DEL(hashtable,ptr);  /* delete it (users advances to next) */
        free(ptr);            /* free it */
    }
    
    
    return result;
}