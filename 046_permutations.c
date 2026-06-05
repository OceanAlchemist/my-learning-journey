/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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
        if (used[i]) continue;  // 跳过已使用的元素
        used[i] = 1;
        path[pathSize] = nums[i];
        backtrack(nums, numsSize, used, path, pathSize + 1, res, returnSize, returnColumnSizes);
        used[i] = 0;  // 回溯
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
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
