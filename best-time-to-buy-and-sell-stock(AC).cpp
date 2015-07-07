class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        int minVal = prices[0];
        int ans = 0;
        int i;
        for (i = 1; i < n; ++i) {
            minVal = min(minVal, prices[i]);
            ans = max(ans, prices[i] - minVal);
        }
        return ans;
    }
};