/*
 * LeetCode 300. Longest Increasing Subsequence
 * 
 * 方法一：动态规划 O(n^2)
 * 状态定义：dp[i] 表示以 nums[i] 结尾的最长递增子序列长度
 * 状态转移：dp[i] = max(dp[i], dp[j] + 1) (当 nums[j] < nums[i])
 * 
 * 方法二：贪心 + 二分查找 O(n log n)
 * 核心思路：维护一个 tails 数组，记录长度为 i 的递增子序列的最小结尾数字。
 * 遍历数组，用二分查找更新 tails 数组。
 */
方法一：
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int dp[numsSize];
    int maxLen = 1;
    
    // 每个数字自己至少是一个长度为1的子序列
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1; 
    }
    
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }
    
    return maxLen;
}

方法二：
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int tails[numsSize];
    int size = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = size;
        // 二分查找第一个大于等于 nums[i] 的位置
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        tails[left] = nums[i];
        if (left == size) size++;
    }
    return size;
}
