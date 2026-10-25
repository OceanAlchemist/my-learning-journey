/*
 * 322. Coin Change
 * 
 * 思路：动态规划（完全背包）
 * 状态定义：dp[i] 表示凑成金额 i 所需的最少硬币个数
 * 状态转移：dp[i] = min(dp[i], dp[i - coin] + 1)
 * 
 * 时间复杂度：O(amount * coinsSize) 
 * 空间复杂度：O(amount)
 */
int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) return 0;
    
    // 1. 定义dp数组，大小为 amount + 1
    int dp[amount + 1];
    
    // 2. 初始化
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1; // 设为不可能的最大值
    }
    
    // 3. 开始遍历（这是完全背包的标准写法）
    for (int i = 1; i <= amount; i++) {        // 外层循环：金额
        for (int j = 0; j < coinsSize; j++) {  // 内层循环：硬币
            if (coins[j] <= i) {               // 硬币面值不能大于当前凑的金额
                // 状态转移方程
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }
    
    // 4. 判断是否凑出了目标金额
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}
