/*
 * 198. House Robber
 * 
 * 思路：动态规划
 * 状态转移：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 * 
 * 方法一：使用 dp 数组，空间 O(n) （最直观）
 * 方法二：使用两个变量滚动，空间 O(1) （最优）
 */

// 方法一：常规 DP 数组
int rob_method1(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    
    for (int i = 2; i < numsSize; i++) {
        dp[i] = (dp[i-1] > dp[i-2] + nums[i]) ? dp[i-1] : dp[i-2] + nums[i];
    }
    return dp[numsSize - 1];
}

// 方法二：空间优化版（滚动变量）
int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    int prev2 = nums[0];                  // 相当于 dp[i-2]
    int prev1 = (nums[0] > nums[1]) ? nums[0] : nums[1]; // 相当于 dp[i-1]
    int curr;
    
    for (int i = 2; i < numsSize; i++) {
        curr = (prev1 > prev2 + nums[i]) ? prev1 : prev2 + nums[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
