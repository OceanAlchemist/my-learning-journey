/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void backtrack(int* nums, int numsSize, int* used, int* path, int pathSize, int** res, int* returnSize, int** returnColumnSizes) {
    if (pathSize == numsSize) {
        res[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            res[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        // 去重：如果当前数字和前一个相同，且前一个没有被使用，说明同一层已经用过了
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        
        used[i] = 1;
        path[pathSize] = nums[i];
        backtrack(nums, numsSize, used, path, pathSize + 1, res, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int** res = (int**)malloc(100000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(100000 * sizeof(int));
    *returnSize = 0;
    int* path = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));
    
    backtrack(nums, numsSize, used, path, 0, res, returnSize, returnColumnSizes);
    
    free(path);
    free(used);
    return res;
}
