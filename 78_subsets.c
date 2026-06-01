/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, int** res, int* returnSize, int** returnColumnSizes) {
    // 把当前路径加入结果
    res[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) {
        res[*returnSize][i] = path[i];
    }
    (*returnColumnSizes)[*returnSize] = pathSize;
    (*returnSize)++;
    
    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, res, returnSize, returnColumnSizes);
        // 这里不需要显式移除，因为下一次循环会覆盖 path[pathSize]
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(10000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
    int* path = (int*)malloc(numsSize * sizeof(int));
    
    backtrack(nums, numsSize, 0, path, 0, res, returnSize, returnColumnSizes);
    
    free(path);
    return res;
}
