/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int hash[1001] = {0};  // 哈希表，下标表示数字，值表示状态
    int* result = (int*)malloc(sizeof(int) * 1001);
    int index = 0;
    
    // 标记 nums1 中出现的数字
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]] = 1;
    }
    
    // 查找 nums2 中出现在 nums1 的数字
    for (int i = 0; i < nums2Size; i++) {
        if (hash[nums2[i]] == 1) {
            result[index++] = nums2[i];
            hash[nums2[i]] = 2;  // 防止重复添加
        }
    }
    
    *returnSize = index;
    return result;
}
