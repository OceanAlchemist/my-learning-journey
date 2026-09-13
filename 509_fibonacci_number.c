/*
 * 509. Fibonacci Number
 * 思路：DP，dp[i] = dp[i-1] + dp[i-2]
 * 复杂度：Time O(n), Space O(1)
 */
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
