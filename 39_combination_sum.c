/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* candidates, int candidatesSize, int target, int start, 
               int* path, int pathSize, int** res, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        int* cur = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++)
            cur[i] = path[i];
        res[*returnSize] = cur;
        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }
    if (target < 0) return;

    for (int i = start; i < candidatesSize; i++) {
        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], 
                  i, path, pathSize + 1, res, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
                     int* returnSize, int** returnColumnSizes) {
    // OJ 常规预分配，足够容纳答案
    int** res = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(1000 * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, path, 0, res, returnSize, returnColumnSizes);

    free(path);
    return res;
}
