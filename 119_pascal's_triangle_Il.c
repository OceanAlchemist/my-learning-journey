/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    
    for (int i = 0; i <= rowIndex; i++) {
        row[i] = 0;
    }//是第几行就初始化几个位置
    row[0] = 1;
    
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {//从后往前
            row[j] = row[j] + row[j - 1];
        }
    }//从第一行开始，一直算到目标行列
    
    return row;
}
