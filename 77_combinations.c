/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int n, int k, int start, int* path, int pathSize, 
               int** res, int* returnSize, int** returnColumnSizes) {
    // 如果当前路径长度等于 k，说明找到了一个有效的组合
    if (pathSize == k) {
        // 为这个组合分配内存，大小为 k
        res[*returnSize] = (int*)malloc(k * sizeof(int));
        // 将当前路径上的元素复制到结果数组中
        for (int i = 0; i < k; i++) {
            res[*returnSize][i] = path[i];
        }
        // 记录这个组合的长度，即 k
        (*returnColumnSizes)[*returnSize] = k;
        // 结果数组的计数器加一
        (*returnSize)++;
        return;
    }

    // 进行剪枝：如果剩余可选的数字不足以填满 k - pathSize 个位置，就可以提前结束循环
    for (int i = start; i <= n - (k - pathSize) + 1; i++) {
        // 将当前选择的数字放入路径
        path[pathSize] = i;
        // 递归地选择下一个数字，起始位置为 i+1
        backtrack(n, k, i + 1, path, pathSize + 1, 
                  res, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    // 估算组合的总数（即 C(n, k)），以此预分配结果数组的空间，这里是简单估算，你可以分配一个足够大的初始空间。
    int maxSize = 200000; // 一个足够大的数，也可以使用组合数公式计算，但为了简化，使用一个经验值，比如 200000。
    int** res = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));
    *returnSize = 0;
    // 分配一个临时数组，用来存储当前的路径
    int* path = (int*)malloc(k * sizeof(int));

    // 从数字 1 开始进行回溯搜索
    backtrack(n, k, 1, path, 0, res, returnSize, returnColumnSizes);

    // 释放临时路径数组的内存，结果数组 res 和 returnColumnSizes 需要由 LeetCode 的调用者释放
    free(path);
    return res;
}
