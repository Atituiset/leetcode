#include <stdlib.h>
#include <stdio.h>
#include "uthash/uthash.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int key;
    int idx;
    UT_hash_handle hh;
} Hash;

int HashFind(Hash ** hash, int key)
{
    Hash *out = NULL;
    HASH_FIND_INT(*hash, &key, out);
    if (out != NULL) {
        return out->idx;
    } 
    return -1;
}

void HashAdd(Hash **hash, int key, int idx) 
{
    Hash *add = malloc(sizeof(Hash) );
    add->key = key;
    add->idx = idx;
    HASH_ADD_INT(*hash, key, add);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Hash *hash = NULL;

    int *result = malloc(sizeof(int) * 2);
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = HashFind(&hash, target - nums[i]);
        if (idx != -1) {
            result[0] = i;
            result[1] = idx;
            *returnSize = 2;
            return result;
        } else {
            HashAdd(&hash, nums[i], i);
        }
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);
    printf("%d, %d\n", result[0], result[1]);
    return 0;
}
