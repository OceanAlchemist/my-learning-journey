#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    int min_price = prices[0];
    for (int i = 0; i < pricesSize; i++) {
        int p = prices[i];
        ans = MAX(ans, p - min_price);
        min_price = MIN(min_price, p);
    }
    return ans;
}
