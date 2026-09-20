/*
 * 070.climbing-stairs
 * 思路：DP，dp[i] = dp[i-1] + dp[i-2]，本质是斐波那契数列
 * 复杂度：Time O(n), Space O(1)
 */
int climbStairs(int n) {
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; ++i) {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}
