/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 从最后一位往前
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            // 情况1：当前位不是9，直接加1返回
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        // 情况2：当前位是9，变成0，继续循环（进位）
        digits[i] = 0;
    }
    
    // 特殊情况：全部都是9，比如 [9,9,9]
    // 需要新数组，长度+1，第一位是1
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }
    *returnSize = digitsSize + 1;
    return result;
}
